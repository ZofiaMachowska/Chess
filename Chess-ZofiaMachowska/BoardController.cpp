#include "BoardController.h"
#include <iostream>

int chessBoard[8][8] = {
   2, 3, 4, 5, 6, 4, 3, 2,
   1, 1, 1, 1, 1, 1, 1, 1,
   0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0,
   -1, -1, -1, -1, -1, -1, -1, -1,
   -2, -3, -4, -5, -6, -4, -3, -2,
};

int temporaryBoard[8][8];

PawnController BoardController::pawn;
KnightController BoardController::knight;
BishopController BoardController::bishop;
RookController BoardController::rook;
QueenController BoardController::queen;
KingController BoardController::king;
PlayerController BoardController::playerController;
int BoardController::movedFigure;
bool BoardController::gameOver;
sf::Vector2i BoardController::oldPosition;


int(&BoardController::getBoard())[8][8]{
    return chessBoard;
}

std::vector<Player*> BoardController::getCurrentPlayers() {
    std::vector<Player*> players = playerController.getPlayers();
    return players;
}

int BoardController::getMovedFigure() {
    return movedFigure;
}

bool BoardController::isGameOver() {
    return gameOver;
}

Player* BoardController::getCurrentPlayer() {
    return playerController.getCurrentPlayer();
}

void BoardController::moveThisPiece(bool whitePlayer, int pieceNumber, sf::Vector2i position) {
    if (whitePlayer && pieceNumber < 0 || !whitePlayer && pieceNumber >0) {
        movedFigure = pieceNumber;
        chessBoard[position.y][position.x] = 0;
    }
}

void BoardController::onBoardClicked(sf::Vector2i pos) {
    if (playerController.isActivePlayerAI()) return;
    if (chessBoard[pos.y][pos.x] == 0 || !isOnBoard(pos.x, pos.y) || gameOver) return;

    bool whitePlayerTurn = playerController.isFirstPlayerTurn();
    int pieceType = chessBoard[pos.y][pos.x];

    if (abs(pieceType) > 0 && abs(pieceType) <= 6) {
        moveThisPiece(whitePlayerTurn, pieceType, pos);
    }

    //wejscie w ten warunek oznacza, ze udalo sie podniesc figure
    if (chessBoard[pos.y][pos.x] == 0) {
        oldPosition.x = pos.x;
        oldPosition.y = pos.y;
    }
}

void BoardController::onBoardReleased(sf::Vector2i pos) {
    if (playerController.isActivePlayerAI()) return;
    if (movedFigure == 0 || gameOver) return;
    bool movePossible = false;
    bool whitePlayerTurn = playerController.isFirstPlayerTurn();

    switch (abs(movedFigure)) {
    case 1:
        movePossible = pawn.isMovePossible(oldPosition, pos, chessBoard, whitePlayerTurn);
        break;
    case 2:
        movePossible = rook.isMovePossible(oldPosition, pos, chessBoard, whitePlayerTurn);
        break;
    case 3:
        movePossible = knight.isMovePossible(oldPosition, pos, chessBoard, whitePlayerTurn);
        break;
    case 4:
        movePossible = bishop.isMovePossible(oldPosition, pos, chessBoard, whitePlayerTurn);
        break;
    case 5:
        movePossible = queen.isMovePossible(oldPosition, pos, chessBoard, whitePlayerTurn);
        break;
    case 6:
        movePossible = king.isMovePossible(oldPosition, pos, chessBoard, whitePlayerTurn);
        break;
    default:
        break;
    }

    if (!movePossible) {
        handleNoValidMoves();
        return;
    }
    prepareTemporaryBoard();
    moveFigureTemporarily(pos, movedFigure);
    if (checkKingSafe(temporaryBoard, whitePlayerTurn)) {
        updateBoardState(pos);
    }
}

void BoardController::prepareTemporaryBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            temporaryBoard[i][j] = chessBoard[i][j];
        }
    }
}

void BoardController::moveFigureTemporarily(sf::Vector2i pos, int piece) {
    temporaryBoard[pos.y][pos.x] = piece;
}

bool BoardController::checkKingSafe(int board[][8], bool whitePlayerTurn) {
    sf::Vector2i currentPlayerKingPosition = king.findKingPosition(board, whitePlayerTurn);
    for (int i = 0; i <= BOARD_LENGTH; i++) {
        for (int j = 0; j <= BOARD_LENGTH; j++) {
            switch (abs(board[i][j])) {
            case 1:
                if (pawn.checkKingCapture(sf::Vector2i(j,i), currentPlayerKingPosition, board, whitePlayerTurn)) {
                    std::cout << "Pionek przeciwnika blokuje" << std::endl;
                    return false;
                };
                break;
            case 2:
                if (rook.checkKingCapture(sf::Vector2i(j, i), currentPlayerKingPosition, board, whitePlayerTurn)) {
                    std::cout << "wieza przeciwnika blokuje" << std::endl;
                    return false;
                };
                break;
            case 3:
                if (knight.checkKingCapture(sf::Vector2i(j, i), currentPlayerKingPosition, board, whitePlayerTurn)) {
                    std::cout << "konik przeciwnika blokuje" << std::endl;
                    return false;
                };
                break;
            case 4:
                if (bishop.checkKingCapture(sf::Vector2i(j, i), currentPlayerKingPosition, board, whitePlayerTurn)) {
                    std::cout << "laufer przeciwnika blokuje" << std::endl;
                    return false;
                };
                break;
            case 5:
                if (queen.checkKingCapture(sf::Vector2i(j, i), currentPlayerKingPosition, board, whitePlayerTurn)) {
                    std::cout << "krolowa przeciwnika blokuje" << std::endl;
                    return false;
                };
                break;
            case 6:
                if (king.checkKingCapture(sf::Vector2i(j, i), currentPlayerKingPosition, board, whitePlayerTurn)) {
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

bool BoardController::checkPossiblePieceMoves(int piece, std::vector<Move> possibleMoves, bool whitePlayerTurn) {
    if (possibleMoves.empty()) {
        return false;
    }
    prepareTemporaryBoard();
    for (const auto& move : possibleMoves) {
        temporaryBoard[move.start.y][move.start.x] = 0;
        moveFigureTemporarily(move.destination, piece);
        if (checkKingSafe(temporaryBoard, whitePlayerTurn)) {
            std::cout << "UDALO SIE ZNALEZC BEZPIECZNY RUCH FIGURY" << piece << std::endl;
            return true;
        }
        prepareTemporaryBoard();
    }
    return false;
}

bool BoardController::isAnyFigureMovePossible(bool whitePlayerTurn) {
    std::vector<Move> possibleMoves;
    int piece;
    for (int i = 0; i <= BOARD_LENGTH; i++) {
        for (int j = 0; j <= BOARD_LENGTH; j++) {
            piece = chessBoard[i][j];
            if (piece > 0 && whitePlayerTurn || piece <  0 && !whitePlayerTurn) {
                continue;
            }
            switch (abs(piece)) {
            case 1:
                possibleMoves = pawn.generateValidMoves(sf::Vector2i(j, i), chessBoard, whitePlayerTurn);
                if (checkPossiblePieceMoves(piece, possibleMoves, whitePlayerTurn)) {
                    return true;
                }
                break;
            case 2:
                possibleMoves = rook.generateValidMoves(sf::Vector2i(j, i), chessBoard, whitePlayerTurn);
                if (checkPossiblePieceMoves(piece, possibleMoves, whitePlayerTurn)) {
                    return true;
                }
                break;
            case 3:
                possibleMoves = knight.generateValidMoves(sf::Vector2i(j, i), chessBoard, whitePlayerTurn);
                if (checkPossiblePieceMoves(piece, possibleMoves, whitePlayerTurn)) {
                    return true;
                }
                break;
            case 4:
                possibleMoves = bishop.generateValidMoves(sf::Vector2i(j, i), chessBoard, whitePlayerTurn);
                if (checkPossiblePieceMoves(piece, possibleMoves, whitePlayerTurn)) {
                    return true;
                }
                break;
            case 5:
                possibleMoves = queen.generateValidMoves(sf::Vector2i(j, i), chessBoard, whitePlayerTurn);
                if (checkPossiblePieceMoves(piece, possibleMoves, whitePlayerTurn)) {
                    return true;
                }
                break;
            default:
                break;
            }
            possibleMoves.clear();
        }
    }
    return false;
}

bool BoardController::isKingMovePossible(bool whitePlayerTurn) {
    std::vector<Move> possibleMoves;
    sf::Vector2i currentPlayerKingPosition = king.findKingPosition(chessBoard, whitePlayerTurn);
    possibleMoves = king.generateValidMoves(currentPlayerKingPosition, chessBoard, whitePlayerTurn);
    int kingPiece = whitePlayerTurn ? -6 : 6;
    return checkPossiblePieceMoves(kingPiece, possibleMoves, whitePlayerTurn);
}

bool BoardController::checkForCheckMate() {
    bool whitePlayerTurn = playerController.isFirstPlayerTurn();
    if (checkKingSafe(chessBoard, whitePlayerTurn)) {
        return false;
    }

    if (isKingMovePossible(whitePlayerTurn)) {
        return false;
    }

    if (isAnyFigureMovePossible(whitePlayerTurn)) {
        return false;
    }
    return true;
}

void BoardController::setGameOver() {
    gameOver = true;
    std::cout << "Zakonczona gra" << std::endl;
}

void BoardController::aiUpdateBoardState(int aiMovedFigure, sf::Vector2i oldPos, sf::Vector2i newPos) {
    movedFigure = aiMovedFigure;
    chessBoard[oldPos.y][oldPos.x] = 0;
    updateBoardState(newPos);
}

void BoardController::updateBoardState(sf::Vector2i pos) {
    int figureOnOldPosition = chessBoard[oldPosition.y][oldPosition.x];
    std::cout << "Ruch sie udal, kolej nastepnego gracza" << std::endl;
    chessBoard[pos.y][pos.x] = movedFigure;
    playerController.switchPlayer(chessBoard);
    if (checkForCheckMate()) {
        setGameOver();
    }
    movedFigure = 0;
}

void BoardController::handleNoValidMoves() {
    chessBoard[oldPosition.y][oldPosition.x] = movedFigure;
    std::cout << "Ruch sie nie udal, odlozenie figury" << std::endl;
    movedFigure = 0;
}

void BoardController::resetBoard() {
   std::cout << "Tablica ustawiona na stan poczatkowy" << std::endl;
   int initialChessBoard[8][8] = {
   2, 3, 4, 5, 6, 4, 3, 2,
   1, 1, 1, 1, 1, 1, 1, 1,
   0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0,
   -1, -1, -1, -1, -1, -1, -1, -1,
   -2, -3, -4, -5, -6, -4, -3, -2,
   };
   for (int i = 0; i < 8; i++) {
       for (int j = 0; j < 8; j++) {
           chessBoard[i][j] = initialChessBoard[i][j];
       }
   }
}

void BoardController::startNewGame(Options aiOptionsChoice) {
    gameOver = false;
    resetBoard();
    playerController.setPlayersAiFromOptions(aiOptionsChoice);
    playerController.resetFirstPlayer();
    playerController.startTimer();
    playerController.shouldRunAI(getBoard());
}

void BoardController::loadGame(Game gameToLoad) {
    gameOver = gameToLoad.gameOver;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chessBoard[i][j] = gameToLoad.board[i][j];
        }
    }
   playerController.setLoadedPlayers(gameToLoad);
   playerController.shouldRunAI(getBoard());
}
