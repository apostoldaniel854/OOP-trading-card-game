#include "../headers/board.h"
#include "../headers/exceptions/invalidMinion.h"

const std::vector <Minion>& Board::getFriendlyMinions() const{
     return friendlyMinions;
}

const std::vector<Minion>& Board::getEnemyMinions() const {
    return enemyMinions;
}

void Board::setFriendlyMinions(const std::vector<Minion> &_friendlyMinions) {
    Board::friendlyMinions = _friendlyMinions;
}

void Board::setEnemyMinions(const std::vector<Minion> &_enemyMinions) {
    Board::enemyMinions = _enemyMinions;
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

void Board::attackMinion(int attackerId, int defenderId, bool friendly) {
    if (friendly) {
        if (attackerId < 0 || attackerId >= (int) friendlyMinions.size())
            throw InvalidMinion(attackerId);
        if (defenderId < 0 || defenderId >= (int) enemyMinions.size())
            throw InvalidMinion(defenderId);
        if (friendlyMinions[attackerId].hasAlreadyAttacked())
            throw InvalidMinion(attackerId);
        friendlyMinions[attackerId].attackMinion(enemyMinions[defenderId]);
        friendlyMinions[attackerId].setAlreadyAttacked(true);
        if (friendlyMinions[attackerId].isDead())
            friendlyMinions.erase(friendlyMinions.begin() + attackerId);
        if (enemyMinions[defenderId].isDead())
            enemyMinions.erase(enemyMinions.begin() + defenderId);
    }
    else {
        if (attackerId < 0 || attackerId >= (int) enemyMinions.size())
            throw InvalidMinion(attackerId);
        if (defenderId < 0 || defenderId >= (int) friendlyMinions.size())
            throw InvalidMinion(defenderId);
        if (enemyMinions[attackerId].hasAlreadyAttacked())
            throw InvalidMinion(attackerId);
        enemyMinions[attackerId].attackMinion(friendlyMinions[defenderId]);
        enemyMinions[attackerId].setAlreadyAttacked(true);
        if (enemyMinions[attackerId].isDead())
            enemyMinions.erase(enemyMinions.begin() + attackerId);
        if (friendlyMinions[defenderId].isDead())
            friendlyMinions.erase(friendlyMinions.begin() + defenderId);
    }
}

Minion Board::getMinionById(int id, bool friendly) {
    if (friendly) {
        if (id < 0 || id >= (int) friendlyMinions.size())
            throw InvalidMinion(id);
        return friendlyMinions[id];
    } else {
        if (id < 0 || id >= (int) enemyMinions.size())
            throw InvalidMinion(id);
        return enemyMinions[id];
    }
}

void Board::damageMinion(int minionId, int damage, bool friendly) {
    if (friendly) {
        if (minionId < 0 || minionId >= (int) friendlyMinions.size())
            throw InvalidMinion(minionId);
        friendlyMinions[minionId].damageMinion(damage);
        if (friendlyMinions[minionId].isDead())
            friendlyMinions.erase(friendlyMinions.begin() + minionId);
    } else {
        if (minionId < 0 || minionId >= (int) enemyMinions.size())
            throw InvalidMinion(minionId);
        enemyMinions[minionId].damageMinion(damage);
        if (enemyMinions[minionId].isDead())
            enemyMinions.erase(enemyMinions.begin() + minionId);
    }
}