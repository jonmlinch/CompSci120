/* 
    Jonathan Linch
    Course Section #08
    02/08/24
    Lab 4
    Additional work:
        - No additional work beyond requirements
*/

/* A simple calculator program,
controlled by a menu and 
divided into separate functions */
#include<iostream>
#include <cmath>

using namespace std;
//---------- Function Prototypes -----------
void print_menu();
double get_value(char);
double get_cylinder_radius();
double get_cylinder_height();
void sum(double, double);
void subtract(double, double);
void divide(double,double);
void cylindrical_area(double,double);
void cylindrical_volume(double,double);
void cone_area(double,double);
double num_squared(double);

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
                case 0:// program will exit
                    break;
                case 1:// Addition
                    operand1 = get_value('d');
                    operand2 = get_value('d');
                    sum(operand1, operand2);
                    break;
                case 2:// Subraction
                    operand1 = get_value('d');
                    operand2 = get_value('d');
                    subtract(operand1, operand2);
                    break; 
                case 3:// Division
                    operand1 = get_value('d');
                    operand2 = get_value('d');
                    divide(operand1,operand2);
                    break;
                case 4:// Area of right circular cylinder
                    operand1 = get_value('a');
                    operand2 = get_value('h');
                    cylindrical_area(operand1,operand2);
                    break;
                case 5:// Volume of right circular cylinder
                    operand1 = get_value('a');
                    operand2 = get_value('h');
                    cylindrical_volume(operand1,operand2);
                    break;
                case 6:// Area of right circular cone
                    operand1 = get_value('a');
                    operand2 = get_value('h');
                    cone_area(operand1,operand2);
                    break;
                default:
                    valid_choice = 0;   // choice is invalid
                    cout << "Invalid Choice." << endl;
            }
      }while(choice != 0);    // if not 0, loop back to start
      return 0;
}

//--------------  Functions -------------------
void divide(double dividend, double divisor){
    if(divisor == 0){
        cout << endl << "Dividing by 0 is not allowed!";
    } else {
        double answer = dividend/divisor;
        cout << endl << dividend << " / " << divisor << " = " << dividend/divisor << endl;
    }
}

void sum(double num1, double num2){
    double answer = num1 + num2;
    cout << endl << num1 << " + " << num2 << " = " << num1+num2 << endl;
}

void subtract(double num1, double num2){
    double answer = num1 - num2;
    cout << endl << num1 << " - " << num2 << " = " << num1-num2 << endl;
}

void cylindrical_area(double radius, double height){
    //Using the formula 2πr(r+h)
    double answer = (2 * M_PI * radius) * (radius + height);
    cout << endl << "The formula for area of a right circle cylindar is: 2πr(r+h)"<< endl;
    cout << "2π(" << radius << ")(" << radius << " + " << height << ") = " << answer << endl; 
}

void cylindrical_volume(double radius, double height){
    //Using the formula π(r^2) * h
    double radiusSquared = num_squared(radius);
    double answer = (M_PI * radiusSquared) * height;
    cout << endl << "The formula for volume of a right circle cylindar is: π(r^2)*h"<< endl;
    cout << "π("<< radius<< "^2) * "<< height << " = " << answer << endl; 
}

void cone_area(double radius, double height){
    //Using the formula πr^2 + πr√(r^2 + h^2)
    double radiusSquared = num_squared(radius);
    double heightSquared = num_squared(height);
    double slantHeight = sqrt(radiusSquared + heightSquared);
    double piR = M_PI * radius;
    double answer = (M_PI * radiusSquared) + (piR*slantHeight);
    cout << endl << "The formula for area of a right circle cone is: πr^2 + πr√(r^2 + h^2)"<< endl;
    cout << "π(" << radius << "^2) + π(" << radius << ")√(" << radius << "^2 + " << height << "^2) = " <<answer << endl; 
}

double num_squared(double num) {
    return num * num;
}


//----------------- get_value function ----------------
double get_value(char messageIndicator){
    double temp_value;
    switch(messageIndicator) { //Switch statement to change message when area or volume is used
        case 'a':
            cout << "Please, enter a radius for your cylinder: ";
            break;
        case 'h':
            cout << "Please, enter a height for your cylinder: ";
            break;
        default:
            cout << "Please, enter a value: ";
    }
    cin >> temp_value;   
    cout << "Thanks." << endl;
    return temp_value;
}


//-------------------- print_menu function -------------
void print_menu(){
     cout << endl;
     cout << "Add (1)" << endl;
     cout << "Subtract (2)" << endl;
     cout << "Divide (3)" << endl;
     cout << "Area of a right circle cylinder (4)" << endl;
     cout << "Volume of a right circle cylinder (5)" << endl;
     cout << "Area of a right circle cone (6)" << endl;
     cout << "Exit (0)" << endl;
     cout << "Enter your choice: ";
}