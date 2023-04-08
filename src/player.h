#pragma once

#include <ostream>
#include "hand.h"
#include "deck.h"

class Player {
private:
    std::string name;
    int health;
    Hand hand;
    Deck deck;
public:
    Player(std::string  name, int health, Deck deck);

    [[maybe_unused]] [[nodiscard]] int getHealth() const;

    friend std::ostream &operator<<(std::ostream &out, const Player &player);

};
