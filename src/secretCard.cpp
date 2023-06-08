#include "../headers/secretCard.h"

SecretCard::SecretCard(std::string  name, int manaCost, int type, int duration) : Card(std::move(name), manaCost, type), duration(duration) {

}

int SecretCard::getDuration() const {
    return duration;
}

std::shared_ptr<Card> SecretCard::clone() const {
    return std::make_shared<SecretCard>(name, manaCost, type, duration);
}

bool SecretCard::playCard(Board &board, bool friendly) {
    if (friendly) {
        std::vector <Minion> enemyMinions;
        for (const Minion& minion : board.getEnemyMinions()) {
            Minion mutableMinion = minion;
            mutableMinion.damageMinion(duration);
            if (not mutableMinion.isDead())
                enemyMinions.push_back(mutableMinion);
        }
        board.setEnemyMinions(enemyMinions);
    }
    else {
        auto friendlyMinions = board.getFriendlyMinions();
        for (const Minion& minion : board.getFriendlyMinions()) {
            Minion mutableMinion = minion;
            mutableMinion.damageMinion(duration);
            if (not mutableMinion.isDead())
                friendlyMinions.push_back(mutableMinion);
        }
        board.setFriendlyMinions(friendlyMinions);
    }
    return true;
}