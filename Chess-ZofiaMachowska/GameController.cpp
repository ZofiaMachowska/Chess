#include <iostream>
#include "GameController.h"

GameController::GameController()
{
	player1 = new Player("White", true);
	player2 = new Player("Black", false);
	//player powinien miec parametr isAI, jak jest taki to nie rejestruje eventow zadnych (oprocz game exit). 
	// AIController aktywuje sie sie przy setActiveState
	//sprawdza bezpieczenstwo krola w pierwszej kolejnosci. a) sprawdza czy moze uciec krolem a potem sprawdza czy ew moze zaslonic krola inna figura
	// funkcja ktora sprawdza czy dowolna figura jest zagrozona 
	//AIController co ture powinien robic tablice 2 wymiarowa z polami zagrozonymi przez gracza drugiego (true, false)
	// priorytyzuje ucieczke figury o najwiekszej wartosci 
	// nastpeny krok proba zbicia najwyzszej figury 
	// a jezeli nic to krok do przodu dowolny losowy
}

bool GameController::isFirstPlayerTurn() {
	return player1->checkIsActive();
}


// funkcja isActivePlayerAI

Player* GameController::getCurrentPlayer() {
	return player1->checkIsActive()? player1 : player2;
}

void GameController::switchPlayer() {
	player1->setActiveState(!player1->checkIsActive());
	player2->setActiveState(!player2->checkIsActive());
}

void GameController::startTimer() {
	player1->timer->start();
	player2->timer->start();
	player2->timer->stop();
}
