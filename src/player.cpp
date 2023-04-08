#include "../headers/player.h"

#include <utility>


Player::Player(std::string  name, bool friendly, int health, Deck deck) : name(std::move(name)), friendly(friendly), mana(0), health(health), hand(Hand()), deck(deck) {
    for (int i = 0; i < 3; i++) 
        hand.drawCard(deck.drawCard());
}

std::ostream &operator<<(std::ostream &out, const Player &player) {
    out << "-----------------" <<  player.name << "-------------------------\n";
    out << "Health: " << player.health << "\n";
    out << player.hand << "\n";
    return out;
}

void Player::endTurn(int turn) {
    static int fatigueDamage = 0;
    mana = std::max(MAX_MANA, turn);
    Card drawnCard = deck.drawCard();
    if (drawnCard.getName() == FATIGUE_CARD_NAME) {
        fatigueDamage++;
        this->health -= fatigueDamage;
        return;
    }
    hand.drawCard(drawnCard);
}

Card Player::playRandomCard() {
    return this->hand.playRandomCard(this->mana);
}

bool Player::getFriendly() const {
    return friendly;
}


