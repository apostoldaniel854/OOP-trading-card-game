#include "../headers/deck.h"


Deck::Deck(int numCards) {
    for (int i = 0; i < numCards; i++) {
        cards.emplace_back(new Card(cardsCatalog[getRandomInteger(0, (int)cardsCatalog.size() - 1)]));
    }
}

std::shared_ptr<Card> Deck::drawCard() {
    if ((int)cards.size() > 0) {
        std::shared_ptr<Card> card = cards.back();
        cards.pop_back();
        return card;
    }
    std::shared_ptr<Card> fatigueCard(new Card(FATIGUE_CARD_NAME, SPECIAL_CARD, 0));
    return fatigueCard;
}


std::ostream& operator << (std::ostream &out, const Deck &deck) {
    out << "---------------- DECK ---------------\n";
    delay(0.2);
    for (const std::shared_ptr<Card>& card : deck.cards)
        out << *card;
    return out;
}