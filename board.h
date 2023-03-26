#include <iostream>
#include <vector>
#include "card.h"
#include "minion.h"


class Board {
private:
    std::vector <Minion> friendlyMinions;
    std::vector <Minion> enemyMinions;
public:
    Board(){};
    ~Board(){};
    void addMinionToBoard(Minion minion, bool friendly);
};