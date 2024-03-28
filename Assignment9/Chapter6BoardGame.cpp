#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

class square { //Declaration of square class
  private:
    int move;
    string message;
    char symbol;
    int health;
  public:
    square(); //Default constructor
    void print();
    int action();
    int healthCheck();
    void set(int, char, string, int);
};

//Function prototypes
void print_board(square[], int, int, int);
void read_board(square[]);
void check_position(int &);
void check_health(int &);

//Global Variables
const int board_length = 20;

int main() {
  cout << "Welcome to the Talladega 20. A short 20 space race full of high octane action. To play the game, you will be racing a companion across 20 spaces to reach the finish line. Each time you hit Enter on your turn you will move ahead a randomly selected number of space. If you happen to land on the symbolic spaces you will gain (or possibly lose) bonus space. The game starts...NOW! \n\n\n";
  
  int current_player = 1, roll;
  int player1_position = 0, player2_position = 0;
  int player1_health = 10, player2_health = 10;
  square the_board[board_length]; //Declaring an array of squares
  srand(time(NULL));
  read_board(the_board);
  print_board(the_board, player1_position, 1, player1_health);
  print_board(the_board, player2_position, 2, player2_health);

  do {
    cout << "\n\n\nPlayer " << current_player << " type enter to roll. \n";
    cin.ignore();
    roll = 1 + (rand() % 5);
    cout << "Player " << current_player << " rolled a " << roll << ".\n";
    if (current_player == 1) {
      player1_position += roll;
      check_position(player1_position);
      check_health(player1_health);
      player1_position += the_board[player1_position].action();
      player1_health += the_board[player1_position].healthCheck();
      check_position(player1_position);
      check_health(player1_health);
    } else {
      player2_position += roll;
      check_position(player2_position);
      check_health(player2_health);
      player2_position += the_board[player2_position].action();
      player2_health += the_board[player2_position].healthCheck();
      check_position(player2_position);
      check_health(player2_health);
    }
    print_board(the_board, player1_position, 1, player1_health);
    print_board(the_board, player2_position, 2, player2_health);
    current_player = (current_player % 2) + 1;
  } while((player1_position < board_length -1) || (player2_position < board_length - 1));

  if(player1_health > player2_health) {
    current_player = 1;
  }

  if(player1_health < player2_health) {
    current_player = 2;
  }
  
  cout << "\nPlayer " << current_player << " Wins!!\n";
  cin.ignore();
  return 0;
}

//Function Definitions
void read_board(square b[]) {
  ifstream infile;
  infile.open("game.txt");
  int square_number, square_move, square_health;
  string square_message;
  char square_symbol;
  while(!infile.eof()) {
    infile >> square_number >> square_move >> square_symbol >> square_health;
    getline(infile, square_message); //Get the rest of the line
    if(square_number < board_length) {
      b[square_number].set(square_move, square_symbol, square_message, square_health);
    }
  }
}

void print_board(square b[], int player_position, int player_number, int player_health) {
  for(int i = 0; i < board_length; i++) {
    if(i != player_position) {
      b[i].print();
    } else {
      cout << player_number << " ";
    }
  }
  cout << "Goal Health: "<< player_health << endl;
  for(int i = 0; i < board_length; i++) {
    cout << "--|";
  }
  cout << "\n";
}

void check_position(int &p) {
  if(p < 0) {
    p = 0;
  } 

  if(p > board_length) {
    p = board_length - 1;
  }
}

void check_health(int &h) {
  if(h < 0) {
    h = 0;
  } 

  if(h > 10) {
    h = 10;
  }
}

square::square() {
  symbol = ' ';
  move = 0;
  message = "";
  health = 0;
}

int square::action() {
  cout << message << endl;
  return move;
}

int square::healthCheck() {
  return health;
}

void square::print() {
  cout << " " << symbol << " ";
}

void square::set(int m, char s, string msg, int h) {
  move = m;
  symbol = s;
  message = msg;
  health = h;
}