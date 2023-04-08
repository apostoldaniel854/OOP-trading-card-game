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
    std::cout << Deck(30) << "\n"; /// test required for hw 1
    int turn = 1;
    while (turn <= 20) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        showState(turn);
        turn++;
    }
}

std::ostream& operator << (std::ostream& out, const Game& game) {
    out << "----------------------NEW GAME-------------------\n";
    out << game.board << "\n";
    out << game.player1 << "\n";
    out << game.player2 << "\n";
    return out;
}
