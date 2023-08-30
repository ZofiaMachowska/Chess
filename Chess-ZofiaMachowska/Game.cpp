#include "Game.h"

Game::Game(bool player1AI, bool player2AI)
    : player1("W", player1AI), player2("B", player2AI), gameOver(false), board() {
    currentPlayer = &player1;
}

void Game::start() {
    player1.startNewTimer();
    player1.setFirstMove(false);
    // Move aiMove = AI::generateMove(board, 'B');
}

void Game::loadGame(GameSaveLoad gameToLoad) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            ChessPiece* loadedPiece = gameToLoad.board[i][j];
            board.setPiece(i, j, loadedPiece);
        }
    }

    player1 = gameToLoad.player1;
    player2 = gameToLoad.player2;
    currentPlayer = gameToLoad.currentPlayerColor == player1.getColor() ? &player1 : &player2;
    currentPlayer->resumeTimer();
    gameOver = gameToLoad.gameOver;
}


void Game::switchPlayer() {
    currentPlayer->stopTimer();
    currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
    if (currentPlayer->isFirstMove()) {
        currentPlayer->startNewTimer();
        currentPlayer->setFirstMove(false);
    }
    else {
        currentPlayer->resumeTimer();
    }
}

bool Game::isCheck() {
    // TODO: Add check detection logic here
    return false;
}

bool Game::isCheckmate() {
    // TODO: Add checkmate detection logic here
    return false;
}

bool Game::isGameOver() {
    return gameOver;
}

Player* Game::getCurrentPlayer() {
    return currentPlayer;
}

Player Game::get1Player() {
    return player1;
}

Player Game::get2Player() {
    return player2;
}

ChessPiece* (&Game::getChessBoard())[8][8]{
    return board.getBoard();
}

ChessPiece* Game::getSelectedPiece() {
    return selectedPiece;
}

void Game::onBoardClicked(int x, int y) {
    ChessPiece* piece = board.getPieceAt(x, y);

    if (piece && piece->getColor() == currentPlayer->getColor()) {
        board.prepareTemporaryBoard();
        selectedPiece = piece;
        selectedPiece->setPosition(x, y);
        board.setPiece(y, x, nullptr);
        pieceOldPosition =  sf::Vector2i(x, y);
    }
}

void Game::onBoardReleased(int x, int y) {
    if (!selectedPiece) {
        return;
    }

    Move move(pieceOldPosition.x, pieceOldPosition.y, x, y);
    if (board.isMovePossible(move, currentPlayer->getColor())) {
        board.setPiece(y, x, selectedPiece);
        switchPlayer();
    }
    else {
        board.setPiece(pieceOldPosition.y, pieceOldPosition.x, selectedPiece);
    }
    selectedPiece = nullptr; 
}