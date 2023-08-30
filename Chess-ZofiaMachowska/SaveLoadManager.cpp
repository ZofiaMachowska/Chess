#include "SaveLoadManager.h"

SaveLoadManager::SaveLoadManager() {

}


SaveLoadManager::~SaveLoadManager() {

}

bool SaveLoadManager::shouldLoadAGame() {
    return gameToLoad >= 0;
}

void SaveLoadManager::setFlagToLoadGame(int flag) {
    gameToLoad = flag;
}

GameSaveLoad SaveLoadManager::getGameToLoad() {
    return games[gameToLoad];
}

std::vector<GameSaveLoad> SaveLoadManager::getGames() {
    return games;
}

Json::Value SaveLoadManager::timerToJson(Timer* timer) const {
    Json::Value jsonTimer;
    jsonTimer["isRunning"] = timer->getIsRunning();
    jsonTimer["initialDuration"] = timer->getInitialDuration();
    jsonTimer["remainingTime"] = timer->getRemainingTime();
    return jsonTimer;
}

Json::Value SaveLoadManager::playerToJson(Player player) const {
    Json::Value jsonPlayer;

    jsonPlayer["color"] = player.getColor();
    jsonPlayer["isAI"] = player.getIsPlayerAI();
    jsonPlayer["timer"] = timerToJson(player.getTimer());
    return jsonPlayer;
}

void  SaveLoadManager::setSaveNewGameCallback(std::function<void()> callback) {
    savedNewGameCallback = std::move(callback);
}

void SaveLoadManager::addNewGameToHistory(Game& game) {
    auto currentTime = std::chrono::system_clock::now();
    std::time_t timestamp = std::chrono::system_clock::to_time_t(currentTime);
    std::tm timeinfo;
    localtime_s(&timeinfo, &timestamp);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);
    std::string readableTime(buffer);

    ChessPiece* (*sourceBoard)[8] = game.getChessBoard();
    GameSaveLoad gameForSaving;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            gameForSaving.board[i][j] = sourceBoard[i][j];
        }
    }
    gameForSaving.player1 = game.get1Player();
    gameForSaving.player2 = game.get2Player();
    gameForSaving.currentPlayerColor = game.getCurrentPlayer()->getColor();
    gameForSaving.timeOfSaving = readableTime;
    gameForSaving.gameOver = game.isGameOver();
    games.insert(games.begin(), gameForSaving);
    if (games.size() > MAX_GAME_HISTORY) {
        games.erase(games.begin() + MAX_GAME_HISTORY, games.end());
    }
    if (savedNewGameCallback) {
        savedNewGameCallback();
    }
}

void SaveLoadManager::saveGameToFile() {
    Json::Value jsonGames;
    for (const GameSaveLoad& game : games) { 
        Json::Value jsonGame;

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                ChessPiece* piece = game.board[i][j];
                if (piece != nullptr) {
                    Json::Value jsonPiece;
                    jsonPiece["type"] = piece->type();
                    jsonPiece["color"] = piece->getColor();
                    jsonPiece["col"] = piece->getCol();
                    jsonPiece["row"] = piece->getRow();
                    jsonGame["chessBoard"][i][j] = jsonPiece;
                }
                else {
                    jsonGame["chessBoard"][i][j] = Json::Value(Json::nullValue);
                }
            }
        }

        jsonGame["player1"] = playerToJson(game.player1);
        jsonGame["player2"] = playerToJson(game.player2);
        jsonGame["currentPlayerColor"] = game.currentPlayerColor;
        jsonGame["timeOfSaving"] = game.timeOfSaving;
        jsonGame["gameOver"] = game.gameOver;
        jsonGames.append(jsonGame);
    }

    std::ofstream outputFile(FILE_NAME);
    if (outputFile.is_open()) {
        Json::StreamWriterBuilder writer;
        std::string jsonString = Json::writeString(writer, jsonGames);
        outputFile << jsonString;
        outputFile.close();
    }
}

Player SaveLoadManager::createPlayerFromJson(const Json::Value& jsonPlayer) {
    bool isAI = jsonPlayer["isAI"].asBool();
    Player player = Player(jsonPlayer["color"].asString(), isAI);
    Timer* timer = createTimerFromJson(jsonPlayer["timer"]);
    player.setTimer(timer);
    return player;
}

Timer* SaveLoadManager::createTimerFromJson(const Json::Value& jsonTimer) {
    Timer* timer = new Timer();
    timer->setIsRunning(jsonTimer["isRunning"].asBool());
    timer->setInitialDuration(std::chrono::minutes(jsonTimer["initialDuration"].asInt()));
    timer->setRemainingTime(std::chrono::seconds(jsonTimer["remainingTime"].asInt()));
    return timer;
}

ChessPiece* SaveLoadManager::createChessPieceFromTypeAndColor(std::string type, std::string color, int row, int col) {
    if (type == "P") {
        return new Pawn(row, col, color);
    }
    else if (type == "R") {
        return new Rook(row, col, color);
    }
    else if (type == "N") {
        return new Knight(row, col, color);
    }
    else if (type == "B") {
        return new Bishop(row, col, color);
    }
    else if (type == "Q") {
        return new Queen(row, col, color);
    }
    else if (type == "K") {
        return new King(row, col, color);
    }
    return nullptr;
}

void SaveLoadManager::loadGamesFromFile() {
    std::ifstream inputFile(FILE_NAME);
    if (inputFile.is_open()) {
        games.clear();

        Json::CharReaderBuilder reader;
        Json::Value jsonGames;
        JSONCPP_STRING jsonStr;
        Json::parseFromStream(reader, inputFile, &jsonGames, &jsonStr);

        for (const Json::Value& jsonGame : jsonGames) {
            GameSaveLoad gameToLoadFrom;

            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    Json::Value jsonPiece = jsonGame["chessBoard"][i][j];
                    if (!jsonPiece.isNull()) {
                        std::string pieceType = jsonPiece["type"].asString();
                        std::string color = jsonPiece["color"].asString();
                        ChessPiece* piece = createChessPieceFromTypeAndColor(pieceType, color, i, j);
                        gameToLoadFrom.board[i][j] = piece;
                    }
                    else {
                        gameToLoadFrom.board[i][j] = nullptr;
                    }
                }
            }

            gameToLoadFrom.player1 = createPlayerFromJson(jsonGame["player1"]);
            gameToLoadFrom.player2 = createPlayerFromJson(jsonGame["player2"]);
            gameToLoadFrom.timeOfSaving = jsonGame["timeOfSaving"].asString();
            gameToLoadFrom.currentPlayerColor = jsonGame["currentPlayerColor"].asString();
            gameToLoadFrom.gameOver = jsonGame["gameOver"].asBool();
            games.push_back(gameToLoadFrom);
        }

        inputFile.close();
    }

    if (savedNewGameCallback) {
        savedNewGameCallback();
    }
}

