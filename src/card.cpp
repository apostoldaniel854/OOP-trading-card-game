#include "card.h"
#include "minion.h"
#include <iostream>
#include <utility>

Card::Card(std::string  name, int manaCost, int type) : name(std::move(name)), manaCost(manaCost), type(type){}
Card::Card() : name("placeholder"), manaCost(0), type(0){}

int Card::getManaCost() const {
    return manaCost;
}

[[maybe_unused]] int Card::getType() const {
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