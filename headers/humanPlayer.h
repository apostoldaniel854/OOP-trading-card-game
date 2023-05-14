#pragma once
#include "player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(std::string  name, bool friendly, int health, Deck deck);
    void playTurn(int turn, Board& board, Player& opponent) override;
    static void showCommands();
};