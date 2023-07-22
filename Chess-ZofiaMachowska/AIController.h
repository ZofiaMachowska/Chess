//jak jest AI to nie rejestruje eventow zadnych (oprocz game exit). 
// AIController aktywuje sie sie przy setActiveState
// //AIController co ture powinien robic tablice 2 wymiarowa z polami zagrozonymi przez gracza drugiego (true, false)
//sprawdza bezpieczenstwo krola w pierwszej kolejnosci.
//  sprawdza czy moze uciec krolem a potem sprawdza czy ew moze zaslonic krola inna figura
// funkcja ktora sprawdza czy dowolna figura jest zagrozona 
// priorytyzuje ucieczke figury o najwiekszej wartosci 
// nastpeny krok proba zbicia najwyzszej figury 
// a jezeli nic to krok do przodu dowolny losowy

#pragma once
#define AICONTROLLER_H
#include <iostream>
#include <functional>

class AIController {
public:
	void makeAMove();
	AIController();

private:
	void createDangerFieldsBoard();
	bool checkIsPlayerKingSafety();
	void protectKing();
	void checkFiguresSafety();
	void capturePiece();
	void setMovePieceCallback(std::function<void()> callback);
	std::function<void()> movePieceCallback;
	//sf::Vector2i oldPos;
	//sf::Vector2i newPos;
	//int movedFigure;

};
