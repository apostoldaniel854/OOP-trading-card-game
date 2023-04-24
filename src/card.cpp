#include "../headers/card.h"
#include <iostream>
#include <utility>

Card::Card(std::string  name, int manaCost, int type) : name(std::move(name)), manaCost(manaCost), type(type){}
Card::Card() : name("Wisp"), manaCost(0), type(MINION_CARD){}

int Card::getManaCost() const {
    return manaCost;
}

int Card::getType() const {
    return type;
}

const std::string& Card::getName() const {
    return name;
}
std::ostream& operator << (std::ostream& out, const Card& card) {
    out << card.getName() << "\n";
    out << "Mana cost: " << card.getManaCost() << "\n";
    return out;
}