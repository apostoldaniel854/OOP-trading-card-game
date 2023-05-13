#pragma once
#include "card.h"
#include <string>
#include <map>
#include <ostream>




class Minion {
private:
    std::string name;
    int health;
    int attack;
public:
    Minion();
    Minion(std::string  name, int health, int attack);
    explicit Minion(const std::string& name);
    friend std::ostream& operator << (std::ostream& out, const Minion& minion);

    void attackMinion(Minion &minion);


    [[nodiscard]] bool isDead() const;

    [[nodiscard]] int getAttack() const;
    [[nodiscard]] const std::string& getName() const;
};


static const std::map <std::string, Minion> minionsCatalog = {
        {"Dragon" , Minion("Dragon", 5, 5)},
        {"Orc", Minion("Orc", 2, 2)},
        {"Imp", Minion("Imp", 1, 1)},
};
