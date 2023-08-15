#pragma once
#include "AppState.h"
#include "Application.h"
#include "UILoadingController.h"

/**
 * @class LoadingState
 * @brief Represents the Loading game screen of the application.
 *
 */
class LoadingState : public AppState {
private:
    UILoadingController uiLoadingController; ///< Controller responsible for managing the user interface during the loading state.

public:
    /**
     * @brief Constructs the LoadingState.
     */
    LoadingState();

    /**
     * @brief Destroys the LoadingState.
     */
    ~LoadingState();

    /**
     * @brief Overrides the handleEvent method from AppState to provide specific handling for events during the loading state.
     *
     * @param event The event object representing user interactions or system events.
     * @param window Reference to the SFML RenderWindow.
     */
    void handleEvent(sf::Event event, sf::RenderWindow& window) override;

    /**
     * @brief Overrides the render method from AppState to display the user interface for the loading screen.
     *
     * @param window Reference to the SFML RenderWindow.
     */
    void render(sf::RenderWindow& window) override;

    /**
     * @brief Overrides the initialize method from AppState, initializes resources and visuals for the loading screen.
     */
    void initialize() override;
};
