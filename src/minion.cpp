#include "../headers/minion.h"

Minion::Minion(const std::string &name, int manaCost, int health, int attack) : Card(name, manaCost), health(health), attack(attack) {}



std::ostream& operator << (std::ostream& out, const Minion& minion) {
    out << "Name: " << minion.getName() << " ";
    out << "Mana cost:" <<  minion.getManaCost() << "\n";
    out << "H: " << minion.health << " ";
    out << "A: " << minion.attack << "\n";
    return out;
}