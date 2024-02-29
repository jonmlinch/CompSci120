/* 
    Jonathan Linch
    Course Section #08
    02/29/24
    Lab 7
    All requirements should be met.
    Assigned Tasks
    - 
*/
#include <iostream>
using namespace std;

double findAverage(int userNum); //Code function declaration, renamed to findAverage
int num; //Global variable for the number entered by the user

int main() {
  //Variable representing the answer
  double answer;

  //Prompt telling the user what the program does and asks for a number to use for average caluclation
  cout << "This program will give you the average of all number between 0 and the number you enter.\n";
  cout << "What's the highest number you would like to include in the average? " << endl;
  cin >> num;

  //Call findAverage to caluculate average based on the number entered by the user
  answer = findAverage(num);

  //Displays the average
  cout << "The average of the numbers between 0 and "<< num << " is:\n";
  cout << answer << "\n\n";

  return 0;
}

double findAverage(int userNum) {
  double calculatedAvg;
  int num; 
  int sum = 0;

  //Find the sum of the numbers between 0 and the number entered by the user
  for (int i = 0; i < userNum; i++) {
    num = i+1; //Removed the need for the user to enter the number, seemed tedious and unneeded
    sum = sum + num;
  }
  
  //Calculate the average and return it
  calculatedAvg = sum / userNum;
  
  return calculatedAvg;
}