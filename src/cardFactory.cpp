#include "../headers/cardFactory.h"
#include <functional>

template <typename T>
std::vector <T> CardFactory::myFilter(const std::vector<T>& vec, std::function<bool(const T&)> check) {
    std::vector<T> out;
    for (auto&& elem : vec)
        if (check(elem))
            out.push_back(elem);
    return out;
}

template
std::vector<std::shared_ptr<Card>> CardFactory::myFilter(const std::vector<std::shared_ptr<Card>>& vec, std::function<bool(const std::shared_ptr<Card>&)> check);



std::shared_ptr<Card> CardFactory::createMinionCard(const std::vector<std::shared_ptr<Card>>& catalog) {
    static std::vector <std::shared_ptr<Card>> minionCatalog = myFilter<std::shared_ptr<Card>>(catalog, [](const std::shared_ptr<Card>& card) {
        return card->getType() == MINION_CARD;
    });
    return minionCatalog[getRandomInteger(0, (int)minionCatalog.size() - 1)]->clone();
}

std::shared_ptr<Card> CardFactory::createSpellCard(const std::vector<std::shared_ptr<Card>>& catalog) {
    static std::vector <std::shared_ptr<Card>> spellCatalog = myFilter<std::shared_ptr<Card>>(catalog, [](const std::shared_ptr<Card>& card) {
        return card->getType() == SPELL_CARD;
    });
    return spellCatalog[getRandomInteger(0, (int)spellCatalog.size() - 1)]->clone();
}
