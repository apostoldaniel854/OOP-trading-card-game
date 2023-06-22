#include "../headers/computerPlayer.h"
#include "../headers/exceptions/invalidMinion.h"
#include "../headers/exceptions/invalidCard.h"

#include <utility>
#include <memory>


ComputerPlayer::ComputerPlayer(std::string  name, bool friendly, int health, const Deck& deck) : Player(std::move(name), friendly, health, deck) {}

void ComputerPlayer::playTurn(int turn, Board& board, const std::shared_ptr<Player>& opponent) {
    try {
        startTurn(turn, board);
        std::shared_ptr<Card> card = playRandomCard();
        if (card->getName() != EMPTY_CARD_NAME) {
            if (card->getType() == SPELL_CARD) {
                auto spellCard = std::dynamic_pointer_cast<SpellCard>(card);
                if (spellCard == nullptr)
                    throw InvalidCard("Invalid card type");
                opponent->takeDamage(spellCard->getDamage());
            }
            else {
                card->playCard(board, getFriendly());
            }
        }
    }
    catch (InvalidCard& e) {
        std::cout << e.what() << "\n";
    }
    catch (InvalidMinion& e) {
        std::cout << e.what() << "\n";
    }
    catch (std::runtime_error& e) {
        std::cout << e.what() << "\n";
    }
    if (isGameOver(opponent))
        return;
    std::vector <Minion> myMinions;
    if (friendly) {
        myMinions = board.getFriendlyMinions();
    }
    else {
        myMinions = board.getEnemyMinions();
    }
    for (const Minion& minion : myMinions) {
        if (minion.hasAlreadyAttacked())
            continue;
        if (minion.getAttack() == 0)
            continue;
        int damage = minion.getAttack();
        opponent->takeDamage(damage);
        if (isGameOver(opponent))
            return;
    }
    endTurn();
}


