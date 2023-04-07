#pragma once
#include "card.h"
#include <string>

class Minion : public Card {
private:
    int health;
    int attack;
public:
    Minion(std::string name, int manaCost, int type, int health, int attack);
    // Minion(const Minion& other);
    ~Minion(){};
    int getHealth();
    int getAttack();
    void setHealth(int health);
    void setAttack(int attack);
    friend std::ostream& operator << (std::ostream& out, Minion& Minion);
};