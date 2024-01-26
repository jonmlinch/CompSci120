/* 
    Jonathan Linch
    Course Section #08
    01/26/24
    Assignment 2
    Additional work:
        - 
*/
/* Basic Calculator - 
    * a simple program working with Doubles
    * to do basic calculations.
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

	// ------------- Explaining the program -------------------------
	cout << "\n ******** This program is a simple program which allow you, the user, to enter 2 numbers to perform a mathematical calculation along with a 3rd number which represent the desired operation to be performed. ******\n\n\n";
    cout << "So when you are ready, hit ENTER to input your first number  \n";
    cin.ignore();

    //While loop to rerun program logic when an error occurs allowing user to correct mistake
    while(restart == 1) {
        //User prompt an input for first number to be calculated
        cout << "Enter the first number you would like to use in your calculation: \n";
        cin >> num1;

        //User prompt and input for second number to be calculated
        cout << "Now, enter the second number you would like to use in your calculation: \n";
        cin >> num2;

        //User prompt and input for operation to be performed
        cout << "The operator to be used corresponds to a number. \n";
        cout << "     1: + (add) \n";
        cout << "     2: - (subtract) \n";
        cout << "     3: * (multiply) \n";
        cout << "     4: / (divide) \n";
        cout << "Enter the number for operation you would like to do.\n";
        cout << "** NOTE **: The first number entered with be the first used in the operation. \n";
        cin >> operation;

        // Check to see if a valid operator was chosen
        if(operation < 1 || operation > 4) {
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
                    // return 0;
                } else {
                    answer = num1 / num2;
                    cout << num1 << " / " << num2 << " = " << answer << endl;
                }
            }
        }
    }

	// ---------- Code to help the program exit "gracefully" -----
	cin.ignore();
 	cout << "Press enter to quit." << endl;
	cin.ignore();
	return 0;
}