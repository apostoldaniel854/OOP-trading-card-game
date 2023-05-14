#pragma once
#include "card.h"
#include "board.h"
#include "utils.h"
#include <iostream>
#include <algorithm>
#include <vector>

class Hand {
private:
    std::vector<std::shared_ptr<Card>> cards;
public:
    Hand()= default;
    Hand(const Hand& hand);
    ~Hand();
    void drawCard(const std::shared_ptr<Card>& card);
    friend std::ostream& operator << (std::ostream& out, const Hand& hand);
    [[nodiscard]] const std::vector <std::shared_ptr<Card>>& getCardsInHand() const;
    Hand& operator = (const Hand& hand);

    std::shared_ptr<Card> playRandomCard(int &mana);
    std::shared_ptr<Card> playCard(const std::string &cardName, int &mana);
};