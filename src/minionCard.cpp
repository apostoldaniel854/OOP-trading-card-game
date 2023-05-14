#include "../headers/minionCard.h"

MinionCard::MinionCard(std::string  name, int manaCost, int type, int health, int attack) : Card(std::move(name), manaCost, type), health(health), attack(attack){}

/// getter
int MinionCard::getHealth() const {
    return health;
}
int MinionCard::getAttack() const {
    return attack;
}

//
//bool MinionCard::playCard() {
//    board.addMinionToBoard(Minion(getName(), health, attack), friendly);
//}