#pragma once
#include "hand.h"
#include <vector>

class Deck {
private:
    std::vector <Card> cards;
public:
    explicit Deck(int numCards);
    Card drawCard();
    friend std::ostream& operator << (std::ostream& out, const Deck &deck);
};