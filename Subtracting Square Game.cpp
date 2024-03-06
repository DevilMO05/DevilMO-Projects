// Game Subtracting Square
/* Program: This program is a game where players take turns removing a square number of coins from a pile.
The last player to remove a coin wins. Players can choose to play in Human Mode, where they
select the number of coins to remove, or Random Mode, where coins are selecting randomly.*/
// Author: Mohamed Mahmoud Abdelbaset (DevilMO05)
// Version: 1.0
// Date: 3/2/2024


#include <bits/stdc++.h>
using namespace std;

// Function to get valid moves (square numbers) based on the number of coins left in the pile
vector<int> getValidMoves(int coins) {
    vector<int> validMoves;
    for (int i = 1; i * i <= coins; i++) {
        validMoves.push_back(i * i);
    }
    return validMoves;
}

// Function for the Human Mode of the game
void PlayGame_HumanMode() {
    // Code for Human Mode...

    int coins;
    cout << "Enter the number of coins in the pile: ";
    cin >> coins;
    while (coins <= 0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    }

    int playerTurn = 1;
    while (coins > 0) {
        cout << "Coins left: " << coins << endl;
        string playerName = (playerTurn == 1) ? "Player 1" : "Player 2";
        cout << playerName << "'s turn" << endl;

        vector<int> moves = getValidMoves(coins);
        cout << "Valid moves: ";
        for (int move : moves) {
            cout << move << " ";
        }
        cout << endl;

        int move;
        cout << "Enter a Square Number of Coins to Remove (" << playerName << "): " ;
        cin >> move;
        while (move > coins or move <= 0){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid move. Enter a valid move: ";
            cin >> move;
        }
        while (move != pow(int(pow(move,0.5)),2)) {
            cout << "Invalid move. Enter a valid move: ";
            cin >> move;
        }

        cout << playerName << " removes " << move << " coins.\n" << endl;

        coins -= move;

        if (coins == 0) {
            cout << playerName << " wins!" << endl;
            break;
        }

        playerTurn = (playerTurn == 1) ? 2 : 1;
    }
}
// Function for the Random Mode of the game
void PlayGame_RandomMode(){
    // Code for Random Mode...

    int coins;
    coins = rand() % 100 + 1;
    while(ceil(pow(coins, 0.5)) == floor(pow(coins, 0.5))){
        coins = rand() % 100 + 1;
}
        cout << "Number of Coins in the Pile: " << coins << endl;

        int playerTurn = 1;
        while (coins > 0) {
            cout << "Coins left: " << coins << endl;
            string playerName = (playerTurn == 1) ? "Player 1" : "Player 2";
            cout << playerName << "'s turn" << endl;

            vector<int> moves = getValidMoves(coins);
            cout << "Valid moves: ";
            for (int move: moves) {
                cout << move << " ";
            }
            cout << endl;

            int move;
            cout << "Enter a Square Number of Coins to Remove (" << playerName << "): " ;
            cin >> move;
            while (move > coins or move <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid move. Enter a valid move: ";
                cin >> move;
            }
            while (move != pow(int(pow(move, 0.5)), 2)) {
                cout << "Invalid move. Enter a valid move: ";
                cin >> move;
            }

            cout << playerName << " removes " << move << " coins.\n" << endl;

            coins -= move;

            if (coins == 0) {
                cout << playerName << " wins!" << endl;
                break;
            }

            playerTurn = (playerTurn == 1) ? 2 : 1;
        }
    }


int main() {
    // Welcome message and explanation of the game

    int coins;
    cout << "Welcome to Subtracting Squares Game!\n" ;
    cout << "The goal of the game is to be the player to remove the last coin.\n" ;
    cout << "You can choose between two game modes:\n" ;
    cout << "1. Human Mode: You choose the number of coins to remove.\n" ;
    cout << "2. Random Mode: Coins are removed randomly, but the total number of coins is not a square number.\n" ;
    cout << "Let's play!\n\n" ;
    vector<int> validMoves = getValidMoves(coins);
    char tryAgain;

    do {
        // Menu for game mode selection

        int choice;
        cout << "1. Human Mode " << endl;
        cout << "2. Random Mode " << endl;
        cout << "3. Exit " << endl;
        cout << "Enter your choice (1-3): ";
        while (!(cin >> choice) or choice < 1 or choice > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number between 1 and 3: ";
        }

        // Switch statement to handle menu choices
        switch (choice) {
            case 1:
                PlayGame_HumanMode();
                break;
            case 2:
                PlayGame_RandomMode();
                break;
            case 3:
                cout << "Exiting game. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 3: " << endl;
                cout << "\n" ;
        }

        // Prompt to play again
        cout << "0. Do you want to try again? : ";
        cin >> tryAgain;
        cout << "\n" ;
    } while (tryAgain == '0');

    cout << "Exiting game. Goodbye!" << endl;

    return 0;
}
