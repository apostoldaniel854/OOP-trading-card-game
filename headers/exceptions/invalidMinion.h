#pragma once

#include <string>
class InvalidMinion : public std::exception {
private:
    std::string message;
public:
    explicit InvalidMinion(int minionId);
    [[nodiscard]] const char* what() const noexcept override;
};
