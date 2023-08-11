#include "Application.h"

std::unique_ptr<AppState> Application::currentState = nullptr;
Options Application::aiPlayerOptions;
int Application::gameToLoad = -1;
std::vector<Game> Application::games;

Application::Application() {
    GameState::saveController.loadGamesFromFile();
    Application::setSavedGames(GameState::saveController.getGames());
}

Options Application::getAiPlayerOptionsValue() {
    return Application::aiPlayerOptions;
}

void Application::setGameIndexToLoad(int index) {
    gameToLoad = index;
}

Game Application::getGameToLoad() {
    return Application::games[gameToLoad];
}

std::vector<Game> Application::getSavedGamesValues() {
    return Application::games;
}

void Application::setSavedGames(std::vector<Game> games) {
    Application::games.clear();
    Application::games = games;
}

void Application::setOptionsChoice(Options optionsChoice) {
    Application::aiPlayerOptions.firstPlayerAi = optionsChoice.firstPlayerAi;
    Application::aiPlayerOptions.secondPlayerAi = optionsChoice.secondPlayerAi;
}

void Application::changeAppState(std::unique_ptr<AppState> newState) {
    Application::currentState = std::move(newState);
    Application::currentState->initialize();
}

void Application::run() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "My Application");
    window.setVerticalSyncEnabled(true);

    Application::currentState = std::make_unique<MenuState>();
    Application::currentState->initialize();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        
            Application::currentState->handleEvent(event, window);
        }

        window.clear();

        Application::currentState->render(window);

        window.display();
    }
}
