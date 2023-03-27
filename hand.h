#include "card.h"
#include <iostream>
#include <vector>

class Hand {
    std::vector<Card> cards;
public:
    Hand(){};
    ~Hand(){};
    void drawCard(const Card& card);
    friend std::ostream& operator << (std::ostream& out, Hand& hand);
    std::vector <Card> getCardsInHand();
};