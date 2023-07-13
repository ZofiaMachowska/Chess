#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include "BoardController.h"
#include "ChessUIController.h"
#include "AIController.h"
#include "GameController.h"
#include "MenuController.h"
#include "AppState.h"
#include "MenuState.h"
#include "GameState.h"
#include "OptionsState.h"

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

