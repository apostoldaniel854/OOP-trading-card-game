#include "player.h"

#include <utility>
#include "deck.h"
#include "hand.h"
#include "card.h"


Player::Player(std::string  name, int health, Deck deck) : name(std::move(name)), health(health), hand(Hand()), deck(deck) {
    for (int i = 0; i < 3; i++) 
        hand.drawCard(deck.drawCard());
}

std::ostream &operator<<(std::ostream &out, const Player &player) {
    out << "-----------------" <<  player.name << "-------------------------\n";
    out << "Health: " << player.health << "\n";
    out << "Cards in hand:" << "\n";
    out << player.hand << "\n";
    return out;
}

[[maybe_unused]] int Player::getHealth() const {
    return health;
}

