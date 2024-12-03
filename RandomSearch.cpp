// RandomSearch.cpp
// Includes --------------------------------------------------------------------
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include <iostream>
#include "RandomSearch.h"
#include "RandomInstanceGeneration.h"
// ------------------------------------------------------------------------------

// Namespace -------------------------------------------------------------------
using namespace std;
// ------------------------------------------------------------------------------

// Functions -------------------------------------------------------------------
// Function to perform the Random Search algorithm
bool randomSearch(const RandomInstanceGeneration& instance, int maxTries, int maxFlips) {
    int n = instance.n_vars;
    srand(time(0)); // Initialize random seed

    for (int t = 0; t < maxTries; t++) {
        // Random initial assignment
        vector<bool> assignment(n + 1); // Index 0 unused for convenience
        for (int i = 1; i <= n; ++i) { // For each variable
            assignment[i] = rand() % 2;
        }

        // Try to satisfy the instance by flipping variables
        for (int flip = 0; flip < maxFlips; flip++) { // For each flip
            // Boolean to check if the current assignment satisfies the instance
            bool isSatisfying = true;
            vector<const Clause*> satisfiedClauses;
            vector<const Clause*> unsatisfiedClauses;

            for (const auto& clause : instance.clauses) { // For each clause
                bool clauseSatisfied = false;
                for (int i = 0; i < 3; ++i) { // For each literal in the clause
                    int var = abs(clause.literals[i]);
                    bool value = assignment[var]; // If the variable is negated, flip the value
                    if (clause.literals[i] < 0) {
                        value = !value;
                    }
                    if (value) { // If the literal is true
                        clauseSatisfied = true;
                        satisfiedClauses.push_back(&clause); // Add the satisfied clause
                        break;
                    }
                }
                if (!clauseSatisfied) {
                    isSatisfying = false; // The clause is unsatisfied
                    unsatisfiedClauses.push_back(&clause); // Add the unsatisfied clause
                }
            }
            // If the assignment satisfies the instance, print the satisfying assignment
            if (isSatisfying) {
                cout << "Satisfying assignment found.\n";
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

            // Select a random unsatisfied clause
            const Clause* clauseToFix = unsatisfiedClauses[rand() % unsatisfiedClauses.size()];

            // Flip the assignment of a random variable in the clause
            int literalToFlip = clauseToFix->literals[rand() % 3];
            int varToFlip = abs(literalToFlip);
            assignment[varToFlip] = !assignment[varToFlip];
        }
    }
    cout << "No satisfying assignment found after " << maxTries << " tries.\n";
    return false;
}
// ------------------------------------------------------------------------------
