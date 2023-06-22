#pragma once

#include <string>
#include "gameException.h"

class InvalidDeck : public GameException {
public:
    explicit InvalidDeck();

};
