#pragma once

#include "card.h"
#include "minionCard.h"
#include "spellCard.h"
#include "../headers/exceptions/invalidDeck.h"

template <typename T, int maxVal>
class CardPool {
private:
    std::vector<std::shared_ptr <T>> cards{maxVal};
public:
    CardPool();
    std::shared_ptr <T> & getCard();
};