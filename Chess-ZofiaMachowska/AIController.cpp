#include "AIController.h"
#include "BoardController.h"

bool dangerFieldsBoard[8][8];

void  AIController::setMovePieceCallback(std::function<void()> callback) {
    movePieceCallback = std::move(callback);
}

AIController::AIController()
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            dangerFieldsBoard[i][j] = false;
        }
    }
    setMovePieceCallback([this]() {
        std::cout << "callback do updateBoardState" << std::endl;
        BoardController::aiUpdateBoardState(5, sf::Vector2i(5,5), sf::Vector2i(5, 6));
        });
}

void AIController::createDangerFieldsBoard() {
   
}

void AIController::makeAMove() {
    movePieceCallback();
}