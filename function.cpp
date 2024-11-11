// functions.cpp
#include "functions.h"
#include <iostream>

using namespace std;

// This function generates all possible lineups of 5 players from the roster
// It uses recursion to explore every possible combination
void generateCombinations(vector<string>& roster, vector<string>& combination, int start, int depth, vector<vector<string>*>& allCombinations) {
    // If we have chosen 5 players, save this combination
    if (depth == 5) {
        vector<string>* newCombination = new vector<string>(combination);
        allCombinations.push_back(newCombination);
        return;
    }
    // Loop through the players to create different combinations
    for (int i = start; i < roster.size(); ++i) {
        combination.push_back(roster[i]); // Add player to the current combination
        generateCombinations(roster, combination, i + 1, depth + 1, allCombinations); // Recur to add more players
        combination.pop_back(); // Remove the last player to try the next one
    }
}
// This function displays the current roster of players
void displayRoster(const vector<string>& roster) {
    cout << "\nCurrent Roster:" << endl;
    for (int i = 0; i < roster.size(); ++i) {
        cout << i + 1 << ". " << roster[i] << endl; // Display each player's name with a number
    }
}

// This function displays all the generated 5-player Starters
void displayCombinations(const vector<vector<string>*>& allCombinations) {
    cout << "\nGenerated Starting 5s :" << endl;
    for (int i = 0; i < allCombinations.size(); ++i) {
        cout << "Lineup " << i + 1 << ": ";
        for (const string& player : *allCombinations[i]) {
            cout << player << " "; // Display each player's name in the starting 5
        }
        cout << endl;
    }
}

// This function frees the memory used to store the starters
void freeCombinations(vector<vector<string>*>& allCombinations) {
    for (auto combination : allCombinations) {
        delete combination; // Free the memory allocated for each combination
    }
    allCombinations.clear(); // Clear the list of combinations
}
