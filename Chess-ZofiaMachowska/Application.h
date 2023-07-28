#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include "BoardController.h"
#include "UIBoardController.h"
#include "AIController.h"
#include "UIMenuController.h"
#include "AppState.h"
#include "MenuState.h"
#include "GameState.h"
#include "LoadingState.h"
#include "OptionsState.h"
#include "chessStructures.h"

class Application {
public:
    Application();
    void run();
    static void changeAppState(std::unique_ptr<AppState> newState);
    static void setOptionsChoice(Options optionsChoice);
    static Options getAiPlayerOptionsValue();

private:
    static Options aiPlayerOptions;
    sf::RenderWindow window;
    static std::unique_ptr<AppState> currentState;
};

#endif // APPLICATION_H

