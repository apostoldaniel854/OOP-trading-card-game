#include "../headers/minionCard.h"

MinionCard::MinionCard(std::string  name, int manaCost, int type, int health, int attack) : Card(std::move(name), manaCost, type), health(health), attack(attack){}
//
//bool MinionCard::playCard() {
//    board.addMinionToBoard(Minion(getName(), health, attack), friendly);
//}