#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include "BoardController.h"
#include "ChessUIController.h"
#include "AIController.h"
#include "GameController.h"
#include "MenuController.h"


class AppState {
public:
    virtual void handleEvent(sf::Event event, sf::RenderWindow& window) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void setTextures() = 0;
};

class MenuState : public AppState {
private:
    MenuController menuController;

public:
    MenuState();
    void handleEvent(sf::Event event, sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;
    void setTextures() override;
};

class GameState : public AppState {
private: 
    BoardController board;
    ChessUIController uiController;
    sf::Event event;
 
public:
    GameState();
    void handleEvent(sf::Event event, sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;
    void setTextures() override;
};

class OptionsState : public AppState {
public:
    void handleEvent(sf::Event event, sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;
    void setTextures() override;
};

class Application {
public:
    Application();
    void run();
    static void changeAppState(std::unique_ptr<AppState> newState);

private:
    sf::RenderWindow window;
    static std::unique_ptr<AppState> currentState;
};

#endif // APPLICATION_H

