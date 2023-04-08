#pragma once

#include <ostream>
#include "card.h"
#include "board.h"
#include "deck.h"
#include "minion.h"
#include "player.h"
#include "utils.h"

class Game {
private:
    Board board;
    Player player1;
    Player player2;
    void showState(int turn);
public:
    Game();

    friend std::ostream& operator << (std::ostream& out, const Game& game);

    void run();
};