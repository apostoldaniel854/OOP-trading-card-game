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
    for (const std::shared_ptr<Card>& card : hand.getCardsInHand())
        cards.emplace_back(card);
}

Hand& Hand::operator = (const Hand& hand) {
    if (this == &hand)
        return *this;
    cards.clear();
    for (const std::shared_ptr<Card>& card : hand.getCardsInHand())
        cards.emplace_back(card);
    return *this;
}

std::shared_ptr<Card> Hand::playRandomCard(int &mana) {
    std::shared_ptr<Card> emptyCard(new Card(EMPTY_CARD_NAME, 0, MINION_CARD));
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


bool Hand::playCard(const std::string& cardName, int& mana) {
    /// check if card is in hand
    for (auto it = cards.begin(); it != cards.end(); it++) {
        if ((*it)->getName() == cardName) {
            if ((*it)->getManaCost() <= mana) { /// we have enough mana to play it
                std::cout << "PLAYED " << (*it)->getName() << "\n";
                /// remove card from hand
                cards.erase(it);
                mana -= (*it)->getManaCost();
                return true;
            }
            return false;
        }
    }
    return false;
}
