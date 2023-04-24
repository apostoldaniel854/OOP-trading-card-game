#include "../headers/game.h"

Game::Game() : board(), player1("Player1", IS_FRIENDLY, MAX_HEALTH, Deck(MAX_DECK_SIZE)), player2("Player2", IS_NOT_FRIENDLY, MAX_HEALTH, Deck(MAX_DECK_SIZE)) {}

void Game::showState(int turn) {
    std::cout << "-------------" << "TURN " << turn << "-----------------\n";
    delay(1);
    std::cout << board << "\n";
    delay(1);
    std::cout << player1 << "\n";
    delay(1);
    std::cout << player2 << "\n";
}

void Game::run() {
    std::cout << Deck(MAX_DECK_SIZE) << "\n"; /// test required for hw 1
    int turn = 1;
    while (turn <= MAX_TURNS) {
        delay(1);
        showState(turn);
        /// FRIENDLY TURN
        delay(1);
        playFriendlyTurn(turn);
        if (isGameOver())
            return;
        /// ENEMY TURN
        delay(1);
        playEnemyTurn(turn);
        if (isGameOver())
            return;
        turn++;
    }
    std::cout << "---------TURN LIMIT EXCEEDED---------\n";
    showDraw();
}

std::ostream& operator << (std::ostream& out, const Game& game) {
    out << "-------------NEW GAME---------------\n";
    delay(1);
    out << game.board << "\n";
    out << game.player1 << "\n";
    out << game.player2 << "\n";
    return out;
}

void Game::playEnemyTurn(int turn) {
    player2.startTurn(turn);
    Card playedCard2 = player2.playRandomCard();
    if (playedCard2.getName() != EMPTY_CARD_NAME)
        board.addMinionToBoard(Minion(playedCard2.getName()), player2.getFriendly());
    player2.endTurn();
}

void Game::playFriendlyTurn(int turn) {
    player1.startTurn(turn);
    Card playedCard1 = player1.playRandomCard();
    if (playedCard1.getName() != EMPTY_CARD_NAME)
        board.addMinionToBoard(Minion(playedCard1.getName()), player1.getFriendly());
    player1.endTurn();
}

bool Game::isGameOver() {
    bool deadF = (player1.getHealth() < 0), deadE = (player2.getHealth() < 0);
    if (deadF && deadE) {
        showDraw();
        return true;
    }
    if (deadF) {
        showLose();
        return true;
    }
    if (deadE) {
        showWin();
        return true;
    }

    return false;
}

void Game::showDraw() {
    std::cout << "---------GAME ENDED IN A DRAW--------\n";

}

void Game::showLose() {
    std::cout << "-----YOU WERE KILLED - YOU LOSE------\n";
}

void Game::showWin() {
    std::cout << "-YOU KILLED THE ENEMY HERO - YOU WIN-\n";
}
