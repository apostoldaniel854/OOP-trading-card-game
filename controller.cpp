#include "headers/game.h"

int main() {
    auto& game = Game::getInstance();
//    std::cout << game << "\n"; /// test required for hw 1
    game.run();
    return 0;
}
