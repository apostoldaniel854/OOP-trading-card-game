#pragma once

#include "card.h"
#include "minionCard.h"
#include "spellCard.h"

template <typename T, int maxVal>
class CardPool {
private:
    std::vector<std::shared_ptr <T>> conns{maxVal};
public:
    CardPool() {
        for (auto& conn : conns)
            conn = std::make_shared<T>();
    }
    std::shared_ptr <T> & getConn();
};
