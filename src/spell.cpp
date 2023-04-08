#include "../headers/spell.h"

Spell::Spell (std::string name, int manaCost, int type, int damage) : Card(name, manaCost, type), damage(damage) {};

int Spell::getDamage() {
    return damage;
}

void Spell::setDamage(int damage) {
    this->damage = damage;
}