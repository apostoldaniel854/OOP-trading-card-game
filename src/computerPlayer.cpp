#include "../headers/computerPlayer.h"
#include "../headers/exceptions/invalidMinion.h"
#include "../headers/exceptions/invalidCard.h"

#include <utility>

ComputerPlayer::ComputerPlayer(std::string  name, bool friendly, int health, const Deck& deck) : Player(std::move(name), friendly, health, std::move(deck)) {}

void ComputerPlayer::playTurn(int turn, Board& board, const std::shared_ptr<Player>& opponent) {
    try {
        startTurn(turn, board);
        std::shared_ptr<Card> playedCard2 = playRandomCard();
        if (playedCard2->getName() != EMPTY_CARD_NAME) {
            if (playedCard2->getType() == MINION_CARD) {
                /// dynamic cast for minion
                auto minionCard = std::dynamic_pointer_cast<MinionCard>(playedCard2);
                if (minionCard == nullptr) {
                    throw std::runtime_error("An error occurred while turning a card to a minion. Contact the developer to let them know about this bug\n");
                }
                board.addMinionToBoard(Minion(*minionCard), getFriendly());
            } else {
                /// dynamic cast for spell
                auto spellCard = std::dynamic_pointer_cast<SpellCard>(playedCard2);
                if (spellCard == nullptr) {
                    throw std::runtime_error("An error occurred while turning a card to a spell. Contact the developer to let them know about this bug\n");
                }
                opponent->takeDamage(spellCard->getDamage());
            }
        }

    }
    catch (std::runtime_error& e) {
        std::cout << e.what();
    }
    catch (InvalidCard& e) {
        std::cout << e.what();
    }
    catch (InvalidMinion& e) {
        std::cout << e.what();
    }
    if (isGameOver(opponent))
        return;
    endTurn();
}