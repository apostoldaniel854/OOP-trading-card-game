#include <string>

class Card {
private:
    std::string name;
    int manaCost;
    int type;
public:
    Card(std::string name, int manaCost, int type);
    Card();
    int getManaCost();
    int getType();
    std::string getName();
    void setManaCost(int manaCost);
    void setType(int type);
    void setName(std::string name);
    friend std::ostream& operator << (std::ostream& out, Card& card);
};

