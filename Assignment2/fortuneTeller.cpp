/* 
    Jonathan Linch
    Course Section #08
    01/17/24
    Assignment 2
    Additional work:
        - Created 4 new variables: nameNumber, name, earlyAlphabet, and lateAlphabet
        - Added a for loop to compare the lowercased first letter of the name variable to find a match in one of the arrays.
        - Depending on where a match is (or isn't) found, the nameNumber variable is set which is then used to calculate the lucky number
        - Changed the parameters for fortune phrases to higher numbers due to change in lucky number parameter
        - instead of adding an additional phrase, I added an ascii image
*/
/* The fortune Teller -
    * a simple program introducing some
    * fundamental programming concepts.
    */
#include<iostream> // include a library
using namespace std;
int main()  // main() starts the program
{
	// -------------- Variable Declarations ------------------
 	int favorite;  // create a variable to store the favorite number
    int disliked;  // create a variable to store the disliked number
	int lucky;     // create a variable to store the lucky number
    int nameNumber; // variable to store a number derived from the name of the user
    string name; // variable to store a text string for name of user 
    char earlyAlphabet [13] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'}; // Array of letters used for comparison
    char lateAlphabet [13] = {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; // Different array of letters for comparison

	// ------------- Get user input -------------------------
    //User prompt and input for favorite num, Int
	cout << "Enter your favorite number (no decimals): \n";
	cin >> favorite;

    //User prompt and input for least favorite num, Int
	cout << "Enter a number you don't like (no decimals): \n";
	cin >> disliked;

    //User prompt and input for user's name, String
    cout << "Enter your name: \n";
    cin >> name;

    //Loops through charater arrays to see if a character matches the lower case version of a users name
    for(int i = 0; i < 13; i++){
        if(earlyAlphabet[i] == tolower(name[0])){
            nameNumber = i;
            break;
        } else if (lateAlphabet[i] == tolower(name[0])) {
            nameNumber = (2*i);
            break;
        } else {
            nameNumber = (3*i);
        }

    }

    //A calculation to create a lucky number based on user input
	lucky = ((favorite*disliked) % 10)*nameNumber;

    //Outputs lucky number for user to see then goes to new line
	cout << endl << "Your secret, lucky number is: " << lucky << endl;

    //Conditionals to determine the user's fortune
	if(lucky < 0){  // conditional, values less than 0
		cout << "Try to be less negative." << endl;
	}
	if(lucky >= 0 && lucky < 25){ // values 0 to 24 inclusive
		cout << "Think bigger!" << endl; 
	}
	if(lucky >= 25 && lucky < 50){ // values 25 to 49 inclusive
		cout << "Today you should embrace technology." << endl; 
	}
	if(lucky >= 50 && lucky < 75){ // values 50 to 74 inclusive
		cout << "Today is your lucky day!" << endl; 
	}
    if(lucky >= 75) { // Any number greater than 100 sees an ascii "LUCKY"
        cout<< " __        _    _   ____   __   __  __    __ \n";
        cout<< "|  |      | |  | | / ___\\ |  | / /  \\ \\  / / \n";
        cout<< "|  |      | |  | || |     |  |/ /    \\ \\/ / \n";
        cout<< "|  |____  | |__| || |____ |     \\     |  | \n";
        cout<< "|_______|  \\_____/ \\____/ |__|\\__\\    |__| \n";
    }
	// ---------- Code to help the program exit "gracefully" -----
	cin.ignore();
 	cout << "Press enter to quit." << endl;
	cin.ignore();
	return 0;
}