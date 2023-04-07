#include "board.h"

const std::vector <Minion>& Board::getFriendlyMinions() const{
     return friendlyMinions;
}

const std::vector<Minion> &Board::getEnemyMinions() const {
    return enemyMinions;
}

void Board::addMinionToBoard(Minion minion, bool friendly) {
    if (friendly) {
        friendlyMinions.push_back(minion);
    } else {
        enemyMinions.push_back(minion);
    }
}

 std::ostream& operator << (std::ostream& out, const Board& board) {
    //for (const Minion& minion : board.getFriendlyMinions())
     //   out << minion << "\n";
   // for (const Minion& minion : board.getEnemyMinions())
   //     out << minion << "\n";
   return out;
}
