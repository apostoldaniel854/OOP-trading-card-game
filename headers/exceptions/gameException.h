#pragma once

#include <stdexcept>
#include <string>


class GameException : public std::runtime_error {
public:
    explicit GameException(const std::string& message);
};