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
    static void setGameIndexToLoad(int index);
    static Game getGameToLoad();
    static void setSavedGames(std::vector<Game> games);
    static std::vector<Game> getSavedGamesValues();
    static int gameToLoad;


private:
    static Options aiPlayerOptions;
    static std::vector<Game> games;
    sf::RenderWindow window;
    static std::unique_ptr<AppState> currentState;
};

#endif // APPLICATION_H

