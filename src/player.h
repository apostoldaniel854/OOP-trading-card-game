#pragma once
#include "hand.h"
#include "deck.h"

class Player {
private:
    int health;
    Hand hand;
    Deck deck;
public:
    Player(int health, Deck deck);
    int getHealth();
};