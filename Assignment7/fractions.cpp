/* 
    Jonathan Linch
    Course Section #08
    03/01/24
    Assignment 7
    All requirements should be met.
    Assigned Tasks
    - 
*/

#include <iostream>
using namespace std;

class Fraction {
    private:
        int numerator;
        int denominator;
    public:
        Fraction(int numerator, int denominator);
        int getNumerator();
        int getDenominator();
        void printImproper();
        void printMixed();
        void printDecimal();
};

//Constructor to instantiate Fraction object with numerator and denominator
Fraction::Fraction(int num, int den){
  if (den == 0) {
    numerator = 0;
    denominator = 1;
  } else {
    numerator = num;
    denominator = den;
  }
}

//Getter to access numerator value
int Fraction::getNumerator(){
  return numerator;
}

//Getter to access denominator value
int Fraction::getDenominator(){
  return denominator;
}

//Print improper fraction in format 4/3
void Fraction::printImproper(){
  cout << "The improper value of your fraction is: " << numerator << "/" << denominator << endl;
}

//Print mixed fraction in format 1 1/3
void Fraction::printMixed(){
  cout << "The mixed number value for your fraction is: " <<numerator / denominator << " " << numerator % denominator << "/" << denominator << endl;
}

//Prints a decimal version of the fraciton 1.33333
void Fraction::printDecimal(){
  double doubleNumerator = numerator;
  double doubleDenominator = denominator;

  cout << "The decimal value for your fraction is: " << doubleNumerator/doubleDenominator << endl;
}

//Non-class function declarations
Fraction buildFraction(int numerator, int denominator);
void addFractions(Fraction f1, Fraction f2);
void subtractFractions(Fraction f1, Fraction f2);
void multiplyFractions(Fraction f1, Fraction f2);
void divideFractions(Fraction f1, Fraction f2);

int main() {
  //Variables to enter numerator, denominator and a variable for running program in loop
  int numerator;
  int denominator;
  int restart = 1;
  
  //Do-While loop to allow the program to be run over and over
  do {

    //Entering numerator and denominator values for first fraction
    cout << "Enter a numerator: ";
    cin >> numerator;

    cout << "Enter a denominator: ";
    cin >> denominator;

    //Build first fraction, this function will print required fraction formats
    Fraction fraction1 = buildFraction(numerator, denominator);

    //Entering numerator and denominator for a second fraction
    cout << "Now let's create another fraction!" << endl;
    cout << "Enter a numerator: ";
    cin >> numerator;

    cout << "Enter a denominator: ";
    cin >> denominator;

    //Builds second fraction and prints required formats
    Fraction fraction2 = buildFraction(numerator, denominator);

    //Function to do the math steps on both fractions
    cout << "Now that we have two fractions, let's do some math! \n" << endl;
    addFractions(fraction1, fraction2);
    subtractFractions(fraction1, fraction2);
    multiplyFractions(fraction1, fraction2);
    divideFractions(fraction1, fraction2);

    //Provide user opportunity to restart
    cout << "Would you like to do more math on fractions? (1 for yes, 0 for no): ";
    cin >> restart;
    
  } while (restart == 1);

  cout << "See you next time!";
  return 0;
}

//The function creates instance of fraction, prints it in various formats, then returns it
Fraction buildFraction(int numerator, int denominator) {
  Fraction createdFraction = Fraction(numerator, denominator);
  createdFraction.printImproper();
  createdFraction.printMixed();
  createdFraction.printDecimal();

  return createdFraction;
}

//Adds two fractions
void addFractions(Fraction f1, Fraction f2) {
  int newNumerator;
  int newDenominator;
  
  //Chack if denominator is the same and just add numerators if so, otherwise multiply accordingly to normalize denominators
  if (f1.getDenominator() == f2.getDenominator()) {
    newNumerator = f1.getNumerator() + f2.getNumerator();
    newDenominator = f1.getDenominator();
  } else {
    newNumerator = (f1.getNumerator() * f2.getDenominator()) + (f2.getNumerator() * f1.getDenominator());
    newDenominator = f1.getDenominator() * f2.getDenominator();
  }

  cout << "When we ADD your fractions we get the following breakdown --> \n" << endl;
  buildFraction(newNumerator, newDenominator);
  
}

//Subtracts two fractions
void subtractFractions(Fraction f1, Fraction f2) {
  int newNumerator;
  int newDenominator;

  //Chack if denominator is the same and just add numerators if so, otherwise multiply accordingly to normalize denominators
  if (f1.getDenominator() == f2.getDenominator()) {
    newNumerator = f1.getNumerator() - f2.getNumerator();
    newDenominator = f1.getDenominator();
  } else {
    newNumerator = (f1.getNumerator() * f2.getDenominator()) - (f2.getNumerator() * f1.getDenominator());
    newDenominator = f1.getDenominator() * f2.getDenominator();
  }

  cout << "When we SUBTRACT your fractions we get the following breakdown --> \n" << endl;
  buildFraction(newNumerator, newDenominator);
}

//Multiplies two fractions
void multiplyFractions(Fraction f1, Fraction f2) {
  int newNumerator;
  int newDenominator;
  newNumerator = f1.getNumerator() * f2.getNumerator();
  newDenominator = f1.getDenominator() * f2.getDenominator();

  cout << "When we MULTIPLY your fractions we get the following breakdown --> \n" << endl;
  buildFraction(newNumerator, newDenominator);
  
}

//Divides two fractions
void divideFractions(Fraction f1, Fraction f2) {
  int newNumerator;
  int newDenominator;
  newNumerator = f1.getNumerator() * f2.getDenominator();
  newDenominator = f1.getDenominator() * f2.getNumerator();

  cout << "When we DIVIDE your fractions we get the following breakdown --> \n" << endl;
  buildFraction(newNumerator, newDenominator);
}