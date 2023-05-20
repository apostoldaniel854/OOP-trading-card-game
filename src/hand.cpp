#include "../headers/hand.h"
#include <iostream>

void Hand::drawCard(const std::shared_ptr<Card> &card) {
    if (cards.size() < MAX_HAND_SIZE)
        cards.push_back(card);
    else
        std::cout << "WARNING: YOUR TOP CARD HAS BEEN BURNED\n";
}

const std::vector <std::shared_ptr<Card>>& Hand::getCardsInHand() const {
    return cards;
}

std::ostream& operator << (std::ostream& out, const Hand& hand) {
    out << "-----------CARDS IN HAND------------\n";
    delay(0.2);
    for (const std::shared_ptr<Card>& card : hand.getCardsInHand())
        out << *card;
    return out;
}


Hand::~Hand() {
    cards.clear();
}


Hand::Hand(const Hand& hand) {
    deepCopy(hand);
}

Hand& Hand::operator = (const Hand& hand) { /// deep copy assignment
    if (this != &hand) {
        deepCopy(hand);
    }
    return *this;
}
void Hand::deepCopy(const Hand& hand) {
    cards.clear();
    for (const std::shared_ptr<Card>& card : hand.getCardsInHand())
        cards.emplace_back(card->clone());
}

std::shared_ptr<Card> Hand::playRandomCard(int &mana) {
    std::shared_ptr<Card> emptyCard(new MinionCard(EMPTY_CARD_NAME, 0, MINION_CARD, 1, 1));
    if (cards.empty())
        return  emptyCard;
    int randomCardIndex = getRandomInteger(0, (int)cards.size() - 1);
    std::shared_ptr<Card> playedCard = cards[randomCardIndex];
    if (playedCard->getManaCost() <= mana) {
        std::cout << "PLAYED " << cards[randomCardIndex]->getName() << "\n";
        delay(1);
        mana -= playedCard->getManaCost();
        cards.erase(cards.begin() + randomCardIndex);
        return playedCard;
    }
    return emptyCard;
}


std::shared_ptr <Card> Hand::playCard(const std::string& cardName, int& mana) {
    /// check if card is in hand
    for (auto it = cards.begin(); it != cards.end(); it++) {
        std::shared_ptr<Card> card = *it;
        if (card != nullptr && card->getName() == cardName) {
            if (card->getManaCost() <= mana) { /// we have enough mana to play it
                std::cout << "PLAYED " << card->getName() << "\n";
                /// remove card from hand
                cards.erase(it);
                mana -= card->getManaCost();
                return card;
            }
            return nullptr;
        }
    }
    return nullptr;
}
