#include "board.h"

const std::vector <Minion>& Board::getFriendlyMinions() const{
     return friendlyMinions;
}

const std::vector<Minion>& Board::getEnemyMinions() const {
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
    out << "Player 1 minions:\n";
    for (const Minion& minion : board.getFriendlyMinions())
        out << minion;
    out << "Player 2 minions:\n";
    for (const Minion& minion : board.getEnemyMinions())
         out << minion;
   return out;
}
