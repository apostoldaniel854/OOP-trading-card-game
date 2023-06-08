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
    if (isGameOver(opponent))
        return;
    endTurn();
}


