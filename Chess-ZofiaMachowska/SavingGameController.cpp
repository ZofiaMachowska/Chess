#include "SavingGameController.h"

SavingGameController::~SavingGameController() {

}

std::vector<Game> SavingGameController::getGames() {
    return games;
}

Json::Value SavingGameController::timerToJson(Timer* timer) const {
    Json::Value jsonTimer;
    jsonTimer["isRunning"] = timer->isRunning;
    jsonTimer["initialDuration"] = timer->initialDuration.count();
    jsonTimer["elapsedTime"] = timer->elapsedTime.count();
    jsonTimer["remainingTime"] = timer->remainingTime.count();
    jsonTimer["timeAtStop"] = timer->timeAtStop.count();
    return jsonTimer;
}

Json::Value SavingGameController::playerToJson(Player* player) const {
    Json::Value jsonPlayer;
    jsonPlayer["color"] = player->getColor();
    jsonPlayer["isActive"] = player->checkIsActive();
    jsonPlayer["isAI"] = player->isPlayerAI();
    jsonPlayer["timer"] = timerToJson(player->timer);
    return jsonPlayer;
}

void  SavingGameController::setSaveNewGameCallback(std::function<void()> callback) {
    savedNewGameCallback = std::move(callback);
}

void SavingGameController::addNewGameToHistory(int board[][8], std::vector<Player*> players, bool gameOver) {
    auto currentTime = std::chrono::system_clock::now();
    std::time_t timestamp = std::chrono::system_clock::to_time_t(currentTime);
    std::tm timeinfo;
    localtime_s(&timeinfo, &timestamp);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);
    std::string readableTime(buffer);

    Game game;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            game.board[i][j] = board[i][j];
        }
    }
    game.player1 = players[0];
    game.player2 = players[1];
    game.timeOfSaving = readableTime;
    game.gameOver = gameOver;
    games.insert(games.begin(), game);
    if (games.size() > MAX_GAME_HISTORY) {
        games.erase(games.begin() + MAX_GAME_HISTORY, games.end());
    }
    if (savedNewGameCallback) {
        savedNewGameCallback();
    }
}

void SavingGameController::saveGameToFile() {
    Json::Value jsonGames;
    for (const Game game : games) {
        Json::Value jsonGame;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                jsonGame["chessBoard"][i][j] = game.board[i][j];
            }
        }
        jsonGame["whitePlayer"] = playerToJson(game.player1);
        jsonGame["blackPlayer"] = playerToJson(game.player2);
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

Player* SavingGameController::createPlayerFromJson(const Json::Value& jsonPlayer) {
    std::string color = jsonPlayer["color"].asString();
    bool isActive = jsonPlayer["isActive"].asBool();
    bool isAI = jsonPlayer["isAI"].asBool();
    Player* player = new Player(color, isActive, isAI);
    player->timer =  createTimerFromJson(jsonPlayer["timer"]);

    return player;
}

Timer* SavingGameController::createTimerFromJson(const Json::Value& jsonTimer) {
    Timer* timer = new Timer();

    timer->isRunning = jsonTimer["isRunning"].asBool();
    int initial_duration_seconds = jsonTimer["initialDuration"].asInt();
    timer->initialDuration = std::chrono::seconds(initial_duration_seconds);
    int elapsed_time_seconds = jsonTimer["elapsedTime"].asInt();
    timer->elapsedTime = std::chrono::seconds(elapsed_time_seconds);
    int remaining_time_seconds = jsonTimer["remainingTime"].asInt();
    timer->remainingTime = std::chrono::seconds(remaining_time_seconds);
    int timeAtStop_seconds = jsonTimer["timeAtStop"].asInt();
    timer->timeAtStop = std::chrono::seconds(timeAtStop_seconds);

    return timer;
}

void SavingGameController::loadGamesFromFile() {
    std::ifstream inputFile(FILE_NAME);
    if (inputFile.is_open()) {
        games.clear();

        Json::CharReaderBuilder reader;
        Json::Value jsonGames;
        JSONCPP_STRING jsonStr;
        Json::parseFromStream(reader, inputFile, &jsonGames, &jsonStr);

        for (const Json::Value& jsonGame : jsonGames) {
            Game game;
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    game.board[i][j] = jsonGame["chessBoard"][i][j].asInt();
                }
            }
            game.player1 = createPlayerFromJson(jsonGame["whitePlayer"]);
            game.player2 = createPlayerFromJson(jsonGame["blackPlayer"]);
            game.timeOfSaving = jsonGame["timeOfSaving"].asString();
            game.gameOver = jsonGame["gameOver"].asBool();
            games.push_back(game);
        }
        inputFile.close();
    }
    if (savedNewGameCallback) {
        savedNewGameCallback();
    }
}
