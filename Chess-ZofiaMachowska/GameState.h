#pragma once
#include <SFML/Graphics.hpp>
#include "BoardController.h"
#include "UIBoardController.h"
#include "AIController.h"
#include "AppState.h"
#include "Application.h"
#include "SavingGameController.h"

class GameState : public AppState {
private: 
    BoardController board;
    UIBoardController uiController;
    sf::Event event;
 
public:
    static SavingGameController saveController;
    GameState();
    void handleEvent(sf::Event event, sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;
    void initialize() override;
};
