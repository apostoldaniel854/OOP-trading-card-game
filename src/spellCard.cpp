#include "../headers/spellCard.h"

SpellCard::SpellCard(std::string  name, int manaCost, int type, int damage) : Card(std::move(name), manaCost, type), damage(damage) {}

int SpellCard::getDamage() const {
    return damage;
}

std::shared_ptr<Card> SpellCard::clone() const {
    return std::make_shared<SpellCard>(name, manaCost, type, damage);
}