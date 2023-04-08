#include "../headers/minion.h"


std::map <std::string, Minion> minionsCatalog = {
        {"placeholder" , Minion("placeholder", 0, 1, 1) }
};

Minion::Minion(const std::string &name, int manaCost, int health, int attack) : Card(name, MINION_CARD, manaCost), health(health), attack(attack) {}




std::ostream& operator << (std::ostream& out, const Minion& minion) {
    out << "-----------------------MINION---------------\n";
    out << "Name: " << minion.getName() << " ";
    out << "Mana cost:" <<  minion.getManaCost() << "\n";
    out << "H: " << minion.health << " ";
    out << "A: " << minion.attack << "\n";
    return out;
}

Minion::Minion(const Card &card)  : Minion(minionsCatalog.find(card.getName())->second) {}

