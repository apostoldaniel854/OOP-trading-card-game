#include "headers/game.h"

int main() {
    std::string a = "Nu";
    std::cout << "Este o instanta umana?\n";
    std::cin >> a;
    if (a == "Nu")
        return 0;
    Game game;
//    std::cout << game << "\n"; /// test required for hw 1
    game.run();
    return 0;
}
