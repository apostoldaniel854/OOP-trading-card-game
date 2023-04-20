#include <random>
#include "../headers/utils.h"
#include <chrono>
#include <thread>


int getRandomInteger(int leftBound, int rightBound) {
    static std::random_device randomDevice;
    std::mt19937 gen(randomDevice());
    std::uniform_int_distribution<> dis(leftBound, rightBound);
    return dis(gen);
}

void delay(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}