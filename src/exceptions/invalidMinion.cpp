#include "../../headers/exceptions/invalidMinion.h"

InvalidMinion::InvalidMinion(int minionId) : message("Minion " + std::to_string(minionId) + " is not on the board or can't attack this turn") {}

const char* InvalidMinion::what() const noexcept {
    return message.c_str();
}
