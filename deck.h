#include "hand.h"
#include <vector>

class Deck {
private:
    std::vector <Card> cards;
public:
    Deck(int numCards);
    Card drawCard();
};