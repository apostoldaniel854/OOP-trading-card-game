#pragma once
#include <string>
#include <map>

static const int MAX_TURNS = 50;

static const int MAX_HEALTH = 30;
static const int MAX_MANA = 10;
static const int DEFAULT_MANA = 1;

static const int MAX_HAND_SIZE = 10;
static const int START_HAND_SIZE = 3;
static const int MAX_DECK_SIZE = 30;

static const std::string FATIGUE_CARD_NAME = "FATIGUE";
static const std::string EMPTY_CARD_NAME = "EMPTY";

static const bool IS_FRIENDLY = true;
static const bool IS_NOT_FRIENDLY = false;

static const int MINION_CARD = 0;
static const int SPELL_CARD = 1;
[[maybe_unused]] static const int SECRET_CARD = 2;
static const int SPECIAL_CARD = 3;

static const int OPPONENT_TARGET = 0;
static const int MAX_MINION_CARDS = 20;
static const int MAX_SPELL_CARDS = 10;

int getRandomInteger(int leftBound, int rightBound);
void delay(double seconds);
bool isNumber(const std::string& str);

