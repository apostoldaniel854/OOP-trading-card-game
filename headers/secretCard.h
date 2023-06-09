#pragma once
#include "card.h"

class SecretCard : public Card {
private:
    int duration;
public:
    SecretCard(std::string  name, int manaCost, int type, int duration);
    ~SecretCard() override = default;
    /// getter
    [[nodiscard]] int getDuration() const;
    /// clone
    [[nodiscard]] std::shared_ptr<Card> clone() const override;
    bool playCard(Board& board, bool friendly) override;

};