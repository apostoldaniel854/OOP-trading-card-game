#pragma once

#include "card.h"

class SpellCard : public Card {
private:
    int damage;
public:
    SpellCard(std::string  name, int manaCost, int type, int damage);
    ///getter
    [[nodiscard]] int getDamage() const;
    /// clone
    [[nodiscard]] std::shared_ptr<Card> clone() const override;
    ~SpellCard() override = default;
};

static const std::vector <SpellCard> spellCardsCatalog = {
        SpellCard("Fireball", 4, SPELL_CARD, 6),
        SpellCard("Fireblast", 2, SPELL_CARD, 3),
        SpellCard("Arcane", 0, SPELL_CARD, 1),
        SpellCard("Frostbolt", 3, SPELL_CARD, 4),
        SpellCard("Lightning", 5, SPELL_CARD, 7)
};