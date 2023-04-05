#include "board.h"

const std::vector <Minion>& Board::getFriendlyMinions() const{
    return friendlyMinions;
}

void Board::addMinionToBoard(Minion minion, bool friendly) {
    if (friendly) {
        friendlyMinions.push_back(minion);
    } else {
        enemyMinions.push_back(minion);
    }
}

std::ostream& operator << (std::ostream& out, const Board& board) {
   // for (const Minion& minion : board.getFriendlyMinions())
     //   std::cout << minion << "\n";
   // for (const Minion& minion : board.getEnemyMinions())
   //     std::cout << minion << "\n";
}