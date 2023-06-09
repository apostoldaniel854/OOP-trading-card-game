#pragma once

#include <ostream>
#include "hand.h"
#include "deck.h"
#include "board.h"
#include "utils.h"

class Player {
protected:
    std::string name;
    bool friendly;
    int mana;
    int health;
    Hand hand;
    Deck deck;
    int fatigueDamage = 0;
public:
    Player(std::string  name, bool friendly, int health, Deck deck);
    friend std::ostream &operator<<(std::ostream &out, const Player &player);

    void endTurn();

    std::shared_ptr<Card> playRandomCard();

    [[nodiscard]] bool getFriendly() const;
    [[nodiscard]] int getHealth() const;


    virtual void playTurn(int turn, Board& board, const std::shared_ptr <Player>& opponent) = 0;
    void startTurn(int turn, Board& board);
    void takeDamage(int damage);
    static bool isGameOver(const std::shared_ptr<Player>& player);

    int &getMana();
    [[nodiscard]] const Hand &getHand() const;

    virtual ~Player() = default;
};
