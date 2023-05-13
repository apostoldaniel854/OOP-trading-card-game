#include "../headers/hand.h"
#include <iostream>

void Hand::drawCard(const Card& card) {
    if (cards.size() < MAX_HAND_SIZE)
        cards.push_back(card);
    else
        std::cout << "WARNING: YOUR TOP CARD HAS BEEN BURNED\n";
}

const std::vector <Card>& Hand::getCardsInHand() const {
    return cards;
}

std::ostream& operator << (std::ostream& out, const Hand& hand) {
    out << "-----------CARDS IN HAND------------\n";
    delay(0.2);
    for (const Card& card : hand.getCardsInHand())
        out << card;
    return out;
}


Hand::~Hand() {
    cards.clear();
}

Hand::Hand(const Hand& hand) {
    for (const Card& card : hand.getCardsInHand())
        cards.emplace_back(card);
}

Hand& Hand::operator = (const Hand& hand) {
    if (this == &hand)
        return *this;
    cards.clear();
    for (const Card& card : hand.getCardsInHand())
        cards.emplace_back(card);
    return *this;
}

Card Hand::playRandomCard(int &mana) {
    if (cards.empty())
        return  {EMPTY_CARD_NAME, 0, MINION_CARD};
    int randomCardIndex = getRandomInteger(0, (int)cards.size() - 1);
    Card playedCard = cards[randomCardIndex];
    if (playedCard.getManaCost() <= mana) {
        std::cout << "PLAYED " << cards[randomCardIndex].getName() << "\n";
        delay(1);
        mana -= playedCard.getManaCost();
        cards.erase(cards.begin() + randomCardIndex);
        return playedCard;
    }
    return {EMPTY_CARD_NAME, 0, MINION_CARD};
}


bool Hand::playCard(const std::string& cardName, int& mana) {
    /// check if card is in hand
    for (auto it = cards.begin(); it != cards.end(); it++) {
        if (it->getName() == cardName) {
            if (it->getManaCost() <= mana) { /// we have enough mana to play it
                std::cout << "PLAYED " << it->getName() << "\n";
                /// remove card from hand
                cards.erase(it);
                mana -= it->getManaCost();
                return true;
            }
            return false;
        }
    }
    return false;
}
