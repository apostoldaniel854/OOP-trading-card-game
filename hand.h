#include "card.h"
#include <vector>

class Hand {
    std::vector<Card> cards;
public:
    Hand(){};
    ~Hand(){};
    void drawCard(Card card);
};