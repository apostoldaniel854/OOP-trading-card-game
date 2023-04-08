#include "hand.h"
#include "card.h"
#include <iostream>

void Hand::drawCard(const Card& card) {
    cards.push_back(card);
}

const std::vector <Card>& Hand::getCardsInHand() const {
    return cards;
}

std::ostream& operator << (std::ostream& out, const Hand& hand) {
    out << "Cards in hand:\n";
    for (const Card& card : hand.getCardsInHand())
        out << card;
    return out;
}
