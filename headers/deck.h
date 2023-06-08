#pragma once
#include "hand.h"
#include "card.h"
#include "minionCard.h"
#include "spellCard.h"
#include <vector>
#include <memory>
#include <fstream>
class Deck {
private:
    std::vector <std::shared_ptr<Card>> cards;
    static std::vector <std::shared_ptr <Card>> catalog;
public:
    explicit Deck(int numCards);
    static std::vector <std::shared_ptr <Card>> readCatalog();
    std::shared_ptr<Card> drawCard();
    /// assignment operator =
    Deck& operator = (const Deck& deck);
    /// copy constructor
    Deck(const Deck& deck);
    /// deep copy
    void deepCopy(const Deck& deck);
    friend std::ostream& operator << (std::ostream& out, const Deck &deck);
};
