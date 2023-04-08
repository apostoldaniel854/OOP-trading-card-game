#pragma once
#include "card.h"
#include <string>
#include <map>
#include <ostream>

class Minion : public Card {
private:
    int health;
    int attack;
public:
    Minion(const std::string& name, int manaCost, int health, int attack);
    explicit Minion(const Card& card);
    friend std::ostream& operator << (std::ostream& out, const Minion& minion);
};
