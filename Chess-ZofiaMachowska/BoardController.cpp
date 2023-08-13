#include "BoardController.h"

int chessBoard[8][8] = {
   2, 3, 4, 5, 6, 4, 3, 2,
   1, 1, 1, 1, 1, 1, 1, 1,
   0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0,
   -1, -1, -1, -1, -1, -1, -1, -1,
   -2, -3, -4, -5, -6, -4, -3, -2,
};

int temporaryBoard[8][8];

PawnController BoardController::pawn;
KnightController BoardController::knight;
BishopController BoardController::bishop;
RookController BoardController::rook;
QueenController BoardController::queen;
KingController BoardController::king;
PlayerController BoardController::playerController;
int BoardController::movedFigure;
bool BoardController::gameOver;
sf::Vector2i BoardController::oldPosition;

BoardController::~BoardController() {

}

int(&BoardController::getBoard())[8][8]{
    return chessBoard;
}

std::vector<Player*> BoardController::getCurrentPlayers() {
    std::vector<Player*> players = playerController.getPlayers();
    return players;
}

int BoardController::getMovedFigure() {
    return movedFigure;
}

bool BoardController::isGameOver() {
    return gameOver;
}

Player* BoardController::getCurrentPlayer() {
    return playerController.getCurrentPlayer();
}

void BoardController::moveThisPiece(bool whitePlayer, int pieceNumber, sf::Vector2i position) {
    if (whitePlayer && pieceNumber < 0 || !whitePlayer && pieceNumber >0) {
        movedFigure = pieceNumber;
        chessBoard[position.y][position.x] = 0;
    }
}

void BoardController::onBoardClicked(sf::Vector2i pos) {
    if (playerController.isActivePlayerAI()) return;
    if (chessBoard[pos.y][pos.x] == 0 || !isOnBoard(pos.x, pos.y) || gameOver) return;

    bool whitePlayerTurn = playerController.isFirstPlayerTurn();
    int pieceType = chessBoard[pos.y][pos.x];

    if (abs(pieceType) > 0 && abs(pieceType) <= 6) {
        moveThisPiece(whitePlayerTurn, pieceType, pos);
    }

    if (chessBoard[pos.y][pos.x] == 0) {
        oldPosition.x = pos.x;
        oldPosition.y = pos.y;
    }
}

bool BoardController::checkPieceMovePossible(const sf::Vector2i& newPosition, bool whitePlayerTurn) {
    switch (abs(movedFigure)) {
    case 1:
        return pawn.isMovePossible(oldPosition, newPosition, chessBoard, whitePlayerTurn);
    case 2:
        return rook.isMovePossible(oldPosition, newPosition, chessBoard, whitePlayerTurn);
    case 3:
        return knight.isMovePossible(oldPosition, newPosition, chessBoard, whitePlayerTurn);
    case 4:
        return bishop.isMovePossible(oldPosition, newPosition, chessBoard, whitePlayerTurn);
    case 5:
        return queen.isMovePossible(oldPosition, newPosition, chessBoard, whitePlayerTurn);
    case 6:
        return king.isMovePossible(oldPosition, newPosition, chessBoard, whitePlayerTurn);
    default:
        return false;
    }
}

void BoardController::onBoardReleased(sf::Vector2i newPosition) {
    if (playerController.isActivePlayerAI()) return;
    if (movedFigure == 0 || gameOver) return;
    bool whitePlayerTurn = playerController.isFirstPlayerTurn();

    if (!checkPieceMovePossible(newPosition, whitePlayerTurn)) {
        handleNoValidMoves();
        return;
    }

    prepareTemporaryBoard();
    moveFigureTemporarily(newPosition, movedFigure);
    checkKingSafe(temporaryBoard, whitePlayerTurn) ? updateBoardState(newPosition) : handleNoValidMoves();
}

void BoardController::prepareTemporaryBoard() {
    for (int i = 0; i <= BOARD_LENGTH; i++) {
        for (int j = 0; j <= BOARD_LENGTH; j++) {
            temporaryBoard[i][j] = chessBoard[i][j];
        }
    }
}

void BoardController::moveFigureTemporarily(sf::Vector2i pos, int piece) {
    temporaryBoard[pos.y][pos.x] = piece;
}

bool BoardController::checkPieceBlocking(const sf::Vector2i& piecePosition, const sf::Vector2i& kingPosition, bool whitePlayerTurn, int board[][8]) {
    int pieceType = board[piecePosition.y][piecePosition.x];
    switch (abs(pieceType)) {
    case 1: 
        return pawn.checkKingCapture(piecePosition, kingPosition, board, whitePlayerTurn);
    case 2: 
        return rook.checkKingCapture(piecePosition, kingPosition, board, whitePlayerTurn);
    case 3: 
        return knight.checkKingCapture(piecePosition, kingPosition, board, whitePlayerTurn);
    case 4: 
        return bishop.checkKingCapture(piecePosition, kingPosition, board, whitePlayerTurn);
    case 5: 
        return queen.checkKingCapture(piecePosition, kingPosition, board, whitePlayerTurn);
    case 6: 
        return king.checkKingCapture(piecePosition, kingPosition, board, whitePlayerTurn);
    default: return false;
    }
}

bool BoardController::checkKingSafe(int board[][8], bool whitePlayerTurn) {
    sf::Vector2i currentPlayerKingPosition = king.findKingPosition(board, whitePlayerTurn);
    for (int i = 0; i <= BOARD_LENGTH; i++) {
        for (int j = 0; j <= BOARD_LENGTH; j++) {
            if (checkPieceBlocking(sf::Vector2i(j, i), currentPlayerKingPosition, whitePlayerTurn, board)) {
                return false;
            }
        }
    }
    return true;
}

bool BoardController::checkPossiblePieceMoves(int piece, std::vector<Move> possibleMoves, bool whitePlayerTurn) {
    if (possibleMoves.empty()) {
        return false;
    }
    prepareTemporaryBoard();
    for (const auto& move : possibleMoves) {
        temporaryBoard[move.start.y][move.start.x] = 0;
        moveFigureTemporarily(move.destination, piece);
        if (checkKingSafe(temporaryBoard, whitePlayerTurn)) {
            return true;
        }
        prepareTemporaryBoard();
    }
    return false;
}

bool BoardController::checkPieceAnyMovePossible(const sf::Vector2i& piecePosition, bool whitePlayerTurn) {
    int pieceType = chessBoard[piecePosition.y][piecePosition.x];
    if (pieceType > 0 && whitePlayerTurn || pieceType < 0 && !whitePlayerTurn) {
        return false;
    }
    std::vector<Move> possibleMoves;
    switch (abs(pieceType)) {
    case 1:
        possibleMoves = pawn.generateValidMoves(piecePosition, chessBoard, whitePlayerTurn);
        return checkPossiblePieceMoves(pieceType, possibleMoves, whitePlayerTurn);
    case 2:
        possibleMoves = rook.generateValidMoves(piecePosition, chessBoard, whitePlayerTurn);
        return checkPossiblePieceMoves(pieceType, possibleMoves, whitePlayerTurn);
    case 3:
        possibleMoves = knight.generateValidMoves(piecePosition, chessBoard, whitePlayerTurn);
        return checkPossiblePieceMoves(pieceType, possibleMoves, whitePlayerTurn);
    case 4:
        possibleMoves = bishop.generateValidMoves(piecePosition, chessBoard, whitePlayerTurn);
        return checkPossiblePieceMoves(pieceType, possibleMoves, whitePlayerTurn);
    case 5:
        possibleMoves = queen.generateValidMoves(piecePosition, chessBoard, whitePlayerTurn);
        return checkPossiblePieceMoves(pieceType, possibleMoves, whitePlayerTurn);
    default: return false;
    }
}

bool BoardController::isAnyFigureMovePossible(bool whitePlayerTurn) {
    std::vector<Move> possibleMoves;
    int piece;
    for (int i = 0; i <= BOARD_LENGTH; i++) {
        for (int j = 0; j <= BOARD_LENGTH; j++) {
            if (checkPieceAnyMovePossible(sf::Vector2i(j, i), whitePlayerTurn)) {
                return true;
            }
            possibleMoves.clear();
        }
    }
    return false;
}

bool BoardController::isKingMovePossible(bool whitePlayerTurn) {
    std::vector<Move> possibleMoves;
    sf::Vector2i currentPlayerKingPosition = king.findKingPosition(chessBoard, whitePlayerTurn);
    possibleMoves = king.generateValidMoves(currentPlayerKingPosition, chessBoard, whitePlayerTurn);
    int kingPiece = whitePlayerTurn ? king.WHITE_KING : king.BLACK_KING;
    return checkPossiblePieceMoves(kingPiece, possibleMoves, whitePlayerTurn);
}

bool BoardController::checkForCheckMate() {
    bool whitePlayerTurn = playerController.isFirstPlayerTurn();
    if (checkKingSafe(chessBoard, whitePlayerTurn)) {
        return false;
    }

    if (isKingMovePossible(whitePlayerTurn)) {
        return false;
    }

    if (isAnyFigureMovePossible(whitePlayerTurn)) {
        return false;
    }
    return true;
}

void BoardController::setGameOver() {
    gameOver = true;
}

void BoardController::aiUpdateBoardState(int aiMovedFigure, sf::Vector2i oldPos, sf::Vector2i newPos) {
    movedFigure = aiMovedFigure;
    chessBoard[oldPos.y][oldPos.x] = 0;
    updateBoardState(newPos);
}

void BoardController::updateBoardState(sf::Vector2i pos) {
    int figureOnOldPosition = chessBoard[oldPosition.y][oldPosition.x];
    chessBoard[pos.y][pos.x] = movedFigure;
    if (checkForCheckMate()) {
        setGameOver();
    }
    movedFigure = 0;
    playerController.switchPlayer(chessBoard);
}

void BoardController::handleNoValidMoves() {
    chessBoard[oldPosition.y][oldPosition.x] = movedFigure;
    movedFigure = 0;
}

void BoardController::resetBoard() {
   int initialChessBoard[8][8] = {
   2, 3, 4, 5, 6, 4, 3, 2,
   1, 1, 1, 1, 1, 1, 1, 1,
   0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0,
   -1, -1, -1, -1, -1, -1, -1, -1,
   -2, -3, -4, -5, -6, -4, -3, -2,
   };
   for (int i = 0; i <= BOARD_LENGTH; i++) {
       for (int j = 0; j <= BOARD_LENGTH; j++) {
           chessBoard[i][j] = initialChessBoard[i][j];
       }
   }
}

void BoardController::startNewGame(Options aiOptionsChoice) {
    gameOver = false;
    resetBoard();
    playerController.setPlayersAiFromOptions(aiOptionsChoice);
    playerController.resetFirstPlayer();
    playerController.startTimer();
    playerController.shouldRunAI(getBoard());
}

void BoardController::loadGame(Game gameToLoad) {
    gameOver = gameToLoad.gameOver;
    for (int i = 0; i <= BOARD_LENGTH; i++) {
        for (int j = 0; j <= BOARD_LENGTH; j++) {
            chessBoard[i][j] = gameToLoad.board[i][j];
        }
    }
   playerController.setLoadedPlayers(gameToLoad);
   playerController.shouldRunAI(getBoard());
}
