/* 
    Jonathan Linch
    Course Section #08
    02/02/24
    Assignment 3
    Additional work:
        - 
/*  The game of NIM 
 */
 #include<iostream>     // include two libraries
 #include<cstdlib>
 using namespace std;
 int main()             // main() starts the actual program 
 {
    // ---------------- Variable declarations ---------------------
    int num_objects = 23; 
    int current_player = 1; 
    int move;
    // ----------- Beginning of the main game loop ----------------
    do {                                      
       if (current_player == 1) {    // conditional: if
            cout << "Player 1 enter your move (1-3): ";  // output
            cin >> move;                 // input
            while (move < 1 || move > 3 || move > num_objects){
               cout << "Illegal move. \nEnter a new move (1-3): ";
               cin >> move;
            }
       } else {                          // else part of conditional
            do {                         // make sure move is legal
               move =  1+ rand() % 3;    // random computer move
            } while (move < 1 || move > 3 || move > num_objects);
            cout << "Computer removed " << move << endl;
       }
       num_objects = num_objects - move;  // implement the move
       cout << num_objects << " objects remaining.\n";
       current_player = (current_player + 1) % 2;  // switch players
   } while (num_objects > 0);                    
   // ------------  end of the game loop --------------------------
   cout << "Player " << current_player << " wins!!!\n";
   cin.ignore();
   cout << "\nPress enter to quit.\n";
   cin.ignore();
   return 0;
}