// RandomSearch.h
// Header Define ---------------------------------------------------------------
#ifndef RANDOM_SEARCH_H
#define RANDOM_SEARCH_H
// -----------------------------------------------------------------------------

// Includes --------------------------------------------------------------------
#include "RandomInstanceGeneration.h"
#include <vector>
// -----------------------------------------------------------------------------

// Functions -------------------------------------------------------------------
// Function to perform the Random Search algorithm
bool randomSearch(const RandomInstanceGeneration& instance, int maxTries, int maxFlips);
// -----------------------------------------------------------------------------
#endif