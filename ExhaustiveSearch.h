// ExhaustiveSearch.h
// Header Define ---------------------------------------------------------------
#ifndef EXHAUSTIVESEARCH_H
#define EXHAUSTIVESEARCH_H
// -----------------------------------------------------------------------------

// Includes --------------------------------------------------------------------
#include "RandomInstanceGeneration.h"
#include <vector>
// -----------------------------------------------------------------------------

// Functions --------------------------------------------------------------------
// Function to evaluate a clause with a given assignment
bool evaluateClause(const Clause& clause, const std::vector<bool>& assignment);

// Function to perform exhaustive search on a formula
bool exhaustiveSearch(const RandomInstanceGeneration& formula);
// -----------------------------------------------------------------------------
#endif 