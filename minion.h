#include "card.h"

class Minion : public Card {
private:
    int health;
    int attack;
public:
    Minion(int manaCost, int type, int health, int attack) : Card(manaCost, type) {
        this->health = health;
        this->attack = attack;
    }
    ~Minion(){};
    int getHealth();
    int getAttack();
    void setHealth(int health);
    void setAttack(int attack);
};