#include "Application.h"

std::unique_ptr<AppState> Application::currentState = nullptr;

MenuState::MenuState() {
}

GameState::GameState() : board(), uiController(), event() {
}

Application::Application() {
}

void MenuState::handleEvent(sf::Event event, sf::RenderWindow& window) {
    if (event.type == sf::Event::Closed)
    {
        window.close();
    }
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        menuController.handleButtonPress(window);
    }
}

void MenuState::render(sf::RenderWindow& window) {
    menuController.redrawWindow(window);
}

void MenuState::setTextures() {
    menuController.setTextures();

    //obsluga eventow na klikniecie buttona
    menuController.setNewGameCallback([this]() {
        std::cout << "udany callback dla setNewGame" << std::endl;
        Application::changeAppState(std::make_unique<GameState>());
    });
}

void GameState::handleEvent(sf::Event event, sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2i boardPosition(mousePos.x / 100, mousePos.y / 100);

    if (event.type == sf::Event::Closed)
    {
        window.close();
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        board.onBoardClicked(boardPosition);
        uiController.printBoardDebug(board.getBoard());
    }

    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
    {
        board.onBoardReleased(boardPosition);
        uiController.printBoardDebug(board.getBoard());
    }
}

void GameState::setTextures() {
    uiController.setTexturesOfFigures();
}

void GameState::render(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    uiController.redrawBoard(window, mousePos, board.getBoard(), board.getMovedFigure(), board.isWhitePlayerTurn());
}

void OptionsState::handleEvent(sf::Event event, sf::RenderWindow& window) {
}

void OptionsState::render(sf::RenderWindow& window) {
}

void OptionsState::setTextures() {
}

void Application::changeAppState(std::unique_ptr<AppState> newState) {
    Application::currentState = std::move(newState);
    Application::currentState->setTextures();
    std::cout << "zmiana stanu okna" << std::endl;
}

void Application::run() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "My Application");
    window.setVerticalSyncEnabled(true);

    Application::currentState = std::make_unique<MenuState>();
    Application::currentState->setTextures();

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
