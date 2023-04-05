#pragma once
#include <string>

class Card {
private:
    std::string name;
    int manaCost;
    int type;
public:
    Card(std::string name, int manaCost, int type);
    Card();
    int getManaCost() const;
    int getType();
    std::string getName() const;
    friend std::ostream& operator << (std::ostream& out, Card& card);
};

