#include "../headers/humanPlayer.h"


HumanPlayer::HumanPlayer(std::string  name, bool friendly, int health, const Deck& deck) : Player(std::move(name), friendly, health, deck) {}



void HumanPlayer::playTurn(int turn, Board& board, const std::shared_ptr<Player>& opponent) {
    startTurn(turn, board);
    while (true) {
        /// get command from user
        std::string command;
        std::cin >> command;
        if (command == "play") {
            try {
                std::string cardName;
                std::cin >> cardName;
                std::shared_ptr<Card> card = hand.playCard(cardName, getMana());
                bool notDone = card->playCard(board, getFriendly());
                if (notDone) {
                    auto spellCard = std::dynamic_pointer_cast<SpellCard>(card);
                    if (spellCard == nullptr)
                        throw InvalidCard("Invalid card type");
                    opponent->takeDamage(spellCard->getDamage());
                }
            }
            catch (InvalidCard& e) {
                std::cout << e.what() << "\n";
            }

        } else if (command == "attack") {
            try {
                std::string strAttacker, strDefender;
                std::cin >> strAttacker >> strDefender;
                if (not isNumber(strAttacker) or not isNumber(strDefender)) {
                    std::cout << "Invalid command. You can type help for a full list of commands\n";
                    continue;
                }
                int attackerId = stoi(strAttacker), defenderId = stoi(strDefender);
                attackerId--; defenderId--;
                board.attackMinion(attackerId, defenderId, getFriendly());
            }
            catch (InvalidMinion& e) {
                std::cout << e.what() << "\n";
            }
        }
        else if (command == "go_face") {
            try {
                std::string strAttacker;
                std::cin >> strAttacker;
                if (not isNumber(strAttacker)) {
                    std::cout << "Invalid command. You can type help for a full list of commands\n";
                    continue;
                }
                int attackerId = stoi(strAttacker);
                attackerId--;
                Minion minion = board.getMinionById(attackerId, getFriendly());
                if (minion.hasAlreadyAttacked()) {
                    std::cout << "This minion cannot attack this turn\n";
                } else {
                    int damage = minion.getAttack();
                    opponent->takeDamage(damage);
                    board.setMinionHasAttacked(attackerId, getFriendly());
                    if (isGameOver(opponent))
                        return;
                }
            }
            catch (InvalidMinion& e) {
                std::cout << e.what() << "\n";
            }
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
            std::cout << "Your mana: ";
            std::cout << getMana() << "\n";
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
        if (isGameOver(opponent))
            return;
    }
}

void HumanPlayer::showCommands() {
    std::ifstream commandsFile("./data/commands.txt");
    std::cout << commandsFile.rdbuf();
    commandsFile.close();
    std::cout << "\n";
}
