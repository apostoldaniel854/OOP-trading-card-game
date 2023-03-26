#include "card.h"

Card::Card(int manaCost, int type) : manaCost(manaCost), type(type){};
Card::Card() : manaCost(0), type(0){};

int Card::getManaCost() {
    return manaCost;
}

int Card::getType() {
    return type;
}

void Card::setManaCost(int manaCost) {
    this->manaCost = manaCost;
}

void Card::setType(int type) {
    this->type = type;
}