// Main.cpp
// Includes --------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <chrono>
#include "RandomSearch.h"
#include "ExhaustiveSearch.h"
#include "RandomInstanceGeneration.h"
// -----------------------------------------------------------------------------

// Namespaces ------------------------------------------------------------------
using namespace std;
// -----------------------------------------------------------------------------

// Function declarations -------------------------------------------------------
// Function to run Random Search (declaration)
void runRandomSearch(const RandomInstanceGeneration& instance);

// Function to run Exhaustive Search (declaration)
void runExhaustiveSearch(const RandomInstanceGeneration& instance);
// -----------------------------------------------------------------------------

// =============================================================================
// Main function ---------------------------------------------------------------
int main() {
    // Main menu
    // Get input from user to run a specific program
    int input;
    do {
        cout << 
        "What Program do you want to run?\n1. Random Instance\n2. Random Search\n3. Exhaustive Search\n4. Run All\n0. Exit\nSelection: ";
        cin >> input;
        // Switch case to run the selected program
        switch(input) {
        case 1:
        // create an instance and print it
        {
            int n, m;
            cout << "Enter the number of variables (n) (for instance generation): ";
            cin >> n;
            cout << "Enter the number of clauses (m) (for instance generation): ";
            cin >> m;
            RandomInstanceGeneration instance(n, m);
            instance.printInstance();
            break;
        }
        case 2:
        // run the random search function
        {
            int n, m;
            cout << "Enter the number of variables (n) (for instance generation): ";
            cin >> n;
            cout << "Enter the number of clauses (m) (for instance generation): ";
            cin >> m;
            RandomInstanceGeneration instance(n, m);
            runRandomSearch(instance);
            break;
        }
        case 3:
        // run the exhaustive search function
        {
            int n, m;
            cout << "Enter the number of variables (n) (for instance generation): ";
            cin >> n;
            cout << "Enter the number of clauses (m) (for instance generation): ";
            cin >> m;
            RandomInstanceGeneration instance(n, m);
            runExhaustiveSearch(instance);
            break;
        }
        case 4:
        // run all functions
        {
            int n, m;
            cout << "Enter the number of variables (n) (for instance generation): ";
            cin >> n;
            cout << "Enter the number of clauses (m) (for instance generation): ";
            cin >> m;
            RandomInstanceGeneration instance(n, m);
            runRandomSearch(instance);
            runExhaustiveSearch(instance);
            break;
        }
        case 0:
        // exit the program
            cout << "Exiting Program\n";
            exit(EXIT_SUCCESS);
        default:
        // to catch invalid inputs
            cout << "Invalid Input\n";
            break;
        }
    } while (input != 0);

    return EXIT_SUCCESS;
}
// -----------------------------------------------------------------------------
// =============================================================================

// Function implementations ----------------------------------------------------
// Function to run Random Search (implementation)
void runRandomSearch(const RandomInstanceGeneration& instance) {
    // If you want to see the formula/instance
    //cout << "Testing Random Search on the following instance:" << endl;
    //instance.printInstance();
    int input;
    int n = instance.n_vars;
    int m = instance.m_clauses;
    cout << "Enter the number of tries: ";
    cin >> input;
    int maxTries = input;
    int maxFlipsFactor = instance.m_clauses; // Set maxFlips = maxFlipsFactor * n
    double k = (double) m/n; // k = m/n
    cout << "n = " << n << ", m = " << m << ", k = " << k << endl;

    // Random Search Algorithm
    // Time the algorithm
    auto start = chrono::high_resolution_clock::now();
    bool result = randomSearch(instance, maxTries, maxFlipsFactor * instance.n_vars);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration<double>(end - start).count();
    cout << "Random Search: " << (result ? "SAT" : "UNSAT")
         << ", Time: " << duration << "s\n";

    cout << "-------------------------------\n";
}

// Function to run Exhaustive Search (implementation)
void runExhaustiveSearch(const RandomInstanceGeneration& instance) {
    // To stop the program from running for n > 20 due to 2^n assignments
    /*if (instance.n_vars > 20) {
        cout << "Exhaustive Search is not feasible for n > 20." << endl;
        return;
    }*/
    // If you want to see the formula/instance
    //cout << "Testing Exhaustive Search on the following instance:" << endl;
    //instance.printInstance();

    // Perform exhaustive search
    bool result = exhaustiveSearch(instance);

    if (result) {
        cout << "Formula is satisfiable." << endl;
    } else {
        cout << "Formula is unsatisfiable." << endl;
    }
}
// -----------------------------------------------------------------------------