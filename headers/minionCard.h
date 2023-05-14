#pragma once
#include "card.h"
#include "minion.h"

class MinionCard : public Card {
private:
    int health;
    int attack;
public:
    MinionCard(std::string  name, int manaCost, int type, int health, int attack);
//    bool playCard() override;
    virtual ~MinionCard() = default;
};

static const std::vector <MinionCard> minionCardsCatalog = {
        MinionCard("Dragon", 5, MINION_CARD, 5, 5),
        MinionCard("Orc", 2, MINION_CARD, 2, 2),
        MinionCard("Imp", 0, MINION_CARD, 1, 1)
};