#include "../headers/cardFactory.h"
#include <functional>

template <typename T>
std::vector <std::shared_ptr<T>> CardFactory::myFilter(const std::vector<std::shared_ptr <Card>>& vec, const std::function<bool(const std::shared_ptr <Card>&)>& check) {
    std::vector<std::shared_ptr<T>> out;
    for (auto&& elem : vec)
        if (check(elem)) {
            /// dynamic cast from Card to T
            if (auto castedElem = std::dynamic_pointer_cast<T>(elem))
                out.push_back(castedElem);
        }
    return out;
}

template
std::vector<std::shared_ptr<MinionCard>> CardFactory::myFilter(const std::vector<std::shared_ptr<Card>>& vec, const std::function<bool(const std::shared_ptr<Card>&)>& check);

template
std::vector<std::shared_ptr<SpellCard>> CardFactory::myFilter(const std::vector<std::shared_ptr<Card>>& vec, const std::function<bool(const std::shared_ptr<Card>&)>& check);



std::shared_ptr<Card> CardFactory::createMinionCard(const std::vector<std::shared_ptr<Card>>& catalog) {
    static std::vector <std::shared_ptr<MinionCard>> minionCatalog = myFilter<MinionCard>(catalog, [](const std::shared_ptr<Card>& card) {
        return card->getType() == MINION_CARD;
    });
    static CardPool<MinionCard, 2 * MAX_MINION_CARDS> pool;
    auto card = pool.getCard();
    card = minionCatalog[getRandomInteger(0, (int)minionCatalog.size() - 1)];
    return card;
}

std::shared_ptr<Card> CardFactory::createSpellCard(const std::vector<std::shared_ptr<Card>>& catalog) {
    static std::vector <std::shared_ptr<SpellCard>> spellCatalog = myFilter<SpellCard>(catalog, [](const std::shared_ptr<Card>& card) {
        return card->getType() == SPELL_CARD;
    });
    static CardPool<SpellCard, 2 * MAX_SPELL_CARDS> pool;
    auto card = pool.getCard();
    card = spellCatalog[getRandomInteger(0, (int)spellCatalog.size() - 1)];
    return card;
}
