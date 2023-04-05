#include "player.h"
#include "deck.h"
#include "hand.h"
#include "card.h"
#include <vector>


Player::Player(int health, Deck deck) : hand(Hand()), deck(deck), health(health) {
    for (int i = 0; i < 3; i++) 
        hand.drawCard(deck.drawCard());
}

int Player::getHealth() {
    return health;
}

