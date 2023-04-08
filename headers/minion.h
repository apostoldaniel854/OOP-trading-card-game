#pragma once
#include "card.h"
#include <string>
#include <ostream>

class Minion : public Card {
private:
    int health;
    int attack;
public:
    Minion(const std::string& name, int manaCost, int health, int attack);
    // Minion(const Minion& other);
    friend std::ostream& operator << (std::ostream& out, const Minion& minion);
};