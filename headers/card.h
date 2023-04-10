#pragma once
#include <string>
#include <vector>
#include "utils.h"

class Card {
private:
    std::string name;
    int manaCost;
    int type;
public:
    Card(std::string  name, int manaCost, int type);
    Card();
    [[nodiscard]] int getManaCost() const;
    [[nodiscard]] int getType() const;
    [[nodiscard]] const std::string& getName() const;
    friend std::ostream& operator << (std::ostream& out, const Card& card);
};


static const std::vector <Card> cardsCatalog = {
        Card("Dragon", 5, MINION_CARD),
        Card("Orc", 2, MINION_CARD),
        Card("Imp", 0, MINION_CARD)
};

