#pragma once
#include "card.h"
#include "board.h"
#include "deck.h"
#include "minion.h"
#include "player.h"
#include "spell.h"

class Game {
private:
    Player player1;
    Player player2;
    Board board;
    void showState();
public:
    Game();
    void run();
};