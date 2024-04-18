#include <iostream>
#include <cstdlib>
using namespace std;

void printInstructions(int boardSize);
void printBoard(char** board, int boardSize);
void printAnswerBoard(int** board, int boardSize);
int updateBoard(char** board, int** answerBoard, int x, int y, int * foundGophers);
void setGophers(int** board, int boardSize, int * gopherCount);
int getGopher();
int countGophers(char** board, int boardSize);
void autoWin (char** board, int** answerBoard, int boardSize);

int main() {
  int boardSize = 10;
  int xCoordinate;
  int yCoordinate;
  int gopherCount = 0;
  int foundGophers = 0;
  int** answerBoard = new int*[boardSize];
  char** board = new char*[boardSize]; //Initialize an array of pointers to pointers
  for (int i = 0; i < boardSize; i++) {
    board[i] = new char[boardSize]; //Initalize each pointer to point to an array of integers
    for (int j = 0; j < boardSize; j++) {
      board[i][j] = 'x';
    }
  }
  setGophers(answerBoard, boardSize, &gopherCount);
  // printAnswerBoard(answerBoard, boardSize);

  printInstructions(boardSize);
  cout << "The gopher count is: " << gopherCount << endl;

  printBoard(board, boardSize);

  while (foundGophers < gopherCount) {
    cout << "Enter the x (row) coordinate: ";
    cin >> xCoordinate;
    cout << "Enter the y (column) coordinate: ";
    cin >> yCoordinate;

    if (xCoordinate >= 0 && xCoordinate < boardSize && yCoordinate >= 0 && yCoordinate < boardSize) {
      int gopherCheck = updateBoard(board, answerBoard, xCoordinate, yCoordinate, &foundGophers);
      if (gopherCheck == 0) {
        foundGophers = countGophers(board, boardSize);
        cout << "The total gophers found is: " << foundGophers << endl;
        cout << "There are " << gopherCount - foundGophers << " gophers left to find" << endl;
      } else {
        foundGophers = gopherCount + 1;
      }
      
      printBoard(board, boardSize);
      
    } else if (xCoordinate == 1001 && yCoordinate == 1001) { //Adding cheat to easily show win condition
      autoWin(board, answerBoard, boardSize);
      foundGophers = countGophers(board, boardSize);
      cout << "The total gophers found is: " << foundGophers << endl;
      cout << "There are " << gopherCount - foundGophers << " gophers left to find" << endl;
      printBoard(board, boardSize);
    } else {
      cout << "Invalid coordinates. Please try again." << endl;
    }
  }

  if (foundGophers == gopherCount) {
    cout << "Congratulations!!! You found all the gophers!" << endl;
  } else {
    cout << "You stepped right on a gopher. It captured you and drug you into it's burrow where you are consumed by the whole colony. Better luck next time!" << endl;
  }
  
  return 0;  
}

void printInstructions(int boardSize){
  cout << "Welcome to the Gopher Game!\n\n";
  cout << "There are gopher hiding all over the field. Your mission is to find all of the gophers without stepping on any of them.\n\n";
  cout << "You will be asked to enter a row and column number. The row and column numbers are between 0 and " << boardSize - 1 << "\n\n";
  cout << "As you move across the board, gophers will be represented by a 1. A 0 mean no gopher is on that spot.If you land on space without a gopher then any gophers in neighboring squares will be revealed.\n\n";
  
}

void printBoard(char** board, int boardSize) {
  for (int i = 0; i < boardSize +1; i++) {
    if (i == 0) {
      cout << "   ";
    } else {
      cout << i - 1 << "  ";
    }
    
    for (int j = 0; j < boardSize; j++) {
      if (i == 0) {
        cout << " " << j << " ";
      } else {
        cout << " " << board[i-1][j] << " ";
        // cout << " x ";
      }
    }
    cout << "\n";
  }
}

void printAnswerBoard(int** board, int boardSize) {
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      cout << " " << board[i][j] << " ";
    }
    cout << "\n";
  }
}

int updateBoard(char** board, int** answerBoard, int x, int y, int * foundGophers) {
  int gophersFound = 0;
  // int zeroCount = 0;
  if(answerBoard[x][y] == 1) {
    board[x][y] = '1';
    return 1;
  } else {
    board[x][y] = '0';
    for (int i = x - 1; i <= x + 1; i++) {
      if (i >= 0 && i < 10) {
        for (int j = y - 1; j <= y + 1; j++) {
          if (answerBoard[i][j] == 1 && j >= 0 && j < 10) {
            gophersFound++;
            board[i][j] = '1';
          } 
        }
      }
    }

    if (gophersFound == 0) {
      for (int i = x - 1; i <= x + 1; i++) {
        if (i >= 0 && i < 10) {
          for (int j = y - 1; j <= y + 1; j++) {
            if (answerBoard[i][j] == 0 && board[i][j] != '0' && j >= 0 && j < 10) {
              board[i][j] = '0';
              updateBoard(board, answerBoard, i, j, foundGophers);
            } 
          }
        }
      }
    }

    return 0;
  }
}

void setGophers(int** board, int boardSize, int* gopherCount) {
  for (int i = 0; i < boardSize; i++) {
    board[i] = new int[boardSize];
    for (int j = 0; j < boardSize; j++) {
      int gopher = getGopher();
      board[i][j] = gopher;
      if(gopher == 1) {
        *gopherCount += 1;
      }
    }
  }
}

int getGopher() {
  if (rand() % 2 == 1) {
      return rand() % 2;
  } else {
      return 0;
  }
}

int countGophers(char** board, int boardSize) {
  int gopherCount = 0;
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      if (board[i][j] == '1') {
        gopherCount++;
      }
    }
  }

  return gopherCount;
}

void autoWin (char** board, int** answerBoard, int boardSize) {
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      if (answerBoard[i][j] == 1) {
        board[i][j] = '1';
      } else {
        board[i][j] = '0';
      }
    }
  }
}

