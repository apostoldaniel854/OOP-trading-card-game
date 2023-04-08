#pragma once

#include <ostream>
#include "hand.h"
#include "deck.h"
#include "utils.h"

class Player {
private:
    std::string name;
    bool friendly;
    int mana;
    int health;
    Hand hand;
    Deck deck;
public:
    Player(std::string  name, bool friendly, int health, Deck deck);
    friend std::ostream &operator<<(std::ostream &out, const Player &player);

    void endTurn(int i);

    Card playRandomCard();

    [[nodiscard]] bool getFriendly() const;
};