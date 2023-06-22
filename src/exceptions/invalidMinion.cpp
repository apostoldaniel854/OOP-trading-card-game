#include "../../headers/exceptions/invalidMinion.h"

InvalidMinion::InvalidMinion(int minionId) : GameException("Minion " + std::to_string(minionId + 1) + " is not on the board or can't attack this turn") {}

