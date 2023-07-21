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

PawnController BoardController::pawn;
KnightController BoardController::knight;
BishopController BoardController::bishop;
RookController BoardController::rook;
QueenController BoardController::queen;
KingController BoardController::king;
GameController BoardController::gameController;

BoardController::BoardController() {
}

int(&BoardController::getBoard())[8][8]{
    return chessBoard;
}

int BoardController::getMovedFigure() {
    return movedFigure;
}

Player* BoardController::getCurrentPlayer() {
    return gameController.getCurrentPlayer();
}

void BoardController::moveThisPiece(int pieceNumber, sf::Vector2i position) {
    movedFigure = pieceNumber;
    chessBoard[position.y][position.x] = 0;
}

void BoardController::moveBlackPiece(sf::Vector2i position) {
    switch (chessBoard[position.y][position.x]) {
    case 1:
        moveThisPiece(1,  position);
        break;
    case 2:
        moveThisPiece(2,  position);
        break;
    case 3:
        moveThisPiece(3, position);
        break;
    case 4:
        moveThisPiece(4, position);
        break;
    case 5:
        moveThisPiece(5, position);
        break;
    case 6:
        moveThisPiece(6, position);
        break;
    default:
        break;
    }
}

void BoardController::moveWhitePiece(sf::Vector2i position) {
    switch (chessBoard[position.y][position.x]) {
    case -1:
        moveThisPiece(-1, position);
        break;
    case -2:
        moveThisPiece(-2, position);
        break;
    case -3:
        moveThisPiece(-3, position);
        break;
    case -4:
        moveThisPiece(-4, position);
        break;
    case -5:
        moveThisPiece(-5, position);
        break;
    case -6:
        moveThisPiece(-6, position);
        break;
    default:
        break;
    }
}

void BoardController::onBoardClicked(sf::Vector2i pos) {
    if (chessBoard[pos.y][pos.x] == 0) return;

    sf::Vector2i boardPosition(pos.x, pos.y);
    bool whitePlayerTurn = gameController.isFirstPlayerTurn();

    if (whitePlayerTurn) moveWhitePiece(boardPosition);
    else moveBlackPiece(boardPosition);

    //wejscie w ten warunek oznacza, ze udalo sie podniesc figure
    if (chessBoard[pos.y][pos.x] == 0) {
        oldPosition.x = pos.x;
        oldPosition.y = pos.y;
    }
}

void BoardController::onBoardReleased(sf::Vector2i pos) {

    if (movedFigure == 0) return;
    bool movePossible = false;
    bool kingSafe = false;
    bool whitePlayerTurn = gameController.isFirstPlayerTurn();

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

    //sprawdzenie czy ten ruch nie sprawi ze krol gracza bedzie zagrozony
    kingSafe = checkKingSafe(pos, whitePlayerTurn);
    checkPlayerMoveValidity(pos, kingSafe, movePossible);
}

bool BoardController::checkKingSafe(sf::Vector2i pos, bool whitePlayerTurn) {
    int temporaryBoard[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            temporaryBoard[i][j] = chessBoard[i][j];
        }
    }
    temporaryBoard[pos.y][pos.x] = movedFigure;

    sf::Vector2i currentPlayerKingPosition = king.findKingPosition(temporaryBoard, whitePlayerTurn);

    for (int i = 0; i <= BOARD_LENGTH; i++) {
        for (int j = 0; j <= BOARD_LENGTH; j++) {
            switch (abs(temporaryBoard[i][j])) {
            case 1:
                if (pawn.checkKingCapture(sf::Vector2i(j,i), currentPlayerKingPosition, temporaryBoard, whitePlayerTurn)) {
                    std::cout << "Pionek przeciwnika blokuje" << std::endl;
                    return false;
                };
                break;
            case 2:
                if (rook.checkKingCapture(sf::Vector2i(j, i), currentPlayerKingPosition, temporaryBoard, whitePlayerTurn)) {
                    std::cout << "wieza przeciwnika blokuje" << std::endl;
                    return false;
                };
                break;
            case 3:
                if (knight.checkKingCapture(sf::Vector2i(j, i), currentPlayerKingPosition, temporaryBoard, whitePlayerTurn)) {
                    std::cout << "konik przeciwnika blokuje" << std::endl;
                    return false;
                };
                break;
            case 4:
                if (bishop.checkKingCapture(sf::Vector2i(j, i), currentPlayerKingPosition, temporaryBoard, whitePlayerTurn)) {
                    std::cout << "laufer przeciwnika blokuje" << std::endl;
                    return false;
                };
                break;
            case 5:
                if (queen.checkKingCapture(sf::Vector2i(j, i), currentPlayerKingPosition, temporaryBoard, whitePlayerTurn)) {
                    std::cout << "krolowa przeciwnika blokuje" << std::endl;
                    return false;
                };
                break;
            case 6:
                if (king.checkKingCapture(sf::Vector2i(j, i), currentPlayerKingPosition, temporaryBoard, whitePlayerTurn)) {
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

void BoardController::updateBoardState(sf::Vector2i pos) {
    int figureOnOldPosition = chessBoard[oldPosition.y][oldPosition.x];
    std::cout << "Ruch sie udal, kolej nastepnego gracza" << std::endl;
    chessBoard[pos.y][pos.x] = movedFigure;
    gameController.switchPlayer();
}

void BoardController::handleNoValidMoves() {
    chessBoard[oldPosition.y][oldPosition.x] = movedFigure;
    std::cout << "Ruch sie nie udal, odlozenie figury" << std::endl;
}

void BoardController::checkPlayerMoveValidity(sf::Vector2i pos, bool kingSafe, bool movePossible) {
    std::cout << "bezpieczenstwo krola: " << kingSafe << std::endl;
    std::cout << "czy mozliwy ruch: " << movePossible << std::endl;

    (movePossible && kingSafe) ? updateBoardState(pos) : handleNoValidMoves();

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

void BoardController::startNewGame() {
    resetBoard();
    gameController.startTimer();
}

