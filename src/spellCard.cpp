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
    std::string answer;
    std::cin >> answer;
    while (not isNumber(answer)) {
        std::cout << "Please enter a valid number" << std::endl;
        std::cin >> answer;
    }
    int idx = stoi(answer);
    while (idx < OPPONENT_TARGET || (friendly && idx > (int)board.getEnemyMinions().size()) || (!friendly && idx > (int)board.getFriendlyMinions().size())) {
        std::cout << "Invalid target chosen. Try again." << std::endl;
        std::cin >> answer;
        while (not isNumber(answer)) {
            std::cout << "Please enter a valid number" << std::endl;
            std::cin >> answer;
        }
        idx = stoi(answer);
    }
    if (idx == OPPONENT_TARGET) {
        return true;
    }
    idx--;
    board.damageMinion(idx, damage, !friendly);
    return false;
}