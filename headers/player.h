#pragma once

#include <ostream>
#include "hand.h"
#include "deck.h"
#include "board.h"
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

    void endTurn();

    std::shared_ptr<Card> playRandomCard();

    [[nodiscard]] bool getFriendly() const;
    [[nodiscard]] int getHealth() const;
    virtual void playTurn(int turn, Board& board, Player& opponent) = 0;
    void startTurn(int turn);
    void takeDamage(int damage);
    static bool isGameOver(const Player& opponent);
    Hand & getHand();

    int &getMana();
};
