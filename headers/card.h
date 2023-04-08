#pragma once
#include <string>

class Card {
private:
    std::string name;
    int manaCost;
//    int type;
public:
    Card(std::string  name, int manaCost);
    Card();
    [[nodiscard]] int getManaCost() const;
//    [[maybe_unused]] [[nodiscard]] int getType() const;
    [[nodiscard]] const std::string& getName() const;
    friend std::ostream& operator << (std::ostream& out, const Card& card);
};

