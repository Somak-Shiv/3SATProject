// RandomInstanceGeneration.cpp
// Includes --------------------------------------------------------------------
#include "RandomInstanceGeneration.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
// ------------------------------------------------------------------------------

// Namespace --------------------------------------------------------------------
using namespace std;
// ------------------------------------------------------------------------------

// Constructor ------------------------------------------------------------------
RandomInstanceGeneration::RandomInstanceGeneration(int n_vars, int m_clauses)
    : n_vars(n_vars), m_clauses(m_clauses) {
    generateRandomInstance();
}
// ------------------------------------------------------------------------------

// Functions --------------------------------------------------------------------
// Function to generate a random 3-CNF formula 
void RandomInstanceGeneration::generateRandomInstance() {
    // Initialize random seed
    static bool seedInitialized = false;
    if (!seedInitialized) {
        srand(static_cast<unsigned>(time(0)));
        seedInitialized = true;
    }

    clauses.clear(); // Ensure clauses vector is empty

    for (int i = 0; i < m_clauses; ++i) { // For each clause
        Clause clause;
        vector<int> vars;

        // Randomly select 3 distinct variables
        while (vars.size() < 3) {
            int var = rand() % n_vars + 1;
            if (find(vars.begin(), vars.end(), var) == vars.end()) { // If the variable is not already in the list
             vars.push_back(var); // Add the variable
            }
        }

        // Randomly decide whether to negate each variable
        for (int j = 0; j < 3; ++j) { 
            clause.literals[j] = vars[j];
            if (rand() % 2 == 0) {
                clause.literals[j] *= -1; // Negate the literal
            }
        }
        clauses.push_back(clause); // Add the clause to the formula
    }
}

// Function to print the formula in a readable format 
void RandomInstanceGeneration::printInstance() const {
    for (size_t index = 0; index < clauses.size(); ++index) { 
        const auto& clause = clauses[index];
        cout << "(";
        for (int i = 0; i < 3; ++i) {
            if (clause.literals[i] < 0) {
                cout << "~";
            }
            cout << "x" << abs(clause.literals[i]);
            if (i < 2) cout << " ∨ ";
        }
        cout << ")";
        if (index < clauses.size() - 1) {
            cout << " ∧ ";
        }
    }
    cout << endl;
}
// ------------------------------------------------------------------------------