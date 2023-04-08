#include "../headers/deck.h"


Deck::Deck(int numCards) {
    for (int i = 0; i < numCards; i++) {
        cards.emplace_back();
    }
}

Card Deck::drawCard() {
    Card card = cards.back();
    cards.pop_back();
    return card;
}