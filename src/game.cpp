#include "../headers/game.h"
#include <chrono>
#include <thread>

Game::Game() : board(), player1("Player1", IS_FRIENDLY, MAX_HEALTH, Deck(MAX_DECK_SIZE)), player2("Player2", IS_NOT_FRIENDLY, MAX_HEALTH, Deck(MAX_DECK_SIZE)) {}

void Game::showState(int turn) {
    std::cout << "----------------" << "Turn " << turn << "---------------\n";
    std::cout << board << "\n";
    std::cout << player1 << "\n";
    std::cout << player2 << "\n";
}

void Game::run() {
    std::cout << Deck(MAX_DECK_SIZE) << "\n"; /// test required for hw 1
    int turn = 1;
    while (turn <= 20) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        showState(turn);

        Card playedCard1 = player1.playRandomCard();
        if (playedCard1.getName() != EMPTY_CARD_NAME)
            board.addMinionToBoard(Minion(playedCard1.getName()), player1.getFriendly());
        player1.endTurn(turn);


        Card playedCard2 = player2.playRandomCard();
        if (playedCard2.getName() != EMPTY_CARD_NAME)
            board.addMinionToBoard(Minion(playedCard2.getName()), player2.getFriendly());
        player2.endTurn(turn);
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
