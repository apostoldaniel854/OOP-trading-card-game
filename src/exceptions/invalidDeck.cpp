#include "../../headers/exceptions/invalidDeck.h"

InvalidDeck::InvalidDeck() : GameException("Too many cards of a certain type in the deck") {}
