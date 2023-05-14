#include "../headers/game.h"

Game::Game() : board(), player1("Player1", IS_FRIENDLY, MAX_HEALTH, Deck(MAX_DECK_SIZE)), player2("Player2", IS_NOT_FRIENDLY, MAX_HEALTH, Deck(MAX_DECK_SIZE)) {}

void Game::showState(int turn) {
    std::cout << "-------------" << "TURN " << turn << "-----------------\n";
    delay(0.2);
    std::cout << board << "\n";
    delay(0.2);
    std::cout << player1.getHand() << "\n";
}

void Game::run() {
//    std::cout << Deck(MAX_DECK_SIZE) << "\n"; /// test required for hw 1
    std::cout << "-------------NEW GAME---------------\n";
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
    std::shared_ptr <Card> playedCard2 = player2.playRandomCard();
    if (playedCard2->getName() != EMPTY_CARD_NAME)
        board.addMinionToBoard(Minion(playedCard2->getName()), player2.getFriendly());
    player2.endTurn();
}

void Game::showCommands() {
    /// commands from README.md file Documentation section
    std::cout << "FULL LIST OF COMMANDS:\n";
    std::cout << "help - show this message\n";
    std::cout << "quit - quit the game\n";
    std::cout << "end_turn - end your turn\n";
    std::cout << "show_board - show the board\n";
    std::cout << "show_hand - show your hand\n";
    std::cout << "show_opponent - show opponent's health\n";
    std::cout << "show_player - show your health\n";
    std::cout << "play <card_name> - play a card from your hand\n";
    std::cout << "attack <attacker_id> <defender_id> - attack with a minion\n";
    std::cout << "go_face <attacker_id> - attack the opponent with a minion\n";
}

void Game::playFriendlyTurn(int turn) {
    player1.startTurn(turn);
    while (true) {
        /// get command from user
        std::string command;
        std::cin >> command;
        if (command == "play") {
            std::string cardName;
            std::cin >> cardName;
            std::shared_ptr <Card> card = player1.getHand().playCard(cardName, player1.getMana());
            if (card != nullptr) {
                /// dynamic cast for minion
                auto minionCard = std::dynamic_pointer_cast<MinionCard>(card);
                board.addMinionToBoard(Minion(*minionCard), player1.getFriendly());
            } else {
                std::cout << "Card is not playable. Try another one\n";
            }
        } else if (command == "attack") {
            int attackerId, defenderId;
            std::cin >> attackerId >> defenderId;
            bool verdict = board.attackMinion(attackerId, defenderId, player1.getFriendly());
            if (!verdict) {
                std::cout << "Invalid attack. Try another one\n";
            }
        } else if (command == "go_face") {
            int attackerId;
            std::cin >> attackerId;
            int damage = board.getMinionById(attackerId, player1.getFriendly()).getAttack();
            player2.takeDamage(damage);
            if (isGameOver())
                return;
        } else if (command == "end_turn") {
            std::cout << "Turn ended\n";
            player1.endTurn();
            return;
        } else if (command == "show_board") {
            std::cout << board << "\n";
        } else if (command == "show_hand") {
            std::cout << player1.getHand() << "\n";
        } else if (command == "show_player") {
            std::cout << "Your health: ";
            std::cout << player1.getHealth() << "\n";
        } else if (command == "show_opponent") {
            std::cout << "Enemy health: ";
            std::cout << player2.getHealth() << "\n";
        } else if (command == "help") {
            showCommands();
        } else if (command == "quit") {
            exit(0);
        } else {
            std::cout << "Invalid command. You can type help for a full list of commands\n";
        }
    }
}


bool Game::isGameOver() {
    bool deadF = (player1.getHealth() <= 0), deadE = (player2.getHealth() <= 0);
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
