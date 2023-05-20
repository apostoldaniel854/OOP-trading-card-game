#pragma once

#include <ostream>
#include "card.h"
#include "board.h"
#include "deck.h"
#include "minion.h"
#include "player.h"
#include "humanPlayer.h"
#include "computerPlayer.h"
#include "utils.h"
#include <typeinfo>

class Game {
private:
    Board board;
    std::shared_ptr<Player> player1, player2;
    void showState(int turn);
public:
    Game();

    friend std::ostream& operator << (std::ostream& out, const Game& game);

    void run();

    bool isGameOver();

    static void showDraw();

    static void showLose();

    static void showWin();

};