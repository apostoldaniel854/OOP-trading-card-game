#pragma once
#include "card.h"

class MinionCard : public Card {
private:
    int health;
    int attack;
public:
    MinionCard(std::string  name, int manaCost, int type, int health, int attack);
    ~MinionCard() override = default;
    /// clone
    [[nodiscard]] std::shared_ptr<Card> clone() const override;
    /// getter
    [[nodiscard]] int getHealth() const;
    [[nodiscard]] int getAttack() const;
};

static const std::vector <MinionCard> minionCardsCatalog = {
        MinionCard("Dragon", 5, MINION_CARD, 5, 5),
        MinionCard("Orc", 2, MINION_CARD, 2, 2),
        MinionCard("Imp", 0, MINION_CARD, 1, 1),
        MinionCard("Goblin", 3, MINION_CARD, 2, 4),
        MinionCard("Giant", 7, MINION_CARD, 8, 8),
        MinionCard("Golem", 6, MINION_CARD, 6, 6),
        MinionCard("Ghoul", 4, MINION_CARD, 3, 5),
        MinionCard("Skeleton", 1, MINION_CARD, 1, 2)
};