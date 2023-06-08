#include "headers/game.h"

int main() {
    std::string a = "aa";
    std::cout << "Este o instanta umana?\n";
    std::cin >> a;
    if (a == "aa")
        return 0;
    Game game;
//    std::cout << game << "\n"; /// test required for hw 1
    game.run();
    return 0;
}
