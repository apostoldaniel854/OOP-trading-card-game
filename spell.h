#include "card.h"

class Spell : public Card {
private:
    int damage;
public:
    Spell(int manaCost, int type, int damage);
    ~Spell(){};
    int getDamage();
    void setDamage(int damage);
};