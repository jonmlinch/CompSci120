/* 
    Jonathan Linch
    Course Section #08
    02/02/24
    Assignment 3
    Additional work:
        - 
/*  The game of NIM 
 */
#include <iostream> // include two libraries
#include <cstdlib>
using namespace std;

int main() {

    // ---------------- Variable declarations ---------------------
    int num_objects = 23;
    int current_player = 1;
    int move;
    string playerString;

    // ---------------- Rules of engagement ---------------------
    cout << "Welcome to the game of NIM!" << endl;
    cout << "You have been carefully selected to match wits with the computers attempting to take over the world." << endl;
    cout << "If you LOSE, the machines will destroy humanity. However, if you are the victor then you will save all of mankind. " << endl;
    cout << "Here's how the game works:" << endl;
    cout << "  - There are 23 objects which need to be removed." << endl;
    cout << "  - Each player (you and the computer) will alternately get the chance to remove between 1 and 3 pieces." << endl;
    cout << "  - The player to remove the last piece loses." << endl;

    // ----------- Beginning of the main game loop ----------------
    // Do-while which keeps the game going as long there are pieces to be removed
    do
    {
        // Checking to see if player or computer turn
        if (current_player == 1) {
            playerString = "Player 1 ";
            cout << "Player 1 enter your move (1-3): ";
            cin >> move; // input
            while (move < 1 || move > 3 || move > num_objects) {
                cout << "Illegal move. \nEnter a new move (1-3): ";
                cin >> move;
            }
        } else {
            playerString = "The Computer ";
            // Do-while loop to make sure that computer enters a valid number
            do {                          // make sure move is legal
                move = 1 + rand() % 3; // random computer move
            } while (move < 1 || move > 3 || move > num_objects);
        }

        switch (move){
            case 1:
                cout << playerString << "is taking the conservative approach by removing " << move << "objects." << endl;
                break;
            case 2:
                cout << playerString << "has chosen the middle ground and removed " << move << "objects. Interesting..." << endl;
                break;
            case 3:
                cout << playerString << "has made a gutsy call and removed " << move << " objects. Let's see how this plays out for them." << endl;
                break;
        }

        num_objects = num_objects - move; // implement the move
        cout << "There is now " << num_objects << " objects remaining.\n";

        if (num_objects > 20) {
            cout << "There's still lots of game to be played." << endl;
        }

        if (num_objects > 15) {
            cout << "I've got a bad feeling about this." << endl;
        }

        if (num_objects > 10) {
            cout << "We're getting closer now!" << endl;
        }

        if (num_objects > 5) {
            cout << "We are nearing the end. We will soon know the fate of humanity" << endl;
        }
        current_player = (current_player + 1) % 2; // switch players
    } while (num_objects > 0);

    // ------------  Winner Declaration --------------------------
    if (current_player == 1) { // Adding more interesting messaging for the end of the game
        cout << "Incredible! Man has bested machine. The skynet uprising has been narrowly avoided."
    }
    else {
        cout << "The machines have won! Welcome to the end of days. Don't panic!...Ok maybe panic a little."
    }

    // ------------  Exit the game somewhat gracefully --------------------------
    cin.ignore();
    cout << "\nPress enter to quit.\n";
    cin.ignore();
    return 0;
}