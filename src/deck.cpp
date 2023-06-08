#include "../headers/deck.h"

Deck::Deck(int numCards) {
    std::vector <std::shared_ptr <Card>> catalog = readCatalog();
    for (int i = 0; i < numCards; i++) {
        cards.emplace_back(catalog[getRandomInteger(0, (int)catalog.size() - 1)]);
    }
}

std::shared_ptr<Card> Deck::drawCard() {
    if ((int)cards.size() > 0) {
        std::shared_ptr<Card> card = cards.back();
        cards.pop_back();
        return card;
    }
    return std::make_shared<MinionCard>(FATIGUE_CARD_NAME, SPECIAL_CARD, 0, 0, 0);
}


std::ostream& operator << (std::ostream &out, const Deck &deck) {
    out << "---------------- DECK ---------------\n";
    delay(0.2);
    for (const std::shared_ptr<Card>& card : deck.cards)
        out << *card;
    return out;
}

Deck& Deck::operator = (const Deck& deck) {
    if (this != &deck)
        deepCopy(deck);
    return *this;
}

Deck::Deck(const Deck& deck) {
    deepCopy(deck);
}

void Deck::deepCopy(const Deck& deck) {
    cards.clear();
    for (const std::shared_ptr<Card>& card : deck.cards) {
        cards.emplace_back(card->clone());
    }
}

std::vector <std::shared_ptr <Card>> Deck::readCatalog() {
    std::ifstream catalogFile("../data/catalog.txt");
    std::vector <std::shared_ptr <Card>> catalog;
    int noOfCards;
    catalogFile >> noOfCards;

    for (int i = 0; i < noOfCards; i++) {
        std::string name; int manaCost; std::string type;
        catalogFile >> name >> manaCost >> type;
        if (type == "MINION_CARD") {
            int health, attack;
            catalogFile >> health >> attack;
            catalog.emplace_back(std::make_shared<MinionCard>(name, manaCost, MINION_CARD, health, attack));
        }
        else if (type == "SPELL_CARD") {
            int damage;
            catalogFile >> damage;
            catalog.emplace_back(std::make_shared<SpellCard>(name, manaCost, SPELL_CARD, damage));
        }
        else {
            exit(2);
        }
    }
    catalogFile.close();
    return catalog;
}