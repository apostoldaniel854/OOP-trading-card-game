#include "../../headers/exceptions/gameException.h"

GameException::GameException(const std::string& _message) : runtime_error("Game: " + _message) {}