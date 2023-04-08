#pragma once
#include <string>
#include <map>

static const int MAX_HEALTH = 30;
static const int MAX_MANA = 10;
static const int MAX_HAND_SIZE = 10;
static const int MAX_DECK_SIZE = 30;
static const std::string FATIGUE_CARD_NAME = "FATIGUE";
static const bool IS_FRIENDLY = true;
static const bool IS_NOT_FRIENDLY = false;
static const std::string EMPTY_CARD_NAME = "EMPTY";


static const int SPECIAL_CARD = 0;
static const int MINION_CARD = 1;

int getRandomInteger(int leftBound, int rightBound);
