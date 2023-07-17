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
    std::cout << "dotknieto: " << chessBoard[pos.y][pos.x] << std::endl;
    Player* currentPlayer = gameController.getCurrentPlayer();
    std::cout << "Kolej gracza: " << currentPlayer->getColor() << std::endl;
    if (chessBoard[pos.y][pos.x] == 0) return;
    sf::Vector2i boardPosition(pos.x, pos.y);
    bool whitePlayerTurn = gameController.isFirstPlayerTurn();

    if (whitePlayerTurn) moveWhitePiece(boardPosition);
    else moveBlackPiece(boardPosition);

    //jezeli wchodzi w ten warunek to znaczy ze sie udalo podniesc figure
    if (chessBoard[pos.y][pos.x] == 0) {
        oldPosition.x = pos.x;
        oldPosition.y = pos.y;
        std::cout << "udalo sie podniesc figure " << movedFigure << std::endl;
    }
}

void BoardController::onBoardReleased(sf::Vector2i pos) {

    if (movedFigure == 0) return;
    bool movePossible = false;
    bool kingSafe = false;
    bool whitePlayer = gameController.isFirstPlayerTurn();

    switch (abs(movedFigure)) {
    case 1:
        movePossible = pawn.isMovePossible(oldPosition, pos, chessBoard, whitePlayer);
        break;
    case 2:
        movePossible = rook.isMovePossible(oldPosition, pos, chessBoard, whitePlayer);
        break;
    case 3:
        movePossible = knight.isMovePossible(oldPosition, pos, chessBoard, whitePlayer);
        break;
    case 4:
        movePossible = bishop.isMovePossible(oldPosition, pos, chessBoard, whitePlayer);
        break;
    case 5:
        movePossible = queen.isMovePossible(oldPosition, pos, chessBoard, whitePlayer);
        break;
    case 6:
        movePossible = king.isMovePossible(oldPosition, pos, chessBoard, whitePlayer);
        break;
    default:
        break;
    }

    //sprawdz czy ten ruch nie zagrozi krolowi gracza
    kingSafe = checkKingSafe(whitePlayer);
    checkPlayerMoveValidity(pos, kingSafe, movePossible);
}

bool BoardController::checkKingSafe(bool whitePlayer) {

    sf::Vector2i kingPosition = king.findKingPosition(chessBoard, whitePlayer);
 
    for (int i = 0; i <= BOARD_LENGTH; i++) {
        for (int j = 0; j <= BOARD_LENGTH; j++) {
            if (chessBoard[i][j] <= 0) {
                switch (abs(chessBoard[i][j])) {
                case 1:
                    if (pawn.checkKingCapture(sf::Vector2i(j,i), kingPosition, chessBoard, whitePlayer)) {
                        std::cout << "Pionek zablokowal" << std::endl;
                        return false;
                    };
                    break;
                case 2:
                    if (rook.checkKingCapture(sf::Vector2i(j, i), kingPosition, chessBoard, whitePlayer)) {
                        std::cout << "wieza zablokowala" << std::endl;
                        return false;
                    };
                    break;
                case 3:
                    if (knight.checkKingCapture(sf::Vector2i(j, i), kingPosition, chessBoard, whitePlayer)) {
                        std::cout << "konik zablokowal" << std::endl;
                        return false;
                    };
                    break;
                case 4:
                    if (bishop.checkKingCapture(sf::Vector2i(j, i), kingPosition, chessBoard, whitePlayer)) {
                        std::cout << "laufer zablokowal" << std::endl;
                        return false;
                    };
                    break;
                case 5:
                    if (queen.checkKingCapture(sf::Vector2i(j, i), kingPosition, chessBoard, whitePlayer)) {
                        std::cout << "krolowa zablokowal" << std::endl;
                        return false;
                    };
                    break;
                case 6:
                    if (king.checkKingCapture(sf::Vector2i(j, i), kingPosition, chessBoard, whitePlayer)) {
                        std::cout << "krol zablokowal" << std::endl;
                        return false;
                    };
                    break;
                default:
                    break;
                }
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
   std::cout << "Tablica zosta³a przywrocona do stanu poczatkowego" << std::endl;
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

