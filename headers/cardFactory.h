#pragma once

// factory for creating cards
#include <memory>
#include <string>
#include <vector>
#include "card.h"
#include "minionCard.h"
#include "spellCard.h"
#include "utils.h"
#include <functional>


class CardFactory {
private:
    CardFactory() = default;
    template <typename T>
    static std::vector<T> myFilter(const std::vector<T>& vec, std::function<bool(const T&)> check);
public:
    static std::shared_ptr<Card> createMinionCard(const std::vector<std::shared_ptr<Card>>& catalog);
    static std::shared_ptr<Card> createSpellCard(const std::vector<std::shared_ptr<Card>>& catalog);
};
