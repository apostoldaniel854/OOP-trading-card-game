#pragma once

#include "card.h"

class SpellCard : public Card {
private:
    int damage{};
public:
    SpellCard(std::string  name, int manaCost, int type, int damage);
    SpellCard() = default;
    ///getter
    [[nodiscard]] int getDamage() const;
    /// clone
    [[nodiscard]] std::shared_ptr<Card> clone() const override;
    ~SpellCard() override = default;
    bool playCard(Board& board, bool friendly) override;
};
