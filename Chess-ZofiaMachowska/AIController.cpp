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
        std::cout << "callback do updateBoardState" << std::endl;
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

std::vector<Move> AIController::generatePossibleMoves(int board[][8]) {
    std::vector<Move> possibleMoves;

    // Przeszukaj wszystkie pola na szachownicy
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            int piece = board[row][col];

            if (piece == 0) {
                // Puste pole na szachownicy - przejdŸ do nastêpnego pola
                continue;
            }

            // Wygeneruj mo¿liwe ruchy dla danej figury na tym polu
            std::vector<Move> validMoves = generateValidMovesForPiece(piece, sf::Vector2i(col, row), board);

            // Dodaj wygenerowane ruchy do listy mo¿liwych ruchów
            for (const auto& move : validMoves) {
                possibleMoves.push_back(move);
            }
        }
    }

    return possibleMoves;
}

void AIController::make_move(const sf::Vector2i& from, const sf::Vector2i& to, int board[][8]) {
    // Pobieramy figurê, któr¹ chcemy przesun¹æ
    int piece = board[from.y][from.x];

    // Przenosimy figurê na now¹ pozycjê
    board[to.y][to.x] = piece;

    // Ustawiamy pole z którego przesunêliœmy figurê jako puste
    board[from.y][from.x] = 0;
}

void AIController::unmake_move(const sf::Vector2i& from, const sf::Vector2i& to, int board[][8]) {
    // Pobieramy figurê, która zosta³a przesuniêta na pole 'to'
    int piece = board[to.y][to.x];

    // Przenosimy figurê z powrotem na pole 'from'
    board[from.y][from.x] = piece;

    // Ustawiamy pole 'to' jako puste
    board[to.y][to.x] = 0;
}


int AIController::positionQuality(int board[][8]) {

    int score = 0;

    int pawnValue = 1;
    int knightValue = 3;
    int bishopValue = 3;
    int rookValue = 5;
    int queenValue = 9;

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
                // Puste pole na szachownicy
                continue;
            }

            // Ocena za poszczególne figury
            if (piece == 1 || piece == -1) {
                score += pawnValue;
            }
            else if (piece == 2 || piece == -2) {
                score += rookValue;
            }
            else if (piece == 3 || piece == -3) {
                score += knightValue;
            }
            else if (piece == 4 || piece == -4) {
                score += bishopValue;
            }
            else if (piece == 5 || piece == -5) {
                score += queenValue;
            }

            // Dodaj wartoœæ pozycyjn¹ pola na szachownicy
            if (piece > 0) {
                score += positionValues[row][col];
            }
            else {
                // Odbicie pozycji dla pól czarnych
                score += positionValues[7 - row][col];
            }
        }
    }

    // Wypisz wynik oceny
    std::cout << "Ocena pozycji: " << score << std::endl;
    return score;
}

MoveEvaluation AIController::minimMaxAlphaBeta(int depth, int alpha, int beta, bool maximizingPlayer, int board[][8]) {
    // Tutaj wywo³ujemy funkcjê generatePossibleMoves, aby uzyskaæ listê mo¿liwych ruchów
    std::vector<Move> possibleMoves = generatePossibleMoves(board);

    if (depth == 0 || possibleMoves.empty()) {
        // Docieramy do koñca drzewa lub nie ma ju¿ mo¿liwych ruchów, wiêc zwracamy ocenê pozycji
        int evaluation = positionQuality(board);
        return MoveEvaluation{ Move{sf::Vector2i(-1, -1), sf::Vector2i(-1, -1), 0}, evaluation };
    }

    if (maximizingPlayer) {
        int maxEval = INT_MIN;
        MoveEvaluation bestMoveEval;
        for (const auto& move : possibleMoves) {
            // Symulujemy ruch na planszy
            make_move(move.start, move.destination, board);

            // Rekurencyjnie wywo³ujemy minimax dla kolejnej warstwy drzewa
            MoveEvaluation eval = minimMaxAlphaBeta(depth - 1, alpha, beta, false, board);
            int evalScore = eval.evaluation;
            if (evalScore > maxEval && move.pieceType != 0 && checkKingSafe(move.pieceType, board)) {
                maxEval = evalScore;
                bestMoveEval = eval;
                bestMoveEval.move = move;
            }
            alpha = std::max(alpha, evalScore);

            // Odbieramy symulowany ruch
            unmake_move(move.start, move.destination, board);

            // Ciêcie Alfa-Beta
            if (beta <= alpha)
                break;
        }

        return bestMoveEval;
    }
    else {
        int minEval = INT_MAX;
        MoveEvaluation bestMoveEval;
        for (const auto& move : possibleMoves) {
            // Symulujemy ruch na planszy
            make_move(move.start, move.destination, board);

            // Rekurencyjnie wywo³ujemy minimax dla kolejnej warstwy drzewa
            MoveEvaluation eval = minimMaxAlphaBeta(depth - 1, alpha, beta, true, board);
            int evalScore = eval.evaluation;
            if (evalScore < minEval && move.pieceType != 0 && checkKingSafe(move.pieceType, board)) {
                minEval = evalScore;
                bestMoveEval = eval;
                bestMoveEval.move = move;
            }
            beta = std::min(beta, evalScore);

            // Odbieramy symulowany ruch
            unmake_move(move.start, move.destination, board);

            // Ciêcie Alfa-Beta
            if (beta <= alpha)
                break;
        }

        return bestMoveEval;
    }
}

void AIController::makeAMove() {
    movePieceCallback();
}

void AIController::calculateBestMove(int board[][8]) {
    int alpha = INT_MIN;
    int beta = INT_MAX;
    int depth = 3;
    bool maximizingPlayer = true;
    int boardCopy[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            boardCopy[i][j] = board[i][j];
        }
    }
    bestMoveEvaluation = minimMaxAlphaBeta(depth, alpha, beta, maximizingPlayer, boardCopy);
    bestMove = bestMoveEvaluation.move;
    makeAMove();
}