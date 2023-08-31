#include "Board.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

Board::Board() {
    initialize();
}

Board::~Board() {
    for(int row = 0; row < 8; ++row) {
        for(int col = 0; col < 8; ++col) {
            delete board[row][col];
        }
    }
}

void Board::initialize() {
    for(int row = 0; row < 8; ++row) {
        for(int col = 0; col < 8; ++col) {
            board[row][col] = nullptr;
        }
    }

    for (int col = 0; col < 8; ++col) {
        board[1][col] = new Pawn(1, col, "B");
        board[6][col] = new Pawn(6, col, "W");
    }

    board[0][0] = new Rook(0, 0, "B");
    board[0][1] = new Knight(0, 1, "B");
    board[0][2] = new Bishop(0, 2, "B");
    board[0][3] = new Queen(0, 3, "B");
    board[0][4] = new King(0, 4, "B");
    board[0][7] = new Rook(0, 7, "B");
    board[0][6] = new Knight(0, 6, "B");
    board[0][5] = new Bishop(0, 5, "B");

    board[7][0] = new Rook(7, 0, "W");
    board[7][1] = new Knight(7, 1, "W");
    board[7][2] = new Bishop(7, 2, "W");
    board[7][3] = new Queen(7, 3, "W");
    board[7][4] = new King(7, 4, "W");
    board[7][7] = new Rook(7, 7, "W");
    board[7][6] = new Knight(7, 6, "W");
    board[7][5] = new Bishop(7, 5, "W");
}

ChessPiece* Board::getPiece(int row, int col) const {
    return board[row][col];
}

void Board::setPiece(int row, int col, ChessPiece* piece) {
    board[row][col] = piece;
}

void Board::movePiece(int fromRow, int fromCol, int toRow, int toCol) {
    ChessPiece* piece = getPiece(fromRow, fromCol);
    if (piece == nullptr) {
        return;
    }

    setPiece(toRow, toCol, piece);
    setPiece(fromRow, fromCol, nullptr);
    piece->setPosition(toRow, toCol);
}

ChessPiece* Board::getPieceAt(int row, int col) {
    if (row >= 0 && row < 8 && col >= 0 && col < 8) {
        return board[col][row];
    }
    return nullptr;
}

void Board::prepareTemporaryBoard() {
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {
            temporaryTestingBoard[i][j] = board[i][j];
        }
    }
}

void Board::printBoard() const {
    for(int row = 0; row < 8; ++row) {
        for(int col = 0; col < 8; ++col) {
            ChessPiece* piece = getPiece(row, col);
            if(piece == nullptr) {
                std::cout << ".";
            } else {
              std::cout << piece->type();
            }
        }
        std::cout << std::endl;
    }
}

bool Board::isMovePossible(Move move, std::string currentPlayer) {
    bool movePossible = MoveValidator::isValidMove(temporaryTestingBoard, move, currentPlayer);
    return movePossible;
}

ChessPiece* (&Board::getTemporaryBoard())[8][8]{
    return temporaryTestingBoard;
}

ChessPiece*(&Board::getBoard())[8][8]{
    return board;
}
