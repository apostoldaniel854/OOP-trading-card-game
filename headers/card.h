#pragma once
#include <string>
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
//    [[nodiscard]] int getType() const;
    [[nodiscard]] const std::string& getName() const;
    friend std::ostream& operator << (std::ostream& out, const Card& card);
};

