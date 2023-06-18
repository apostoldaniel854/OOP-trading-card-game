#include "../headers/deck.h"

Deck::Deck(int numCards, const Deck& catalog) {
    for (int i = 0; i < numCards; i++) {
        if (getRandomInteger(0, 2) == 0)
            cards.emplace_back(CardFactory::createSpellCard(catalog.cards));
        else
           cards.emplace_back(CardFactory::createMinionCard(catalog.cards));
    }
}

std::shared_ptr<Card> Deck::drawCard() {
    if ((int)cards.size() > 0) {
        std::shared_ptr<Card> card = cards.back();
        cards.pop_back();
        return card;
    }
    return std::make_shared<MinionCard>(FATIGUE_CARD_NAME, SPECIAL_CARD, 0, 0, 0);
}


std::ostream& operator << (std::ostream &out, const Deck &deck) {
    out << "---------------- DECK ---------------\n";
    delay(0.2);
    for (const std::shared_ptr<Card>& card : deck.cards)
        out << *card;
    return out;
}

Deck& Deck::operator = (const Deck& deck) {
    if (this != &deck)
        deepCopy(deck);
    return *this;
}

Deck::Deck(const Deck& deck) {
    deepCopy(deck);
}

void Deck::deepCopy(const Deck& deck) {
    cards.clear();
    for (const std::shared_ptr<Card>& card : deck.cards) {
        cards.emplace_back(card->clone());
    }
}

void Deck::addCard(const std::shared_ptr<Card> &card) {
    cards.emplace_back(card);
}
