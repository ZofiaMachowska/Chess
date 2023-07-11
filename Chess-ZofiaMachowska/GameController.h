#pragma once
#define GAMECONTROLLER_H

class GameController {
public:

	void switchPlayer();
	bool getWhitePlayer();

private:
	bool whitePlayer = true;
};