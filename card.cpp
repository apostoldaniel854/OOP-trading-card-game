#include "card.h"
#include <iostream>

Card::Card(std::string name, int manaCost, int type) : name(name), manaCost(manaCost), type(type){};
Card::Card() : name("placeholder"), manaCost(0), type(0){};

int Card::getManaCost() {
    return manaCost;
}

int Card::getType() {
    return type;
}

std::string Card::getName() {
    return name;
}

void Card::setManaCost(int manaCost) {
    this->manaCost = manaCost;
}

void Card::setType(int type) {
    this->type = type;
}

void Card::setName(std::string name) {
    this->name = name;
}

std::ostream& operator << (std::ostream& out, Card& card) {
    out << card.getName() << "\n";
    out << "Mana cost: " << card.getManaCost() << "\n";
    return out;
}