#pragma once
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
    static void changeAppState(std::unique_ptr<AppState> newState);
    static void setOptionsChoice(Options optionsChoice);
    static void setGameIndexToLoad(int index);
    static void setSavedGames(std::vector<Game> games);
    void run();

    static Options getAiPlayerOptionsValue();
    static Game getGameToLoad();
    static std::vector<Game> getSavedGamesValues();
    static int gameToLoad;

private:
    static Options aiPlayerOptions;
    static std::vector<Game> games;
    static std::unique_ptr<AppState> currentState;
    sf::RenderWindow window;
};
