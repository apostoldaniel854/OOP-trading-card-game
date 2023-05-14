#include "../headers/deck.h"


Deck::Deck(int numCards) {
    for (int i = 0; i < numCards; i++) {
        std::shared_ptr <Card> card = std::make_shared <MinionCard> (minionCardsCatalog[getRandomInteger(0, (int)minionCardsCatalog.size() - 1)]);
        cards.emplace_back(card);
    }
}

std::shared_ptr<Card> Deck::drawCard() {
    if ((int)cards.size() > 0) {
        std::shared_ptr<Card> card = cards.back();
        cards.pop_back();
        return card;
    }
    std::shared_ptr<Card> fatigueCard(new MinionCard(FATIGUE_CARD_NAME, SPECIAL_CARD, 0, 0, 0));
    return fatigueCard;
}


std::ostream& operator << (std::ostream &out, const Deck &deck) {
    out << "---------------- DECK ---------------\n";
    delay(0.2);
    for (const std::shared_ptr<Card>& card : deck.cards)
        out << *card;
    return out;
}