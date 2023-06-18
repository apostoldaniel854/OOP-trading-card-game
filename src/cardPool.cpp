#include "../headers/cardPool.h"

template<typename T, int maxVal>
std::shared_ptr<T> &CardPool<T, maxVal>::getConn() {
    for(auto& conn : conns)
        if(conn->free()) {
            conn->open();
            return conn;
        }
    throw std::runtime_error("Too many cards!");
}

template
class CardPool<MinionCard, 2 * MAX_MINION_CARDS>;

template
class CardPool<SpellCard, 2 * MAX_SPELL_CARDS>;
