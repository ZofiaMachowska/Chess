#include "Application.h"

std::unique_ptr<AppState> Application::currentState = nullptr;
SaveLoadManager Application::saveLoadManager;
//Options Application::aiPlayerOptions;

Application::Application() {
    saveLoadManager.loadGamesFromFile();
}

Application::~Application() {
}

//Options Application::getAiPlayerOptionsValue() {
//    return Application::aiPlayerOptions;
//}
//
//void Application::setOptionsChoice(Options optionsChoice) {
//    Application::aiPlayerOptions.firstPlayerAi = optionsChoice.firstPlayerAi;
//    Application::aiPlayerOptions.secondPlayerAi = optionsChoice.secondPlayerAi;
//}

void Application::changeAppState(std::unique_ptr<AppState> newState) {
    Application::currentState = std::move(newState);
}

void Application::run() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Chess by Zofia Machowska");
    window.setVerticalSyncEnabled(true);
    Application::currentState = std::make_unique<MenuState>();

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
