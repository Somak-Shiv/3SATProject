// ExhaustiveSearch.cpp
// Includes --------------------------------------------------------------------
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "RandomInstanceGeneration.h"
#include "ExhaustiveSearch.h"
// -----------------------------------------------------------------------------

// Namespaces ------------------------------------------------------------------
using namespace std;
// -----------------------------------------------------------------------------

// Functions -------------------------------------------------------------------
// Evaluate a clause with the given assignment
bool evaluateClause(const Clause& clause, const vector<bool>& assignment) {
    for (int i = 0; i < 3; ++i) { // For each literal in the clause
        int var = abs(clause.literals[i]) - 1; 
        bool value = assignment[var]; // If the variable is negated, flip the value
        if (clause.literals[i] < 0) {
            value = !value;
        }
        if (value) {
            return true;
        }
    }
    return false;
}

// Perform exhaustive search to find a satisfying assignment
bool exhaustiveSearch(const RandomInstanceGeneration& formula) {
    int n = formula.n_vars;
    long long totalAssignments = 1LL << n; // 2^n assignments

    // Try all possible assignments
    for (long long i = 0; i < totalAssignments; ++i) {
        vector<bool> assignment(n); // Assignment for each variable
        for (int j = 0; j < n; ++j) {
            assignment[j] = (i >> j) & 1; // Get the j-th bit of i
        }

        bool isSatisfying = true;
        for (const auto& clause : formula.clauses) { // for each clause
            if (!evaluateClause(clause, assignment)) { // If the clause is not satisfied
                isSatisfying = false;
                break;
            }
        }

        if (isSatisfying) {
            // Print the satisfying assignment
            cout << "Satisfying assignment found:" << endl;
            for (int j = 0; j < n; ++j) {
                if (j == n - 1) {
                    cout << "x" << j + 1 << " = " << assignment[j];
                } else {
                    cout << "x" << j + 1 << " = " << assignment[j] << ", ";
                }
            }
            cout << endl;
            return true;
        }
    }
    cout << "No satisfying assignment exists." << endl;
    return false;
}
// -----------------------------------------------------------------------------
