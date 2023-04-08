#include "../headers/game.h"
#include <chrono>
#include <thread>

Game::Game() : board(), player1("Player1", 30, Deck(30)), player2("Player2", 30, Deck(30)) {}

void Game::showState(int turn) {
    std::cout << "----------------" << "Turn " << turn << "---------------\n";
    std::cout << board << "\n";
    std::cout << player1 << "\n";
    std::cout << player2 << "\n";
}

void Game::run() {
    int turn = 1;
    while (turn <= 20) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        showState(turn);
        turn++;
    }
}