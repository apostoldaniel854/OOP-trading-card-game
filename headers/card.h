#pragma once
#include <string>
#include <vector>
#include "utils.h"
#include <memory>

class Card {
protected:
    std::string name;
    int manaCost;
    int type;
public:
    Card(std::string  name, int manaCost, int type);
    Card();
    [[nodiscard]] int getManaCost() const;
    [[nodiscard]] int getType() const;
    [[nodiscard]] const std::string& getName() const;
    virtual std::shared_ptr<Card> clone() const = 0;
    friend std::ostream& operator << (std::ostream& out, const Card& card);
    virtual ~Card() = default;
};


