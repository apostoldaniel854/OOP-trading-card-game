#pragma once
#include "card.h"

class MinionCard : public Card {
private:
    int health{};
    int attack{};
public:
    MinionCard(std::string  name, int manaCost, int type, int health, int attack);
    MinionCard() = default;
    ~MinionCard() override = default;
    /// clone
    [[nodiscard]] std::shared_ptr<Card> clone() const override;

    bool playCard(Board& board, bool friendly) override;
};
