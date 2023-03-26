#include "card.h"
#include "minion.h"

Minion::Minion(int manaCost, int type, int health, int attack) : Card(manaCost, type) {
    this->health = health;
    this->attack = attack;
}
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