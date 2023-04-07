#include "game.h"

Game::Game() : board(), player1(30, Deck(30)), player2(30, Deck(30)) {};

void Game::showState() {
   // std::cout << player1 << "\n";
     std::cout << board << "\n";
  //  std::cout << player2 << "\n";
}

void Game::run() {
    while (true) {
        showState();
    }
}