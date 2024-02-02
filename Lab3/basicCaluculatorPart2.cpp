/* 
    Jonathan Linch
    Course Section #08
    02/01/24
    Lab 3
    Additional work:
        - 
*/
/* Basic Calculator (Expanded) - 
    * This program builds on the basic calculator that was built in 
    * Assignment 2 and adds the requirements from Lab 3.
*/
#include<iostream> 
using namespace std;


int main()  
{
	//Defining variables
    double num1;
    double num2;
    double answer;
    int operation;
    int restart = 1;
    int num1Check = 0;
    int num2Check = 0;
    int operationCheck = 0;
    char newCalc[] = "no";

	// ------------- Explaining the program -------------------------
	cout << "\n ******** This program is a simple program which allow you, the user, to enter 2 numbers to perform a mathematical calculation along with a 3rd number which represent the desired operation to be performed. ******\n\n\n";

    //While loop to rerun program logic when an error occurs allowing user to correct mistake
    while(restart == 1) {
        //User prompt an input for first number to be calculated
        cout << "Enter the FIRST number you would like to use in your calculation: \n";
        cin >> num1;
        
        //Check if input is valid, if not then display error
        if(cin.fail()) {
            cin.clear();
            cin.ignore();
            num1Check = 0;
            cout<<"That is not a number. Please try again."<<endl;
        } else {
            //Sets value to determine if num1 variable was correctly set
            num1Check = 1;
        }
        
        //Check if num1 has been set and if set allow input for num2
        if(num1Check) {
            //User prompt and input for second number to be calculated
            cout << "Now, enter the SECOND number you would like to use in your calculation: \n";
            cin >> num2;
            
            //Check if input for num2 valid, if not show error otherwise set check to true and allow progression
            if(cin.fail()) {
                cin.clear();
                cin.ignore();
                num2Check = 0;
                cout<<"That is not a number. Please try again."<<endl;
            } else {
                num2Check = 1;
            }

        }
        
        //Check for both num1 and num2 before allow operation selection
        if(num1Check && num2Check) {
            cout << "The operator to be used corresponds to a number. \n";
            cout << "     1: + (add) \n";
            cout << "     2: - (subtract) \n";
            cout << "     3: * (multiply) \n";
            cout << "     4: / (divide) \n";
            cout << "     5: Sum all integers between selected numbers \n";
            cout << "** NOTE **: The first number entered with be the first used in the operation. \n";
            cout << "Enter the number for OPERATION you would like to do.\n";
            cin >> operation;
            
            //Validate operation input and if valid allow progression
            if(cin.fail()) {
                cin.clear();
                cin.ignore();
                operationCheck = 0;
                cout<<"That is not a number. Please try again."<<endl;
            } else {
                operationCheck = 1;
            }
        } else {
            operationCheck = 0;
        }

        // Check to see if a valid operator was chosen
        if(operationCheck) {
            if(operation < 1 || operation > 5) { //Validate chosen operation is a valid operation
                cout << "That number does not correspond with any of the available operations. Please try again. \n";
            } else {
                restart = 0; //Setting restart to 0 to exit while condition
                if(operation == 1) {
                    answer = num1 + num2;
                    cout << num1 << " + " << num2 << " = " << answer << endl;
                }
    
                if(operation == 2) {
                    answer = num1 - num2;
                    cout << num1 << " - " << num2 << " = " << answer << endl;
                }
    
                if(operation == 3) {
                    answer = num1 * num2;
                    cout << num1 << " * " << num2 << " = " << answer << endl;
                }
    
                if(operation == 4) {
                    if(num2 == 0) {
                        cout << "WARNING: Dividing by 0 will cause an error. Please try again. \n";
                        restart = 1; //Setting restart back to 1 to allow user to retry
                    } else {
                        answer = num1 / num2;
                        cout << num1 << " / " << num2 << " = " << answer << endl;
                    }
                }
                
                //New operation added as part of lab 3
                if(operation == 5) {
                    int highestInt;
                    int lowestInt;
                    
                    //Checking to see which number is higher and setting variables accordingly
                    if(num1 > num2) {
                        highestInt = num1;
                        lowestInt = num2;
                    } else {
                        highestInt = num2;
                        lowestInt = num1;
                    }
                    
                    //For loop to sum all numbers
                    for (int i = lowestInt; i <= highestInt; i++) {
                        if(i == lowestInt) {
                            answer = i;
                        } else {
                            answer = answer + i;
                        }
                    }
                    
                    cout << "The sum of all integers between " << num1 << " and " << num2 << " is: " << answer << endl;
                }
            }
        }

        // Added to program as part of lab 3
        if (restart != 1) {
            cout << "Would you like to do another calculation (y/n)?  ";
            cin >> newCalc;

            switch(newCalc[0]) {
                case 'y':
                case 'Y':
                    restart = 1;
                    break;
                default:
                    restart = 0;
                    break;
            } 
        }
    }

	// ---------- Code to help the program exit "gracefully" -----
	cin.ignore();
 	cout << "Press enter to quit." << endl;
	cin.ignore();
	return 0;
}