#include "Application.h"

std::unique_ptr<AppState> Application::currentState = nullptr;
Options Application::aiPlayerOptions;

Application::Application() {
}

Options Application::getAiPlayerOptionsValue() {
    return Application::aiPlayerOptions;
}

void Application::setOptionsChoice(Options optionsChoice) {
    Application::aiPlayerOptions.firstPlayerAi = optionsChoice.firstPlayerAi;
    Application::aiPlayerOptions.secondPlayerAi = optionsChoice.secondPlayerAi;
}

void Application::changeAppState(std::unique_ptr<AppState> newState) {
    std::cout << "To pierwsze AI: " << Application::aiPlayerOptions.firstPlayerAi <<std::endl;
    std::cout << "To drugie AI: " << Application::aiPlayerOptions.secondPlayerAi << std::endl;

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
