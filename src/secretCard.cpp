#include "../headers/secretCard.h"

SecretCard::SecretCard(std::string  name, int manaCost, int type, int duration) : Card(std::move(name), manaCost, type), duration(duration) {

}

int SecretCard::getDuration() const {
    return duration;
}
