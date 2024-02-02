/* 
    Jonathan Linch
    Course Section #08
    02/02/24
    Assignment 3
    Additional work:
        - Made use of functions to control display of objects and game replay
*/
/*  The game of NIM 
 */
#include <iostream> // include two libraries
#include <cstdlib>
using namespace std;

void displayNumObjects(int numObjects);
int game();

int main() {

    int restart = 1;
    
    //Allow the game to be played over and over
    while(restart == 1) {
        //Added the game to its own function to make main more readable
        restart = game();
    }

    // ------------  Exit the game somewhat gracefully --------------------------
    cin.ignore();
    cout << "\nPress enter to quit.\n";
    cin.ignore();
    return 0;
}

//Game function. Nearly all of the game logic is in this function
int game() {
    // ---------------- Variable declarations ---------------------
    int restart = 0;
    int num_objects = 23;
    int current_player = 1;
    int minMove = 1;
    int maxMove = 5;
    int move;
    char newGame[] = "no";
    string playerString;

    // ---------------- Rules of engagement ---------------------
    cout << "Welcome to the game of NIM!" << endl;
    cout << "You have been carefully selected to match wits with the computers attempting to take over the world." << endl;
    cout << "If you LOSE, the machines will destroy humanity. However, if you are the victor then you will save all of mankind. " << endl;
    cout << "Here's how the game works:" << endl;
    cout << "  - There are 23 objects which need to be removed." << endl;
    cout << "  - Each player (you and the computer) will alternately get the chance to remove between 1 and 3 pieces." << endl;
    cout << "  - The player to remove the last piece loses." << endl;
    cout << "We will start the game with these " << num_objects << " objects.";
    
    //Call display objects function to show the starting number of objects
    displayNumObjects(num_objects);
    

    // ----------- Beginning of the main game loop ----------------
    // Do-while which keeps the game going as long there are pieces to be removed
    do
    {
        // Checking to see if player or computer turn
        if (current_player == 1) {
            playerString = "Player 1 ";
            cout << "Player 1 enter your move (" << minMove << " - " << maxMove << "): ";
            cin >> move; // input
            while (move < minMove || move > maxMove || move > num_objects) {
                cout << "Illegal move. \nEnter a new move (" << minMove << " - " << maxMove << "): ";
                cin >> move;
            }
        } else {
            playerString = "The Computer ";
            // Do-while loop to make sure that computer enters a valid number
            do {
                
                //Determine the computer's move based on the min and max moves values
                move = minMove + rand() % maxMove;
                
                //Prevents computer from putting in a losing number unless it has to
                if (move == num_objects && num_objects > minMove) {
                    move = move - 1;
                }
                
            } while (move < minMove || move > maxMove || move > num_objects);
        }

        //Color commentary based on the number of objects removed
        switch (move){
            case 1:
                cout << playerString << "is taking the conservative approach by removing " << move << " objects." << endl;
                break;
            case 2:
                cout << playerString << "has chosen the middle ground and removed " << move << " objects. Interesting..." << endl;
                break;
            case 3:
                cout << playerString << "has made a gutsy call and removed " << move << " objects. Let's see how this plays out for them." << endl;
                break;
            default: 
                cout << playerString << "is making BIG moves by removing " << move << " objects." << endl;
                
        }

        num_objects = num_objects - move; // implement the move
        cout << "There is now " << num_objects << " objects remaining.";
        displayNumObjects(num_objects);

        //Conditions to determine a statement about the status of the game
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
        cout << "Incredible! Man has bested machine. The skynet uprising has been narrowly avoided." << endl;
    }
    else {
        cout << "The machines have won! Welcome to the end of days. Don't panic!...Ok maybe panic a little." << endl;
    }
    
    //Ask player if they want to restart the game
    cout << "Would you like to do another calculation (y/n)?  ";
    cin >> newGame;

    switch(newGame[0]) {
        case 'y':
        case 'Y':
            restart = 1;
            break;
        default:
            restart = 0;
            break;
    } 
    
    return restart;
}

//Function to display the number of objects remaining
void displayNumObjects(int numObjects){
    cout << " >";
    for(int i = 0; i < numObjects; i++) {
        
        //If statement to group objects to make it easier to track
        if(i % 5 == 4) {
            cout << "*  ";
        } else {
            cout << "*";
        }
        
    }
    
    cout << "<\n";
}