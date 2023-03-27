#include "card.h"
#include "minion.h"

Minion::Minion(std::string name, int manaCost, int type, int health, int attack) : Card(name, manaCost, type), health(health), attack(attack) {}

int Minion::getHealth() {
    return health;
}
int Minion::getAttack() {
    return attack;
}
void Minion::setHealth(int health) {
    this->health = health;
}
void Minion::setAttack(int attack) {
    this->attack = attack;
}
