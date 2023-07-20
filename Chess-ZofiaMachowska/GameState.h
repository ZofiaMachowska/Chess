#pragma once
#include <SFML/Graphics.hpp>
#include "BoardController.h"
#include "UIBoardController.h"
#include "AIController.h"
#include "GameController.h"
#include "AppState.h"

class GameState : public AppState {
private: 
    BoardController board;
    GameController gameController;
    UIBoardController uiController;
    sf::Event event;
 
public:
    GameState();
    void handleEvent(sf::Event event, sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;
    void initialize() override;
};
