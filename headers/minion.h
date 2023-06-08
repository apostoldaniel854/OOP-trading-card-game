#pragma once
#include <string>
#include <map>
#include <ostream>




class Minion {
private:
    std::string name;
    int health;
    int attack;
    bool alreadyAttacked;
public:
    Minion();
    Minion(std::string  name, int health, int attack);
    friend std::ostream& operator << (std::ostream& out, const Minion& minion);

    void attackMinion(Minion &minion);
    void damageMinion(int damage);

    [[nodiscard]] bool isDead() const;

    [[nodiscard]] int getAttack() const;
    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] bool hasAlreadyAttacked() const;
    void setAlreadyAttacked(bool _alreadyAttacked);
};


