#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>

using namespace std;

// Function to generate all possible 5-player starters
void generateCombinations(vector<string>& roster, vector<string>& combination, int start, int depth, vector<vector<string>*>& allCombinations);

// Function to display the current list of players
void displayRoster(const vector<string>& roster);

// Function to display all generated Starters
void displayCombinations(const vector<vector<string>*>& allCombinations);

// This function clears up memory prior to creating roster
void freeCombinations(vector<vector<string>*>& allCombinations);

#endif
