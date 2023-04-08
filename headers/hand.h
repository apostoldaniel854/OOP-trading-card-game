#pragma once
#include "card.h"
#include <iostream>
#include <vector>

class Hand {
private:
    std::vector<Card> cards;
public:
    Hand()= default;
    ~Hand()= default;
    void drawCard(const Card& card);
    friend std::ostream& operator << (std::ostream& out, const Hand& hand);
    [[nodiscard]] const std::vector <Card>& getCardsInHand() const;
};