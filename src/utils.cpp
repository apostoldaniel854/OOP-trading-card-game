#include <random>
#include "../headers/utils.h"

int getRandomInteger(int leftBound, int rightBound) {
    static std::random_device randomDevice;
    std::mt19937 gen(randomDevice());
    std::uniform_int_distribution<> dis(leftBound, rightBound);
    return dis(gen);
}