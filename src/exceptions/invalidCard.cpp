#include "../../headers/exceptions/invalidCard.h"


InvalidCard::InvalidCard(const std::string& cardName) : message(cardName + " is not in your hand or you dont have any mana") {}

const char* InvalidCard::what() const noexcept {
    return message.c_str();
}