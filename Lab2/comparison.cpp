/*
    Jonathan Linch
    Course Section #08
    01/25/24
    Lab 2
    Additional work
    - Create a map which maps all of the expressions to the number in the list
    - Added a prompt which directs user to enter the number of the expression they want the answer to
    - Added an input to collect the user's chosen expresssion
    - Created a conditional which fetches the correct expression from the map and shows the answer
    - Added the ability to use the number 0 to see all of the answers
    - Added condtion which look for 0 and loops through map to show each item in the map
*/
#include<iostream>
#include<map>  //Including map to allow for building of a map
using namespace std;

int main(){
  //Building a map where the key is the number of the expression and the value is the expression
  map<int, int> example_map;
  example_map[1] = 0;
  example_map[2] = -7;
  example_map[3] = -1 + -2;
  example_map[4] = -7 + 7;
  example_map[5] = 7 < 8;
  example_map[6] = 10 > 10;
  example_map[7] = (7 < 10) || (7 > 10);
  example_map[8] = (7 < 10) && (7 > 10);
  example_map[9] = -5 >= 5;
  example_map[10] = (7 > 10) || (-5 == 5);
  example_map[11] = !(6 == 7);
  example_map[12] = (10 != 11) && (7 > 8);
  example_map[13] = (7 == 6) || (7 == 7) || (7 == 8);
  example_map[14] = (6 < (8 && 9));
  example_map[15] = (1 == (6 < 8));
  example_map[16] = (0 == (0 || 1));
  example_map[17] = 6 < (5 + 2);
  example_map[18] = 6 + (5 == 5);
  example_map[19] = (6 < 7) + (7 >= 5);
  example_map[20] = (0 < 7) - (0 < 7);
  example_map[21] = 4 > 4.2;
  example_map[22] = 2 % 3;
  example_map[23] = 2 % 2;

  int selected_example; //Variable to hold an value of chosed expression to see the answer of.

  //Text prompt to show the available expressions to get answers to.
  cout<<"**** Below are 23 examples of Boolean and mathematical expressions **** \n";
  cout<<"    1. 0 \n";
  cout<<"    2. -7 \n";
  cout<<"    3. -1 + -2 \n";
  cout<<"    4. -7 + 7 \n";
  cout<<"    5. 7 < 8 \n";
  cout<<"    6. 10 > 10 \n";
  cout<<"    7. (7 < 10) || (7 > 10) \n";
  cout<<"    8. (7 < 10) && (7 > 10) \n";
  cout<<"    9. -5 >= 5 \n";
  cout<<"    10. (7 > 10) || (-5 == 5) \n";
  cout<<"    11. !(6 == 7) \n";
  cout<<"    12. (10 != 11) && (7 > 8) \n";
  cout<<"    13. (7 == 6) || (7 == 7) || (7 == 8) \n";
  cout<<"    14. (6 < (8 && 9)) \n";
  cout<<"    15. (1 == (6 < 8)) \n";
  cout<<"    16. (0 == (0 || 1)) \n";
  cout<<"    17. 6 < (5 + 2) \n";
  cout<<"    18. 6 + (5 == 5) \n";
  cout<<"    19. (6 < 7) + (7 >= 5) \n";
  cout<<"    20. (0 < 7) - (0 < 7) \n";
  cout<<"    21. 4 > 4.2 \n";
  cout<<"    22. 2 % 3 \n";
  cout<<"    23. 2 % 2 \n";
  cout<<"Enter the number of an expression to see if it resolves to TRUE or FALSE (Enter 0 to see all answers):\n";
  cin>>selected_example;  //Input of chosen expression to be answered


  //Conditional statement to determine whether user selected '0' which would print all answers. Otherwise it prints answer of desired expression
  if(selected_example == 0) {
    for(int i = 1; i <= example_map.size(); i++) {
        if(example_map[i]) {
            cout<<"The answer for number " << i << " is TRUE!\n";
        } else {
            cout<<"The answer for number " << i << " is FALSE!\n";
        }
    }
  } else if (example_map[selected_example]){
    cout<<"The answer for number " << selected_example << " is TRUE!\n";
  } else {
    cout<<"The answer for number " << selected_example << " is FALSE!\n";
  }

  //Exit out of program
  return 0;
}