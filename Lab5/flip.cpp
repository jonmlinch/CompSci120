/* 
    Jonathan Linch
    Course Section #08
    02/15/24
    Lab 5
    Additional work:
        - No additional work beyond requirements
*/
#include<iostream>
using namespace std;

void flip(int &num1, int &num2);

int main(){
    int num1;
    int num2;
    
    cout << "Please enter the first number to be flipped:" << endl;
    cin >> num1;
    
    cout << "Please enter the second number to be flipped:" << endl;
    cin >> num2;
    
    cout << "Your first number is " << num1 << " and your second number is " << num2 << endl;
    cout << "Flipping..." << endl;
    
    flip(num1, num2);
    
    cout << "Your new first number is " << num1 << " and your new second number is " << num2 << endl;
    cout << "Mission Accomplished!";
    
    return 0;
}

void flip(int &num1, int &num2){
   int numTemp = num1;
   num1 = num2;
   num2 = numTemp;
}


/* Answers to Lab 5 questions:
Question 1) Could you write the code for the definition of the flip() function so that the values of x and y are switched? (so that x becomes 20 and y becomes 7.) Why or why not?
Answer 1): 
As things are laid out in the example, you could not write code to flip the x, y variable values in the flip(). 
The reason for this that when x and y are passed into the flip function we are passing a copied value of x, y but not the original references. 
So when x and y get flipped in the function it has not impact on the original values in the main function. 

Question 2) What do you notice about how the value of x changes after function1() is called?
Answer 2):
After function 1 runs, the logged value of x remains the same as the original value even though it is multiplied by 2 in the function.
However, if I were to log the x variable INSIDE function 1 then I would see a value of 14


Question 3) What do you notice about how the value of x changes after function2() is called?
Answer 3):
The value of x that is logged is 14. This is the value that would be expected from the multiplication by 2 that function 2 does.
This is possible because we are passing a reference to the original value instead of a copy of the value.


Question 4) What is the difference in code between function1() and function2() besides the name of the functions?
Anser 4): 
This dfference in the code is the presence of the & which is used in function 2 and notes that the argument is a reference vs a value. 
With the & we are using a pass-by-reference technique which uses a reference to the actual variable that is passed in. 
Function 1 uses a pass-by-value approach which makes a copy of the values associated with the variable passes as arguments. 

*/