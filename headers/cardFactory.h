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
    static std::vector<std::shared_ptr<T>> myFilter(const std::vector<std::shared_ptr <Card>>& vec, const std::function<bool(const std::shared_ptr <Card>&)>& check);
public:
    static std::shared_ptr<Card> createMinionCard(const std::vector<std::shared_ptr<Card>>& catalog);
    static std::shared_ptr<Card> createSpellCard(const std::vector<std::shared_ptr<Card>>& catalog);
};
