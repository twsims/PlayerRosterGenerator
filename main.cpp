/*
Terrance Sims
MS549 - Data Structures and Algorithms 
Assignment 2-1 Recursion and Pointers
The general idea of the application is to create a roster of players that are stored with a maximum of 15 players.
Once this roster is created the recursive function will cycle through the entire roster and make various combinations 
of potential starters.  This is beneficial for me as a coach as my younger teams I have to experiment with different 
lineups as my younger group requires all players to start at least once in the season.  

Time estimation I don't expect this to take as long I have to figure out the syntax of C++ for vectors as I used something similiar
in python for our program.  I wanted to try  my hand at creating it in C++ since I am not as familiar.  
Total estimate is roughly 6-10 hours and unfortunately it took longer more like 12-14 hours as I did not fully understand chapter 11 and chapter 17 to 
properly implement all the features I wanted.  I did work with a C++ tutor to fine tune my recursive function for generating the starting lineup

*/
#include <iostream>
#include "functions.h"

using namespace std;

int main() {
    // Create a list to store the player names and a list to store all the potenetial starters
    vector<string> roster;
    vector<vector<string>*> allCombinations;
    int choice;

    // Display a menu and remain available until the exit is selected.
    do {
        // Show the menu options
        cout << "\nMenu:" << endl;
        cout << "1. Add Player to Roster" << endl;
        cout << "2. Generate All Starting 5 Lineups" << endl;
        cout << "3. Display Current Roster" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform actions based on the user's choice
        switch (choice) {
        case 1: {
            // Add a player to the roster if there's space (maximum 15 players)
            if (roster.size() < 15) {
                string playerName;
                cout << "Enter player name: ";
                cin.ignore();
                getline(cin, playerName);
                roster.push_back(playerName);
            }
            else {
                // Tell the user if the roster is full
                cout << "\nRoster is full. Cannot add more players." << endl;
            }
            break;
        }
        case 2: {
            // Generate all possible starters if there are enough players
            if (roster.size() < 5) {
                // Tell the user if there are not enough players
                cout << "\nNot enough players to generate lineups. Minimum 5 players required." << endl;
            }
            else {
                vector<string> combination;
                // clear memory and roster before starting
                freeCombinations(allCombinations);
                // Generate the starting 5 by using recursion 
                generateCombinations(roster, combination, 0, 0, allCombinations);
                // Display all possible starting 5
                displayCombinations(allCombinations);
            }
            break;
        }
        case 3: {
            // Show the current list of players from choice 1
            displayRoster(roster);
            break;
        }
        case 4: {
            // lears memory prior to exiting
            freeCombinations(allCombinations);
            cout << "\nExiting program." << endl;
            break;
        }
        default: {
            // makes sure user makes a proper selection
            cout << "\nPlease select 1 of the menu choices. Please try again." << endl;
            break;
        }
        }
    } while (choice != 4);

    return 0;
}


