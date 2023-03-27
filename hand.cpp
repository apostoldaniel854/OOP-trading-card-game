#include "hand.h"
#include "card.h"
#include <iostream>

void Hand::drawCard(const Card& card) {
    cards.push_back(card);
}

std::vector <Card> Hand::getCardsInHand() {
    return cards;
}

std::ostream& operator << (std::ostream& out, Hand& hand) {
    out << "Cards in hand:\n";
    for (Card& card : hand.getCardsInHand()) {
        out << "-> ";
        out << card << "\n";
    }
    return out;
}
