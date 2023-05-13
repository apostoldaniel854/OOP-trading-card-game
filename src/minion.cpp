#include <utility>
#include <iostream>

#include "../headers/minion.h"

Minion::Minion(std::string name, int health, int attack) : name(std::move(name)), health(health), attack(attack) {}
Minion::Minion() : name("Wisp"), health(1), attack(1) {}

/// getter for attack
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

Minion::Minion(const std::string& name)  : Minion(minionsCatalog.find(name)->second) {}

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

