#include "../headers/computerPlayer.h"

ComputerPlayer::ComputerPlayer(std::string  name, bool friendly, int health, Deck deck) : Player(std::move(name), friendly, health, std::move(deck)) {}

void ComputerPlayer::playTurn(int turn, Board& board, Player& opponent) {
    startTurn(turn);
    std::shared_ptr <Card> playedCard2 = playRandomCard();
    if (playedCard2->getName() != EMPTY_CARD_NAME)
        board.addMinionToBoard(Minion(playedCard2->getName()), getFriendly());
    if (isGameOver(opponent))
        return;
    endTurn();
}