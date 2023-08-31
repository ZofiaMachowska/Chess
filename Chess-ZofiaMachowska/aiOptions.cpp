#include "aiOptions.h"

aiOptions::aiOptions() : firstPlayerAi(false), secondPlayerAi(false) {}

void aiOptions::setFirstPlayerAi(bool value) {
    firstPlayerAi = value;
}

void aiOptions::setSecondPlayerAi(bool value) {
    secondPlayerAi = value;
}

bool aiOptions::getFirstPlayerAi() const {
    return firstPlayerAi;
}

bool aiOptions::getSecondPlayerAi() const {
    return secondPlayerAi;
}

