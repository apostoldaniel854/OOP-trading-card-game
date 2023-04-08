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


std::ostream& operator << (std::ostream &out, const Deck &deck) {
    out << "---------------- DECK -----------------\n";
    for (const Card& card : deck.cards)
        out << card;
    return out;
}