#include "../headers/spellCard.h"

SpellCard::SpellCard(std::string  name, int manaCost, int type, int damage) : Card(std::move(name), manaCost, type), damage(damage) {}

int SpellCard::getDamage() const {
    return damage;
}