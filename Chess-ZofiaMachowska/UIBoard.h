#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include "Button.h"
#include "Game.h"


/**
 * @brief Controller class responsible for rendering and updating the visual representation of the chessboard.
 *
 * `UIBoardController` manages the visual components associated with the chessboard. It is in charge of
 * drawing pieces, updating the state of the board when a move is made, and providing user interface elements
 * related to the game.
 */
class UIBoard {
public:
    /**
     * @brief Default constructor for the UIBoardController class.
     */
    UIBoard();

    /**
     * @brief Destructor for the UIBoardController class.
     */
    ~UIBoard();

    /**
     * @brief Renders the entire chessboard, including pieces and UI elements.
     *
     * @param window Reference to the SFML RenderWindow.
     * @param board array representing the state of the chessboard.
     * @param movedFigure Integer identifier of a piece being moved.
     * @param currentPlayer Pointer to the current player's information.
     * @param gameOver Flag indicating if the game is over.
     */
    void redrawBoard(sf::RenderWindow& window, Game& game);

    /**
     * @brief Prints the state of the board to the console (for debugging purposes).
     *
     * @param board array representing the state of the chessboard.
     */

    Button* backButton; ///< Button allowing users to navigate back.
    Button* saveButton; ///< Button used to save the game state.

private:
    const int WINDOW_HEIGHT = 800;
    const int WINDOW_WIDTH = 1200;
    const int SQUARE_SIZE = 100;
    const int BOARD_LENGTH = 7;

    /**
 * @brief Textures for white chess pieces.
 */
    sf::Texture pawnWTexture, rookWTexture, knightWTexture, bishopWTexture, queenWTexture, kingWTexture;

    /**
     * @brief Textures for black chess pieces.
     */
    sf::Texture pawnBTexture, rookBTexture, knightBTexture, bishopBTexture, queenBTexture, kingBTexture;

    /**
     * @brief Texture for the chessboard.
     */
    sf::Texture boardTexture;

    /**
     * @brief Sprites for white chess pieces.
     */
    sf::Sprite pawnWSprite, rookWSprite, knightWSprite, bishopWSprite, queenWSprite, kingWSprite;

    /**
     * @brief Sprites for black chess pieces.
     */
    sf::Sprite pawnBSprite, rookBSprite, knightBSprite, bishopBSprite, queenBSprite, kingBSprite;

    /**
     * @brief Sprite for the chessboard.
     */
    sf::Sprite boardSprite;

    /**
     * @brief Font for UI texts.
     */
    sf::Font font;

    /**
     * @brief Text for the game title.
     */
    sf::Text title;

    /**
     * @brief Information about game time.
     */
    sf::Text timerInformation;


    /**
     * @brief Initializes the visual representations (sprites) for the chess pieces.
     */
    void setFiguresVisuals();

    /**
     * @brief Draws a chess piece on the board.
     */
    void drawPiece(sf::RenderWindow& window, sf::Sprite piece, int j, int i);
    /**
     * @brief Redraws the board when a chess move is made.
     *
     * @param window Reference to the SFML RenderWindow.
     * @param mousePos Coordinates of the mouse position.
     * @param movedFigure Integer identifier of the piece being moved.
     */
    void redrawChessMove(sf::RenderWindow& window, sf::Vector2i mousePos, ChessPiece* selectedPiece);

    /**
     * @brief Renders the informational panel, providing details about the current game state.
     *
     * @param window Reference to the SFML RenderWindow.
     * @param currentPlayer Pointer to the current player's information.
     * @param isGameOver Flag indicating if the game is over.
     */
    void redrawInfoPannel(sf::RenderWindow& window, Player* currentPlayer, bool gameOver);

    /**
     * @brief Calculates the time remaining.
     *
     * @param time A pair representing the minutes and seconds.
     */
    void calculateTimer(std::pair<int, int> time);

    /**
     * @brief Fetches the sprite for a given piece.
     *
     * @param movedFigure Integer identifier of the piece being moved.
     * @return Returns a sprite representing the moved chess piece.
     */
    sf::Sprite getFigureSprite(ChessPiece* selectedPiece);

    /**
    * @brief Fetches the sprite for a black chess piece.
    *
    * This function returns a sprite representing a black chess piece.
    *
    * @param selectedPiece Pointer to the chess piece being moved.
    * @return Returns a sprite representing a black chess piece.
    */
    sf::Sprite getBlackFigure(ChessPiece* selectedPiece);

    /**
     * @brief Fetches the sprite for a white chess piece.
     *
     * This function returns a sprite representing a white chess piece.
     *
     * @param selectedPiece Pointer to the chess piece being moved.
     * @return Returns a sprite representing a white chess piece.
     */
    sf::Sprite getWhiteFigure(ChessPiece* selectedPiece);
};
