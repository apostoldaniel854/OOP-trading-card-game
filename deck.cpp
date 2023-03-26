#include "deck.h"
#include "hand.h"
#include "card.h"
#include <vector>


Deck::Deck(int numCards) {
    for (int i = 0; i < numCards; i++) {
        cards.push_back(Card());
    }
}

Card Deck::drawCard() {
    Card card = cards.back();
    cards.pop_back();
    return card;
}