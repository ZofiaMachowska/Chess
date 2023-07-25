#include "Application.h"

std::unique_ptr<AppState> Application::currentState = nullptr;

Application::Application() {
}

void Application::changeAppState(std::unique_ptr<AppState> newState) {
    Application::currentState = std::move(newState);
    Application::currentState->initialize();
    std::cout << "zmiana stanu okna" << std::endl;
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
