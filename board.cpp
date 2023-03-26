#include "board.h"

void Board::addMinionToBoard(Minion minion, bool friendly) {
    if (friendly) {
        friendlyMinions.push_back(minion);
    } else {
        enemyMinions.push_back(minion);
    }
}