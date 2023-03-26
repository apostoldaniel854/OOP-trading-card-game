class Card {
private:
    int manaCost;
    int type;
public:
    Card(int manaCost, int type);
    Card();
    ~Card();
    int getManaCost();
    int getType();
    void setManaCost(int manaCost);
    void setType(int type);
};