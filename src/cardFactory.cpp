#include "../headers/cardFactory.h"

std::shared_ptr<Card> CardFactory::createMinionCard(const std::vector<std::shared_ptr<Card>>& catalog) {
    // std::copy_if (foo.begin(), foo.end(), std::back_inserter(bar), [](int i){return i>=0;} );
    static std::vector <std::shared_ptr<Card>> minionCatalog = myFilter(catalog, [](const std::shared_ptr<Card>& card) {
        return card->getType() == MINION_CARD;
    });
    return minionCatalog[getRandomInteger(0, (int)minionCatalog.size() - 1)]->clone();
}

std::shared_ptr<Card> CardFactory::createSpellCard(const std::vector<std::shared_ptr<Card>>& catalog) {
    static std::vector <std::shared_ptr<Card>> spellCatalog = myFilter(catalog, [](const std::shared_ptr<Card>& card) {
        return card->getType() == SPELL_CARD;
    });
    return spellCatalog[getRandomInteger(0, (int)spellCatalog.size() - 1)]->clone();
}
