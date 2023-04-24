#include "../headers/board.h"

const std::vector <Minion>& Board::getFriendlyMinions() const{
     return friendlyMinions;
}

const std::vector<Minion>& Board::getEnemyMinions() const {
    return enemyMinions;
}

void Board::addMinionToBoard(const Minion& minion, bool friendly) {
    if (friendly) {
        friendlyMinions.emplace_back(minion);
    } else {
        enemyMinions.emplace_back(minion);
    }
}

 std::ostream& operator << (std::ostream& out, const Board& board) {
    out << "-------- PLAYER 1 MINIONS-----------\n";
    delay(1);
    if (board.getFriendlyMinions().empty())
        out << "NONE\n";
    for (const Minion& minion : board.getFriendlyMinions())
        out << minion;

    out << "\n";

    out << "-------- PLAYER 2 MINIONS-----------\n";
    delay(1);
    if (board.getEnemyMinions().empty())
         out << "NONE\n";
    for (const Minion& minion : board.getEnemyMinions())
         out << minion;
   return out;
}
