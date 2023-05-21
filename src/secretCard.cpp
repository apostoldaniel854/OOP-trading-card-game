#include "../headers/secretCard.h"

SecretCard::SecretCard(std::string  name, int manaCost, int type, int duration) : Card(std::move(name), manaCost, type), duration(duration) {

}

int SecretCard::getDuration() const {
    return duration;
}

std::shared_ptr<Card> SecretCard::clone() const {
    return std::make_shared<SecretCard>(name, manaCost, type, duration);
}

bool SecretCard::playCard(Board &board, bool friendly) {
    return true;
}