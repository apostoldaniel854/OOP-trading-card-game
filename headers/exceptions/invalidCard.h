#pragma once
#include "gameException.h"

#include <string>

class InvalidCard : public GameException {
public:
    explicit InvalidCard(const std::string& message);
};