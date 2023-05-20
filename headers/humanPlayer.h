#pragma once
#include "player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(std::string  name, bool friendly, int health, const Deck& deck);
    void playTurn(int turn, Board& board, const std::shared_ptr <Player> &opponent) override;
    static void showCommands();
    ~HumanPlayer() override = default;
};