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
    out << "----------------BOARD---------------\n";
    out << "-------- PLAYER 1 MINIONS-----------\n";
    delay(0.5);
    if (board.getFriendlyMinions().empty())
        out << "NONE\n";
    for (const Minion& minion : board.getFriendlyMinions())
        out << minion;

    out << "\n";

    out << "-------- PLAYER 2 MINIONS-----------\n";
    delay(0.5);
    if (board.getEnemyMinions().empty())
         out << "NONE\n";
    for (const Minion& minion : board.getEnemyMinions())
         out << minion;
   return out;
}

bool Board::attackMinion(int attackerId, int defenderId, bool friendly) {
    if (attackerId < 0 || attackerId >= (int)friendlyMinions.size() || defenderId < 0 || defenderId >= (int)enemyMinions.size())
        return false;
    if (friendly) {
        friendlyMinions[attackerId].attackMinion(enemyMinions[defenderId]);
        if (friendlyMinions[attackerId].isDead())
            friendlyMinions.erase(friendlyMinions.begin() + attackerId);
        if (enemyMinions[defenderId].isDead())
            enemyMinions.erase(enemyMinions.begin() + defenderId);
    } else {
        enemyMinions[attackerId].attackMinion(friendlyMinions[defenderId]);
        if (enemyMinions[attackerId].isDead())
            enemyMinions.erase(enemyMinions.begin() + attackerId);
        if (friendlyMinions[defenderId].isDead())
            friendlyMinions.erase(friendlyMinions.begin() + defenderId);
    }
    return true;
}

Minion Board::getMinionById(int id, bool friendly) {
    if (friendly) {
        /// we will use try catch here
        try {
            if (id < 0 || id >= (int)friendlyMinions.size())
                throw std::out_of_range("Minion with this id does not exist");
            return friendlyMinions[id];
        }
        catch (std::out_of_range& e) {
            std::cout << e.what() << std::endl;
            return {};
        }
    } else {
        try {
            if (id < 0 || id >= (int)enemyMinions.size())
                throw std::out_of_range("Minion with this id does not exist");
            return enemyMinions[id];
        }
        catch (std::out_of_range& e) {
            std::cout << e.what() << std::endl;
            return {};
        }
    }
}