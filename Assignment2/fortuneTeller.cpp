// Jonathan Linch
// Course Section #08
// 01/17/24
// Assignment 2
//changes:
    // -
    // -
    // -
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
    int nameNumber;
    string name;
    string earlyAlphabet [13] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m"};
    string lateAlphabet [13] = {"n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

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

    // name[0] = tolower(name[0]);
    char lowerFirstLetter = tolower(name[0]);
    string lowerFirst;
    lowerFirst += lowerFirstLetter;

    for(int i = 0; i < 13; i++){
        if(earlyAlphabet[i] == lowerFirst){
            nameNumber = i;
            break;
        } else if (lateAlphabet[i] == lowerFirst) {
            nameNumber = (2*i);
            break;
        } else {
            nameNumber = (3*i);
        }

    }

    cout << nameNumber << endl;

    

    //A calculation to create a lucky number based on user input
	lucky = (favorite*disliked) % 10;
    int newLucky = ((favorite*disliked) % 10)*nameNumber;
    cout << lucky << endl;
    cout << newLucky << endl;

    //Outputs lucky number for user to see then goes to new line
	cout << endl << "Your secret, lucky number is: " << lucky << endl;

    //Conditionals to determine the user's fortune
	if(lucky < 0){  // conditional, values less than 0
		cout << "Try to be less negative." << endl;
	}
	if(lucky >= 0 && lucky < 50){ // values 0 to 4 inclusive
		cout << "Think bigger!" << endl;
	}
	if(lucky >= 50 && lucky < 90){ // values 5 to 8 inclusive
		cout << "Today you should embrace technology." << endl;
	}
	if(lucky == 90){ // value exactly 9
		cout << "Today is your lucky day!" << endl;
	}
    if(lucky >= 100) {
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