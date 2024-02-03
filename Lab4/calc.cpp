/* 
    Jonathan Linch
    Course Section #08
    02/08/24
    Lab 4
    Additional work:
        - 
*/

/* A simple calculator program,
controlled by a menu and 
divided into separate functions */
#include<iostream>
using namespace std;
//---------- Function Prototypes -----------
void print_menu();
double get_value();
double divide(double,double);
//--------------  Main -------------------
int main()
{
     double operand1, operand2, answer;
     int choice, valid_choice;
     do{
           print_menu();
           cin >> choice;
           valid_choice = 1;           // assume choice is valid
           switch(choice){
           case 0:                    // program will exit
                  break;
           case 1:                    // addition
                  operand1 = get_value();
                  operand2 = get_value();
                  answer = operand1 + operand2;
                   break;
            case 2:                    // division
                   operand1 = get_value();
                   operand2 = get_value();
                   answer = divide(operand1,operand2);
                   break;
            default:
                   valid_choice = 0;   // choice is invalid
                   cout << "Invalid Choice." << endl;
            }
            if(valid_choice){   // if choice is valid, print the answer
                   cout << endl << "Answer = " << answer << endl;
            }
      }while(choice != 0);    // if not 0, loop back to start
      return 0;
}

//--------------  Functions -------------------
double divide(double dividend, double divisor){
      if(divisor == 0){
            return 0;  // avoids divide by zero errors
      }
      else
            return (dividend/divisor);
}
//----------------- get_value function ----------------
double get_value(){
      double temp_value;
      cout << "Please, enter a value: ";
      cin >> temp_value;
      cout << "Thanks." << endl;
      return temp_value;
}
//-------------------- print_menu function -------------
void print_menu(){
     cout << endl;
     cout << "Add (1)" << endl;
     cout << "Divide (2)" << endl;
     cout << "Exit (0)" << endl;
     cout << "Enter your choice: ";
}