#include "Game.h"

Game::Game(bool player1AI, bool player2AI)
    : player1("W", player1AI), player2("B", player2AI), gameOver(false), board(),
    ai(player1.getIsPlayerAI() ? player1.getColor() : player2.getColor()) {
    currentPlayer = &player1;
}

void Game::start() {
    currentPlayer->startNewTimer();
    currentPlayer->setFirstMove(false);
    if (currentPlayer->getIsPlayerAI()) {
        Move aiMove = ai.makeMove(board, currentPlayer);
        if (aiMove.fromCol >= 0) {
            makeAMove(aiMove);
        }
        else {
            std::cout << "NO VALID MOVES " << std::endl;
        }
    }
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
    if (currentPlayer->getIsPlayerAI()) {
        Move aiMove = ai.makeMove(board, currentPlayer);
        if (aiMove.fromCol >= 0) {
            makeAMove(aiMove);
        }
        else {
            std::cout << "NO VALID MOVES " << std::endl;
        }
    }
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
        board.setPiece(move.toCol, move.toRow, selectedPiece);
        if (selectedPiece ->type() == "P") {
            Pawn* pawnPtr = dynamic_cast<Pawn*>(selectedPiece);
            if (pawnPtr != nullptr) {
                pawnPtr->setHasMoved(true);
            }
        }
        switchPlayer();
    }
    else {
        board.setPiece(pieceOldPosition.y, pieceOldPosition.x, selectedPiece);
    }
    selectedPiece = nullptr; 
}

void Game::makeAMove(Move newMove) {
    ChessPiece* piece = board.getPiece(newMove.fromCol, newMove.fromRow);

    board.setPiece(newMove.toCol, newMove.toRow, piece);
    board.setPiece(newMove.fromCol, newMove.fromRow, nullptr);
    if (piece && piece->type() == "P") {
        Pawn* pawnPtr = dynamic_cast<Pawn*>(piece);
        if (pawnPtr != nullptr) {
            pawnPtr->setHasMoved(true);
        }
    }
    switchPlayer();
}