#include "../../headers/exceptions/invalidCard.h"


InvalidCard::InvalidCard(const std::string& _message) : message(_message) {}

const char* InvalidCard::what() const noexcept {
    return message.c_str();
}