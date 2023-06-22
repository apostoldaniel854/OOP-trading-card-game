#pragma once
#include <string>
#include "gameException.h"

class InvalidMinion : public GameException {
public:
    explicit InvalidMinion(int minionId);
};
