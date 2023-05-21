#include "../headers/minionCard.h"

MinionCard::MinionCard(std::string  name, int manaCost, int type, int health, int attack) : Card(std::move(name), manaCost, type), health(health), attack(attack){}

std::shared_ptr<Card> MinionCard::clone() const {
    return std::make_shared<MinionCard>(name, manaCost, type, health, attack);
}

bool MinionCard::playCard(Board& board, bool friendly) {
    board.addMinionToBoard(Minion(name, health, attack), friendly);
    return false;
}