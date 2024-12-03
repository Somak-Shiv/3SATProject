// RandomInstanceGeneration.h
// Header Define ---------------------------------------------------------------
#ifndef RANDOMINSTANCEGENERATION_H
#define RANDOMINSTANCEGENERATION_H
// -----------------------------------------------------------------------------

// Includes --------------------------------------------------------------------
#include <vector>
// -----------------------------------------------------------------------------

// Clause Struct ---------------------------------------------------------------
struct Clause {
    int literals[3]; // Three literals in the clause
};
// -----------------------------------------------------------------------------

// Random Instance Generation Class ============================================
class RandomInstanceGeneration {
public:
    // Variable Declarations ---------------------------------------------------
    int n_vars;              // Number of variables
    int m_clauses;           // Number of clauses
    std::vector<Clause> clauses;
    // -------------------------------------------------------------------------

    // Constructor -------------------------------------------------------------
    RandomInstanceGeneration(int n, int m);
    // -------------------------------------------------------------------------

    // Function Declarations ---------------------------------------------------
    // Generates a random 3-CNF formula
    void generateRandomInstance();

    // Prints the formula in a readable format
    void printInstance() const;
    //--------------------------------------------------------------------------
};
// =============================================================================
#endif