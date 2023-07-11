#include <iostream>
#include "GameController.h"

bool GameController::getWhitePlayer() {
	return whitePlayer;
}

void GameController::switchPlayer() {
	whitePlayer = !whitePlayer;
}
