#include "../headers/minionCard.h"

MinionCard::MinionCard(std::string  name, int manaCost, int type, int health, int attack) : Card(std::move(name), manaCost, type), health(health), attack(attack){}

int MinionCard::getHealth() const {
    return health;
}
int MinionCard::getAttack() const {
    return attack;
}

std::shared_ptr<Card> MinionCard::clone() const {
    return std::make_shared<MinionCard>(name, manaCost, type, health, attack);
}
