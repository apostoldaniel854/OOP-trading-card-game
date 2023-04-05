#include "card.h"
#include <iostream>

Card::Card(std::string name, int manaCost, int type) : name(name), manaCost(manaCost), type(type){};
Card::Card() : name("placeholder"), manaCost(0), type(0){};

int Card::getManaCost() const {
    return manaCost;
}

int Card::getType() {
    return type;
}

std::string Card::getName() const {
    return name;
}
std::ostream& operator << (std::ostream& out, const Card& card) {
    out << card.getName() << "\n";
    out << "Mana cost: " << card.getManaCost() << "\n";
    return out;
}