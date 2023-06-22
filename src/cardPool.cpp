#include "../headers/cardPool.h"

template<typename T, int maxVal>
std::shared_ptr<T> &CardPool<T, maxVal>::getCard() {
    for(auto& card : cards)
        if(card->isInactive()) {
            card->activate();
            return card;
        }
    throw InvalidDeck();
}

template<typename T, int maxVal>
CardPool<T, maxVal>::CardPool() {
    for (auto& card : cards)
        card = std::make_shared<T>();
}


template
class CardPool<MinionCard, 2 * MAX_MINION_CARDS>;

template
class CardPool<SpellCard, 2 * MAX_SPELL_CARDS>;
