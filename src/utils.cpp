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

void delay(double seconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds((int)seconds * 1000));
}
bool isNumber(const std::string& str) {
    if (isdigit(str[0]) && str[0] != '0') {
        if ((int)str.size() > 6)
            return false;
        for (int i = 1; i < (int)str.size(); i++)
            if (!isdigit(str[i]))
                return false;
        return true;
    }
    return false;
}
