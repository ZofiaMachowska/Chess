#include "shared.h"

bool isOnBoard(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}