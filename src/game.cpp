#include "../headers/game.h"
//#include "../headers/secretCard.h"
Game::Game() : board() {
    std::cout << "CHOOSE GAME TYPE:\n";
    std::cout << "1. Player vs Player\n";
    std::cout << "2. Player vs AI\n";
    std::cout << "3. AI vs AI\n";
    int choice;
    std::cin >> choice;
    while (choice <= 0 || choice > 3) {
        std::cout << "Invalid choice. Try again.\n";
        std::cin >> choice;
    }

    if (choice == 1) {
        player1 = std::make_shared<HumanPlayer>("Player1", IS_FRIENDLY, MAX_HEALTH, Deck(MAX_DECK_SIZE));
        player2 = std::make_shared<HumanPlayer>("Player2", IS_NOT_FRIENDLY, MAX_HEALTH, Deck(MAX_DECK_SIZE));
    }
    else if (choice == 2) {
        player1 = std::make_shared<HumanPlayer>("Player1", IS_FRIENDLY, MAX_HEALTH, Deck(MAX_DECK_SIZE));
        player2 = std::make_shared<ComputerPlayer>("Player2", IS_NOT_FRIENDLY, MAX_HEALTH, Deck(MAX_DECK_SIZE));
    }
    else {
        player1 = std::make_shared<ComputerPlayer>("Player1", IS_FRIENDLY, MAX_HEALTH, Deck(MAX_DECK_SIZE));
        player2 = std::make_shared<ComputerPlayer>("Player2", IS_NOT_FRIENDLY, MAX_HEALTH, Deck(MAX_DECK_SIZE));
    }
}

void Game::showState(int turn) {
    std::cout << "-------------" << "TURN " << turn << "-----------------\n";
    delay(0.2);
    std::cout << board << "\n";
    delay(0.2);
    std::cout << player1->getHand() << "\n";
}

void Game::run() {
//    std::cout << Deck(MAX_DECK_SIZE) << "\n"; /// test required for hw 1
//    SecretCard secretCard("Secret", 0, SECRET_CARD, 2);
//    std::cout << secretCard.getDuration() << "\n";
    std::cout << "-------------NEW GAME---------------\n";
    int turn = 1;
    while (turn <= MAX_TURNS) {
        delay(1);
        showState(turn);

        /// FRIENDLY TURN
        delay(1);
        player1->playTurn(turn, board, player2);
        if (isGameOver())
            return;

        /// ENEMY TURN
        delay(1);
        player2->playTurn(turn, board, player1);
        if (isGameOver())
            return;
    //    std::cout << player1 << " " << player2 << "\n";
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




bool Game::isGameOver() {
    bool deadF = (player1->getHealth() <= 0), deadE = (player2->getHealth() <= 0);
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
