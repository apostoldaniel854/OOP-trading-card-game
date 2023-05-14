#pragma once
#include "hand.h"
#include <vector>
#include <memory>

class Deck {
private:
    std::vector <std::shared_ptr<Card>> cards;
public:
    explicit Deck(int numCards);
    std::shared_ptr<Card> drawCard();
    friend std::ostream& operator << (std::ostream& out, const Deck &deck);
};