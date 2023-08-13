#include "AIController.h"
#include "BoardController.h"

PawnController AIController::pawn;
KnightController AIController::knight;
BishopController AIController::bishop;
RookController AIController::rook;
QueenController AIController::queen;
KingController AIController::king;

void  AIController::setMovePieceCallback(std::function<void()> callback) {
    movePieceCallback = std::move(callback);
}

AIController::AIController()
{
    setMovePieceCallback([this]() {
        BoardController::aiUpdateBoardState(bestMove.pieceType, bestMove.start, bestMove.destination);
        });
}

std::vector<Move> AIController::generateValidMovesForPiece(int piece, sf::Vector2i position, int board[][8]) {
    std::vector<Move> validMoves;
    switch (abs(piece)) {
    case 1: 
        validMoves = pawn.generateValidMoves(position, board, piece <0);
        break;
    case 2: 
        validMoves = rook.generateValidMoves(position, board, piece < 0);
        break;
    case 3: 
        validMoves = knight.generateValidMoves(position, board, piece < 0);
        break;
    case 4: 
        validMoves = bishop.generateValidMoves(position, board, piece < 0);
        break;
    case 5: 
        validMoves = queen.generateValidMoves(position, board, piece < 0);
        break;
    case 6: 
        validMoves = king.generateValidMoves(position, board, piece < 0);
        break;
    default:
        break;
    }
    return validMoves;
}

bool AIController::checkKingSafe(int pieceType, int board[][8]) {

    sf::Vector2i currentPlayerKingPosition = king.findKingPosition(board, pieceType<0);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            switch (abs(board[i][j])) {
            case 1:
                if (pawn.checkKingCapture(sf::Vector2i(j, i), currentPlayerKingPosition, board, pieceType < 0)) {
                    std::cout << "Pionek przeciwnika blokuje" << std::endl;
                    return false;
                };
                break;
            case 2:
                if (rook.checkKingCapture(sf::Vector2i(j, i), currentPlayerKingPosition, board, pieceType < 0)) {
                    std::cout << "wieza przeciwnika blokuje" << std::endl;
                    return false;
                };
                break;
            case 3:
                if (knight.checkKingCapture(sf::Vector2i(j, i), currentPlayerKingPosition, board, pieceType < 0)) {
                    std::cout << "konik przeciwnika blokuje" << std::endl;
                    return false;
                };
                break;
            case 4:
                if (bishop.checkKingCapture(sf::Vector2i(j, i), currentPlayerKingPosition, board, pieceType < 0)) {
                    std::cout << "laufer przeciwnika blokuje" << std::endl;
                    return false;
                };
                break;
            case 5:
                if (queen.checkKingCapture(sf::Vector2i(j, i), currentPlayerKingPosition, board, pieceType < 0)) {
                    std::cout << "krolowa przeciwnika blokuje" << std::endl;
                    return false;
                };
                break;
            case 6:
                if (king.checkKingCapture(sf::Vector2i(j, i), currentPlayerKingPosition, board, pieceType < 0)) {
                    std::cout << "krol przeciwnika blokuje" << std::endl;
                    return false;
                };
                break;
            default:
                break;
            }

        }
    }
    return true;
}

std::vector<Move> AIController::generatePossibleMoves(int board[][8], bool maximizingPlayer) {
    std::vector<Move> possibleMoves;

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            int piece = board[row][col];

            if (piece == 0 && ((piece < 0 && !maximizingPlayer) || (piece > 0 && maximizingPlayer))) {
                continue;
            }

            std::vector<Move> validMoves = generateValidMovesForPiece(piece, sf::Vector2i(col, row), board);

            for (const auto& move : validMoves) {
                possibleMoves.push_back(move);

            }
        }
    }
    return possibleMoves;
}

void AIController::makeMove(const sf::Vector2i& oldPosition, const sf::Vector2i& newPosition, int board[][8]) {
    int piece = board[oldPosition.y][oldPosition.x];
    board[newPosition.y][newPosition.x] = piece;
    board[oldPosition.y][oldPosition.x] = 0;
}

void AIController::unmakeMove(const sf::Vector2i& oldPosition, const sf::Vector2i& newPosition, int board[][8]) {
    int piece = board[newPosition.y][newPosition.x];
    board[oldPosition.y][oldPosition.x] = piece;
    board[newPosition.y][newPosition.x] = 0;
}

int AIController::positionQuality(int board[][8]) {
    int score = 0;
    int positionValues[8][8] = {
     { 4,  3,  2,  1,  1,  2,  3,  4},
     { 3,  2,  1,  0,  0,  1,  2,  3},
     { 2,  1,  0, -1, -1,  0,  1,  2},
     { 1,  0, -1, -2, -2, -1,  0,  1},
     { 1,  0, -1, -2, -2, -1,  0,  1},
     { 2,  1,  0, -1, -1,  0,  1,  2},
     { 3,  2,  1,  0,  0,  1,  2,  3},
     { 4,  3,  2,  1,  1,  2,  3,  4},
    };

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            int piece = board[row][col];
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
                score += positionValues[row][col];
            }
            else {
                score += positionValues[7 - row][col];
            }
        }
    }
    return score;
}

MoveEvaluation AIController::minimMaxAlphaBeta(int depth, int alpha, int beta, bool maximizingPlayer, int board[][8]) {
    std::vector<Move> possibleMoves = generatePossibleMoves(board, maximizingPlayer);

    if (depth == 0 || possibleMoves.empty()) {
        int evaluation = positionQuality(board);
        return MoveEvaluation{ Move{sf::Vector2i(-1, -1), sf::Vector2i(-1, -1), 0}, evaluation };
    }

    if (maximizingPlayer) {
        int maxEval = INT_MIN;
        MoveEvaluation bestMoveEval;
        for (const auto& move : possibleMoves) {
            makeMove(move.start, move.destination, board);

            MoveEvaluation eval = minimMaxAlphaBeta(depth - 1, alpha, beta, false, board);
            int evalScore = eval.evaluation;
            if (evalScore > maxEval && move.pieceType != 0 && move.pieceType >0) {
                maxEval = evalScore;
                bestMoveEval = eval;
                bestMoveEval.move = move;
            }
            alpha = std::max(alpha, evalScore);

            unmakeMove(move.start, move.destination, board);
            if (beta <= alpha)
                break;
        }

        return bestMoveEval;
    }
    else {
        int minEval = INT_MAX;
        MoveEvaluation bestMoveEval;
        for (const auto& move : possibleMoves) {
            makeMove(move.start, move.destination, board);
            MoveEvaluation eval = minimMaxAlphaBeta(depth - 1, alpha, beta, true, board);
            int evalScore = eval.evaluation;
            if (evalScore < minEval && move.pieceType != 0 && move.pieceType < 0) {
                minEval = evalScore;
                bestMoveEval = eval;
                bestMoveEval.move = move;
            }
            beta = std::min(beta, evalScore);

            unmakeMove(move.start, move.destination, board);

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
    int boardCopy[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            boardCopy[i][j] = board[i][j];
        }
    }
    bestMoveEvaluation = minimMaxAlphaBeta(depth, alpha, beta, maximizingPlayer, boardCopy);
    bestMove = bestMoveEvaluation.move;
    makePlayerMove();
}