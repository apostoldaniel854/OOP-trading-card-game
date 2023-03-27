#include "card.h"
#include <string>

class Spell : public Card {
private:
    int damage;
public:
    Spell(std::string name, int manaCost, int type, int damage);
    ~Spell(){};
    int getDamage();
    void setDamage(int damage);
};