#pragma once
#include "AppState.h"
#include "Application.h"
#include "UILoadingController.h"

/**
 * @brief Represents the state in the application lifecycle when the game is in the loading phase.
 * It inherits from the AppState base class to provide specific functionalities related to loading game resources and visuals.
 */
class LoadingState : public AppState {
private:
    UILoadingController uiLoadingController; ///< Controller responsible for managing the user interface during the loading state.

public:
    /**
     * @brief Constructs the LoadingState, setting up the initial state.
     */
    LoadingState();

    /**
     * @brief Destroys the LoadingState, cleaning up any allocated resources.
     */
    ~LoadingState();

    /**
     * @brief Overrides the handleEvent method from AppState to provide specific handling for events during the loading phase.
     *
     * @param event The event object representing user interactions or system events.
     * @param window Reference to the SFML RenderWindow, used to interact with the graphical interface.
     */
    void handleEvent(sf::Event event, sf::RenderWindow& window) override;

    /**
     * @brief Overrides the render method from AppState to display the user interface for the loading phase.
     *
     * @param window Reference to the SFML RenderWindow, where the loading UI elements are drawn.
     */
    void render(sf::RenderWindow& window) override;

    /**
     * @brief Overrides the initialize method from AppState to set up the necessary resources and visuals for the loading phase.
     */
    void initialize() override;
};
