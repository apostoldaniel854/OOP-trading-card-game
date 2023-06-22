#include "../../headers/exceptions/invalidCard.h"


InvalidCard::InvalidCard(const std::string& _message) : GameException(_message) {}
