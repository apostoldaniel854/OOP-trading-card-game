#pragma once
#include <iostream>
#include <vector>
#include "card.h"
#include "minion.h"


class Board {
private:
    std::vector <Minion> friendlyMinions;
    std::vector <Minion> enemyMinions;
public:
    // Board();
    [[nodiscard]] const std::vector <Minion>& getFriendlyMinions() const;
    [[nodiscard]] const std::vector<Minion> &getEnemyMinions() const;
//    void addMinionToBoard(Minion minion, bool friendly);
    friend std::ostream& operator << (std::ostream& out, const Board& board);


};