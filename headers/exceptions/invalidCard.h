#pragma once

#include <string>

class InvalidCard : public std::exception {
private:
    std::string message;
public:
    explicit InvalidCard(const std::string& message);
    [[nodiscard]] const char* what() const noexcept override;
};