#include <utility>
#include <iostream>

#include "../headers/minion.h"

Minion::Minion(std::string name, int health, int attack) : name(std::move(name)), health(health), attack(attack), alreadyAttacked(true) {}
Minion::Minion() : name("Wisp"), health(1), attack(0), alreadyAttacked(true) {}

int Minion::getAttack() const {
    return attack;
}


std::ostream& operator << (std::ostream& out, const Minion& minion) {
    out << "---------------MINION---------------\n";
    out << "Name: " << minion.getName() << " ";
    out << "H: " << minion.health << " ";
    out << "A: " << minion.attack << "\n";
    return out;
}

void Minion::attackMinion(Minion &minion) {
    minion.health -= this->attack;
    this->health -= minion.attack;
}

const std::string& Minion::getName() const {
    return name;
}

bool Minion::isDead() const {
    return health <= 0;
}

bool Minion::hasAlreadyAttacked() const {
    return alreadyAttacked;
}

void Minion::setAlreadyAttacked(bool _alreadyAttacked) {
    alreadyAttacked = _alreadyAttacked;
}
void Minion::damageMinion(int damage) {
    health -= damage;
    std::cout << "Minion " << name << " took " << damage << " damage\n";
}
