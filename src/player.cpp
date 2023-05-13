#include "../headers/player.h"

#include <utility>

Player::Player(std::string  name, bool friendly, int health, Deck deck) : name(std::move(name)), friendly(friendly), mana(DEFAULT_MANA), health(health), hand(Hand()), deck(deck) {
    for (int i = 0; i < START_HAND_SIZE; i++)
        hand.drawCard(deck.drawCard());
}

std::ostream &operator<<(std::ostream &out, const Player &player) {
    out << "-------------" <<  player.name << "----------------\n";

    delay(0.5);
    out << "Health: " << player.health << "\n";
    out << player.hand << "\n";
    return out;
}

void Player::endTurn() {
    static auto fatigueDamage = 0;
    Card drawnCard = deck.drawCard();
    if (drawnCard.getType() == SPECIAL_CARD) {
        fatigueDamage++;
        this->health -= fatigueDamage;
        return;
    }
    hand.drawCard(drawnCard);
}

Card Player::playRandomCard() {
    std::cout << this->name << ":\n";
    return this->hand.playRandomCard(this->mana);
}

bool Player::getFriendly() const {
    return friendly;
}

void Player::startTurn(int turn) {
    mana = std::min(MAX_MANA, turn);
}

int Player::getHealth() const {
    return this->health;
}

void Player::takeDamage(int damage) {
    this->health -= damage;
}
Hand & Player::getHand() {
    return this->hand;
}

int &Player::getMana() {
    return this->mana;
}


