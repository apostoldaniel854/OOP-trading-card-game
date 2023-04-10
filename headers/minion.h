#pragma once
#include "card.h"
#include <string>
#include <map>
#include <ostream>




class Minion : public Card {
private:
    std::string name;
    int health;
    int attack;
public:
    Minion(std::string  name, int health, int attack);
    explicit Minion(const std::string& name);
    friend std::ostream& operator << (std::ostream& out, const Minion& minion);
};


static const std::map <std::string, Minion> minionsCatalog = {
        {"Dragon" , Minion("Dragon", 5, 5)},
        {"Orc", Minion("Orc", 2, 2)},
        {"Imp", Minion("Imp", 1, 1)},
};
