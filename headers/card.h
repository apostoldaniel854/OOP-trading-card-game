#pragma once
#include <string>
#include <vector>
#include "utils.h"
#include <memory>
#include "board.h"

class Card {
private:
    bool active = false;
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
    virtual bool playCard(Board& board, bool friendly) = 0;
    [[nodiscard]] virtual std::shared_ptr<Card> clone() const = 0;
    friend std::ostream& operator << (std::ostream& out, const Card& card);
    virtual ~Card();
    void activate() { active = true; }
    [[nodiscard]] bool isInactive() const { return !active; }
    void deactivate() { active = false; }
};


