#include "game.h"
#include <unistd.h>

Game::Game() : board(), player1("Player1", 30, Deck(30)), player2("Player2", 30, Deck(30)) {}

void Game::showState(int turn) {
    std::cout << "----------------" << "Turn " << turn << "---------------\n";
    std::cout << player1 << "\n";
    std::cout << board << "\n";
    std::cout << player2 << "\n";
}

void Game::run() {
    int turn = 1;
    while (true) {
        sleep(1);
        showState(turn);
        turn++;
        if (turn == 20)
            return;
    }
}