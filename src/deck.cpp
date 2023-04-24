#include "../headers/deck.h"


Deck::Deck(int numCards) {
    for (int i = 0; i < numCards; i++) {
        cards.emplace_back(cardsCatalog[getRandomInteger(0, (int)cardsCatalog.size() - 1)]);
    }
}

Card Deck::drawCard() {
    if ((int)cards.size() > 0) {
        Card card = cards.back();
        cards.pop_back();
        return card;
    }
    return {FATIGUE_CARD_NAME, SPECIAL_CARD, 0};
}


std::ostream& operator << (std::ostream &out, const Deck &deck) {
    out << "---------------- DECK ---------------\n";
    delay(1);
    for (const Card& card : deck.cards)
        out << card;
    return out;
}