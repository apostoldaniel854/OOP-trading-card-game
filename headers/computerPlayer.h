#pragma once
#include "player.h"

class ComputerPlayer : public Player {
public:
    ComputerPlayer(std::string  name, bool friendly, int health, const Deck& deck);
    void playTurn(int turn, Board& board, const std::shared_ptr<Player>& opponent) override;
    ~ComputerPlayer() override = default;
};