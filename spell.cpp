#include "spell.h"
#include "card.h"

Spell::Spell (int manaCost, int type, int damage) : Card(manaCost, type), damage(damage) {};

int Spell::getDamage() {
    return damage;
}

void Spell::setDamage(int damage) {
    this->damage = damage;
}