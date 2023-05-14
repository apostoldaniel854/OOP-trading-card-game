#include "../headers/humanPlayer.h"
#include "../headers/exceptions/invalidCard.h"


HumanPlayer::HumanPlayer(std::string  name, bool friendly, int health, Deck deck) : Player(std::move(name), friendly, health, std::move(deck)) {}

void HumanPlayer::playTurn(int turn, Board& board, const std::shared_ptr<Player>& opponent) {
    startTurn(turn);
    while (true) {
        /// get command from user
        std::string command;
        std::cin >> command;
        if (command == "play") {
            try {
                std::string cardName;
                std::cin >> cardName;
                std::shared_ptr<Card> card = getHand().playCard(cardName, getMana());
                if (card == nullptr) {
                    throw InvalidCard(cardName);
                }
                if (card->getType() == MINION_CARD) {
                    /// dynamic cast for minion
                    auto minionCard = std::dynamic_pointer_cast<MinionCard>(card);
                    if (minionCard == nullptr) {
                        throw std::runtime_error(
                                "An error occurred while turning a card to a minion. Contact the developer to let them know about this bug\n");
                    }
                    board.addMinionToBoard(Minion(*minionCard), getFriendly());
                }
            }
            catch (InvalidCard& e) {
                std::cout << e.what() << "\n";
            }
            catch (std::runtime_error& e) {
                std::cout << e.what() << "\n";
            }

        } else if (command == "attack") {
            int attackerId, defenderId;
            std::cin >> attackerId >> defenderId;
            bool verdict = board.attackMinion(attackerId, defenderId, getFriendly());
            if (!verdict) {
                std::cout << "Invalid attack\n";
            }
        } else if (command == "go_face") {
            int attackerId;
            std::cin >> attackerId;
            int damage = board.getMinionById(attackerId, getFriendly()).getAttack();
            opponent->takeDamage(damage);
            if (isGameOver(opponent))
                return;
        } else if (command == "end_turn") {
            std::cout << "Turn ended\n";
            endTurn();
            return;
        } else if (command == "show_board") {
            std::cout << board << "\n";
        } else if (command == "show_hand") {
            std::cout << getHand() << "\n";
        } else if (command == "show_player") {
            std::cout << "Your health: ";
            std::cout << getHealth() << "\n";
        } else if (command == "show_opponent") {
            std::cout << "Enemy health: ";
            std::cout << opponent->getHealth() << "\n";
        } else if (command == "help") {
            showCommands();
        } else if (command == "quit") {
            exit(0);
        } else {
            std::cout << "Invalid command. You can type help for a full list of commands\n";
        }
    }
}

void HumanPlayer::showCommands() {
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