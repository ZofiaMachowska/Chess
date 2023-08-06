#include "SavingGameController.h"

Json::Value SavingGameController::playerToJson(Player* player) const {
    Json::Value jsonPlayer;
    jsonPlayer["color"] = player->getColor();
    jsonPlayer["isActive"] = player->checkIsActive();
    jsonPlayer["isAI"] = player->isPlayerAI();
    return jsonPlayer;
}

void SavingGameController::saveGameToFile(int board[][8], std::vector<Player*> players, const std::string & fileName) {
    Json::Value jsonGame;

    // Serializacja stanu planszy
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            jsonGame["chessBoard"][i][j] = board[i][j];
        }
    }

    // Serializacja graczy
    jsonGame["whitePlayer"] = playerToJson(players[0]);
    jsonGame["blackPlayer"] = playerToJson(players[1]);

    std::ofstream outputFile(fileName);
    if (outputFile.is_open()) {
        Json::StreamWriterBuilder writer;
        std::string jsonString = Json::writeString(writer, jsonGame);
        outputFile << jsonString;
        outputFile.close();
        std::cout << "Stan gry zosta³ zapisany do pliku: " << fileName << std::endl;
    }
    else {
        std::cout << "B³¹d podczas zapisu do pliku." << std::endl;
    }
}