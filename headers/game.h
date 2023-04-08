#pragma once
#include "card.h"
#include "board.h"
#include "deck.h"
#include "minion.h"
#include "player.h"

class Game {
private:
    Board board;
    Player player1;
    Player player2;
    void showState(int turn);
public:
    Game();
    void run();
};