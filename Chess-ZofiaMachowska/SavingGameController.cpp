#include "SavingGameController.h"

std::vector<Game> SavingGameController::getGames() {
    return games;
}

void  SavingGameController::setSaveNewGameCallback(std::function<void()> callback) {
    savedNewGameCallback = std::move(callback);
}

Json::Value SavingGameController::timerToJson(Timer* timer) const {
    Json::Value jsonTimer;
    jsonTimer["is_running"] = timer->is_running;
    jsonTimer["initial_duration"] = timer->initial_duration.count();
    jsonTimer["elapsed_time"] = timer->elapsed_time.count();
    jsonTimer["remaining_time"] = timer->remaining_time.count();
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

void SavingGameController::addNewGameToHistory(int board[][8], std::vector<Player*> players, bool gameOver) {
    auto currentTime = std::chrono::system_clock::now();
    std::time_t timestamp = std::chrono::system_clock::to_time_t(currentTime);
    Game game;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            game.board[i][j] = board[i][j];
        }
    }
    game.player1 = players[0];
    game.player2 = players[1];
    game.timestamp = timestamp;
    game.gameOver = gameOver;
    games.push_back(game);

    if (savedNewGameCallback) {
        savedNewGameCallback();
    }
}

void SavingGameController::saveGameToFile() {
    Json::Value jsonGames;
    for (const Game game : games) {
        Json::Value jsonGame;
        // Serializacja stanu planszy
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                jsonGame["chessBoard"][i][j] = game.board[i][j];
            }
        }

        // Serializacja graczy
        jsonGame["whitePlayer"] = playerToJson(game.player1);
        jsonGame["blackPlayer"] = playerToJson(game.player2);
        jsonGame["timestamp"] = game.timestamp;
        jsonGame["gameOver"] = game.gameOver;
        jsonGames.append(jsonGame);
    }
    std::ofstream outputFile(fileName);
    if (outputFile.is_open()) {
        Json::StreamWriterBuilder writer;
        std::string jsonString = Json::writeString(writer, jsonGames);
        outputFile << jsonString;
        outputFile.close();
        std::cout << "Stan gry zosta³ zapisany do pliku: " << fileName << std::endl;
    }
    else {
        std::cout << "B³¹d podczas zapisu do pliku." << std::endl;
    }
}

Player* SavingGameController::createPlayerFromJson(const Json::Value& jsonPlayer) {
    std::string color = jsonPlayer["color"].asString();
    bool isActive = jsonPlayer["isActive"].asBool();
    bool isAI = jsonPlayer["isAI"].asBool();
    Player* player = new Player(color, isActive, isAI); // Tworzenie nowego obiektu gracza
    player->timer =  createTimerFromJson(jsonPlayer["timer"]);

    return player;
}
//chyba powinno sie wniesc ja do klasy timer
Timer* SavingGameController::createTimerFromJson(const Json::Value& jsonTimer) {
    Timer* timer = new Timer();

    timer->is_running = jsonTimer["is_running"].asBool();
    int initial_duration_seconds = jsonTimer["initial_duration"].asInt();
    timer->initial_duration = std::chrono::seconds(initial_duration_seconds);
    int elapsed_time_seconds = jsonTimer["elapsed_time"].asInt();
    timer->elapsed_time = std::chrono::seconds(elapsed_time_seconds);
    int remaining_time_seconds = jsonTimer["remaining_time"].asInt();
    timer->remaining_time = std::chrono::seconds(remaining_time_seconds);
    int timeAtStop_seconds = jsonTimer["timeAtStop"].asInt();
    timer->timeAtStop = std::chrono::seconds(timeAtStop_seconds);

    return timer;
}


void SavingGameController::loadGamesFromFile() {
    std::ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        games.clear(); // Wyczyœæ wektor gier przed wczytaniem nowych gier

        Json::CharReaderBuilder reader;
        Json::Value jsonGames;
        JSONCPP_STRING jsonStr;
        Json::parseFromStream(reader, inputFile, &jsonGames, &jsonStr);

        for (const Json::Value& jsonGame : jsonGames) {
            Game game;

            // Deserializacja stanu planszy
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    game.board[i][j] = jsonGame["chessBoard"][i][j].asInt();
                }
            }

            // Deserializacja graczy
            game.player1 = createPlayerFromJson(jsonGame["whitePlayer"]);
            game.player2 = createPlayerFromJson(jsonGame["blackPlayer"]);
            game.timestamp = jsonGame["timestamp"].asString();
            game.gameOver = jsonGame["gameOver"].asBool();
            games.push_back(game);
        }

        inputFile.close();
        std::cout << "Gry zosta³y wczytane z pliku: " << fileName << std::endl;
    }
    else {
        std::cout << "B³¹d podczas odczytu pliku." << std::endl;
    }

    if (savedNewGameCallback) {
        savedNewGameCallback();
    }
}
