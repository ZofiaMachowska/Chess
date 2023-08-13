#include "AIController.h"
#include "BoardController.h"

PawnController AIController::pawn;
KnightController AIController::knight;
BishopController AIController::bishop;
RookController AIController::rook;
QueenController AIController::queen;
KingController AIController::king;
int boardCopy[8][8];

void  AIController::setMovePieceCallback(std::function<void()> callback) {
    movePieceCallback = std::move(callback);
}

AIController::AIController() {
    setMovePieceCallback([this]() {
        BoardController::aiUpdateBoardState(bestMove.pieceType, bestMove.start, bestMove.destination);
        });
}

AIController::~AIController() {
}

std::vector<Move> AIController::generateValidMovesForPiece(int piece, sf::Vector2i position) {
    std::vector<Move> validMoves;
    switch (abs(piece)) {
    case 1: 
        validMoves = pawn.generateValidMoves(position, boardCopy, piece <0);
        break;
    case 2: 
        validMoves = rook.generateValidMoves(position, boardCopy, piece < 0);
        break;
    case 3: 
        validMoves = knight.generateValidMoves(position, boardCopy, piece < 0);
        break;
    case 4: 
        validMoves = bishop.generateValidMoves(position, boardCopy, piece < 0);
        break;
    case 5: 
        validMoves = queen.generateValidMoves(position, boardCopy, piece < 0);
        break;
    case 6: 
        validMoves = king.generateValidMoves(position, boardCopy, piece < 0);
        break;
    default:
        break;
    }
    std::vector<Move> validMovesCopy;
    for (const auto& move : validMoves) {
        makeMove(move.start, move.destination);
        if (BoardController::checkKingSafe(boardCopy, piece < 0)) {
            validMovesCopy.push_back(move);
        }
        unmakeMove(move.start, move.destination);
    }
    return validMovesCopy;
}

std::vector<Move> AIController::generatePossibleMoves(bool maximizingPlayer) {
    std::vector<Move> possibleMoves;

    for (int row = 0; row <= BOARD_LENGTH; row++) {
        for (int col = 0; col <= BOARD_LENGTH; col++) {
            int piece = boardCopy[row][col];

            if (piece == 0 || (piece > 0 && !maximizingPlayer) || (piece < 0 && maximizingPlayer)) {
                continue;
            }

            std::vector<Move> validMoves = generateValidMovesForPiece(piece, sf::Vector2i(col, row));

            for (const auto& move : validMoves) {
                possibleMoves.push_back(move);

            }
        }
    }
    return possibleMoves;
}

void AIController::makeMove(const sf::Vector2i& oldPosition, const sf::Vector2i& newPosition) {
    int piece = boardCopy[oldPosition.y][oldPosition.x];
    boardCopy[newPosition.y][newPosition.x] = piece;
    boardCopy[oldPosition.y][oldPosition.x] = 0;
}

void AIController::unmakeMove(const sf::Vector2i& oldPosition, const sf::Vector2i& newPosition) {
    int piece = boardCopy[newPosition.y][newPosition.x];
    boardCopy[oldPosition.y][oldPosition.x] = piece;
    boardCopy[newPosition.y][newPosition.x] = 0;
}

int AIController::positionQuality() {
    int score = 0;
    for (int row = 0; row <= BOARD_LENGTH; row++) {
        for (int col = 0; col <= BOARD_LENGTH; col++) {
            int piece = boardCopy[row][col];
            if (piece == 0) {
                continue;
            }

            if (piece == pawn.BLACK_PAWN || piece == pawn.WHITE_PAWN) {
                score += pawn.VALUE;
            }
            else if (piece == rook.BLACK_ROOK || piece == rook.WHITE_ROOK) {
                score += rook.VALUE;
            }
            else if (piece == knight.BLACK_KNIGHT || piece == knight.WHITE_KNIGHT) {
                score += knight.VALUE;
            }
            else if (piece == bishop.BLACK_BISHOP || piece == bishop.WHITE_BISHOP) {
                score += bishop.VALUE;
            }
            else if (piece == queen.BLACK_QUEEN || piece == queen.WHITE_QUEEN) {
                score += queen.VALUE;
            }
            if (piece > 0) {
                score += POSITION_VALUES[row][col];
            }
            else {
                score += POSITION_VALUES[7 - row][col];
            }
        }
    }
    return score;
}

MoveEvaluation AIController::minimMaxAlphaBeta(int depth, int alpha, int beta, bool maximizingPlayer) {
    std::vector<Move> possibleMoves = generatePossibleMoves(maximizingPlayer);

    if (depth == 0 || possibleMoves.empty()) {
        int evaluation = positionQuality();
        return MoveEvaluation{ Move{sf::Vector2i(-1, -1), sf::Vector2i(-1, -1), 0}, evaluation };
    }

    if (maximizingPlayer) {
        int maxEval = INT_MIN;
        MoveEvaluation bestMoveEval;
        for (const auto& move : possibleMoves) {
            makeMove(move.start, move.destination);

            MoveEvaluation eval = minimMaxAlphaBeta(depth - 1, alpha, beta, false);
            int evalScore = eval.evaluation;
            if (evalScore > maxEval && move.pieceType != 0 && move.pieceType >0) {
                maxEval = evalScore;
                bestMoveEval = eval;
                bestMoveEval.move = move;
            }
            alpha = std::max(alpha, evalScore);

            unmakeMove(move.start, move.destination);
            if (beta <= alpha)
                break;
        }

        return bestMoveEval;
    }
    else {
        int minEval = INT_MAX;
        MoveEvaluation bestMoveEval;
        for (const auto& move : possibleMoves) {
            makeMove(move.start, move.destination);
            MoveEvaluation eval = minimMaxAlphaBeta(depth - 1, alpha, beta, true);
            int evalScore = eval.evaluation;
            if (evalScore < minEval && move.pieceType != 0 && move.pieceType < 0) {
                minEval = evalScore;
                bestMoveEval = eval;
                bestMoveEval.move = move;
            }
            beta = std::min(beta, evalScore);

            unmakeMove(move.start, move.destination);

            if (beta <= alpha)
                break;
        }
        return bestMoveEval;
    }
}

void AIController::makePlayerMove() {
    if (movePieceCallback) {
        movePieceCallback();
    }
}

void AIController::calculateBestMove(int board[][8], bool isWhitePlayer) {
    int alpha = INT_MIN;
    int beta = INT_MAX;
    int depth = 3;
    bool maximizingPlayer = !isWhitePlayer;
    for (int i = 0; i <= BOARD_LENGTH; i++) {
        for (int j = 0; j <= BOARD_LENGTH; j++) {
            boardCopy[i][j] = board[i][j];
        }
    }
    bestMoveEvaluation = minimMaxAlphaBeta(depth, alpha, beta, maximizingPlayer);
    bestMove = bestMoveEvaluation.move;

    if (bestMove.start == sf::Vector2i(-1, -1) && bestMove.destination == sf::Vector2i(-1, -1)) {
        BoardController::setGameOver();
        return; 
    }
    makePlayerMove();
}