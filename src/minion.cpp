#include <utility>

#include "../headers/minion.h"

Minion::Minion(std::string name, int health, int attack) : name(std::move(name)), health(health), attack(attack) {}




std::ostream& operator << (std::ostream& out, const Minion& minion) {
    out << "-----------------------MINION---------------\n";
    out << "Name: " << minion.getName() << " ";
    out << "Mana cost:" <<  minion.getManaCost() << "\n";
    out << "H: " << minion.health << " ";
    out << "A: " << minion.attack << "\n";
    return out;
}

Minion::Minion(const std::string& name)  : Minion(minionsCatalog.find(name)->second) {}

