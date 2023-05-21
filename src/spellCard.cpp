#include "../headers/spellCard.h"

SpellCard::SpellCard(std::string  name, int manaCost, int type, int damage) : Card(std::move(name), manaCost, type), damage(damage) {}

int SpellCard::getDamage() const {
    return damage;
}

std::shared_ptr<Card> SpellCard::clone() const {
    return std::make_shared<SpellCard>(name, manaCost, type, damage);
}

bool SpellCard::playCard(Board &board, bool friendly) {
    std::cout << "Who do you want to target with this spell?" << std::endl;
    std::cout << "0 - Opponent\n" << std::endl;
    std::cout << "i - the ith enemy minion from left\n" << std::endl;
    int answer;
    std::cin >> answer;
    if (answer == OPPONENT_TARGET) {
        return true;
    }
    answer--;
    board.damageMinion(answer, damage, !friendly);
    return false;
}