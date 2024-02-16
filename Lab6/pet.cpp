/* 
    Jonathan Linch
    Course Section #08
    02/22/24
    Assignment 5
    All requirements should be met.
    Assigned Tasks
    - 
*/

#include<iostream>
#include<string>
using namespace std;
// declaration of the pet class
class pet{
   private:
      int hunger;           // private data member
      string name;          // private data member
      int happy;            // private data member
      int needToPoop; //New data member
   public:
      pet();                // constructor
      void play();          // public member function
      void feed();          // public member function
      void print();         // public member function
      int check_health();   // public member function
      void letOut(); //New public member to interact with needToPoop
};
int main()
{
   pet pet1;
   int choice;
   int health_check;
   do{
       pet1.print();
       cout << "What would you like to do with your pet?\n";
       cout << " Play (1) \n Feed (2) \n Let the Pet Out to Poop (3) \n Exit (0) \n";
       cin >> choice;
       switch(choice){
       case 0: //Adding switch case for when user enters 0
            cout << "Well we hate to see you go!" << endl;
            break;
       case 1:
           pet1.play();
           break;
       case 2:
           pet1.feed();
           break;
       case 3:
            pet1.letOut();
            break;
      }
      health_check = pet1.check_health();
   }while(choice != 0 && health_check != 1);
   cin.ignore();
   cout << "Press enter to exit." << endl;
   cin.ignore();
   return 0;
}

/* Constructor, creates a new pet with starting values. */
pet::pet(){
     hunger = 50;
     happy = 50;
     needToPoop = 0;
     cout << "Pet's name? (One word) ";
     cin >> name;
}
/* Member function play(), allows playing with a pet. */
void pet::play(){
    int choice = 0;
    cout << "What should we play?\n";
    cout << " Fetch (1) \n Roll over (2) \n";
    cin >> choice;
    switch(choice){
    case(1):
         happy += 10;
         hunger += 5;
         needToPoop += 2; //Sometimes running makes you need to poop
         break;
    case(2):
         happy += 5;
         hunger += 1;
         needToPoop += 1; //All that rolling has got to stir up something
         break;
    default:
         cout << "Not a valid choice." << endl;
   }
}

/* Member function feed(), allows the user to feed a pet. */
void pet::feed(){
    cout << "\nMMM, Yummy!\n";
    hunger -= 5;
    needToPoop += 4;
}

/* Member function print(), prints information about a pet. */
void pet::print(){
    cout << "\nYour pet " << name << " is ";
    
    if(happy >= 75) {
        cout << "ECSTATIC to be alive! What a day!" << endl;
    }
    
    if(happy >= 25 && happy < 75) {
        cout << "doing alright. Everything is just...fine." << endl;
    }
    
    if(happy < 25) {
        cout << "a mopey sack and really needs a pick me up." << endl;
    }
    cout << "Happy: " << happy << endl;
    
    cout<< "Also, your pet is ";
    if(hunger >= 75) {
        cout << "STARVING!!! Feed them you negligent nincompoop." << endl;
    }
    if(hunger >= 25 && hunger < 75) {
        cout << "honestly always hungry and would eat if given the chance." << endl;
    }
    if(hunger < 25) {
        cout << "pretty full! If you feed them more they might explode." << endl;
    }
    cout << "Hungry: " << hunger << endl;
    
    cout<<"And lastly, they ";
    
    if(needToPoop >= 10) {
        cout << "need to GO! Like...now. Before there's a big ol' mess to clean up." << endl;
    }
    if(needToPoop >= 5 && needToPoop < 10) {
        cout << "would mind a jaunt to the outhouse if you know what I mean." << endl;
    }
    if(needToPoop < 5) {
        cout << "feel like they could hold it forever." << endl;
    }
    cout << "Need To Poop: " << needToPoop << endl;
}

/* Member function check_health(), checks the health of a pet. */
int pet::check_health(){
    if(hunger >= 100){
         cout << "\nYour pet has starved.\n";
         return 1;
    }
    if(happy <= 0){
         cout << "\nYour pet has died of a broken heart.\n";
         return 1;
    }
    return 0;
}

void pet::letOut() {
    if (needToPoop < 10) {
        cout << "Things aren't ready yet!" << endl;
    }
    
    if (needToPoop >= 10) {
        cout << "You let the dog out to poop and it has great success!" << endl;
        needToPoop = 0;
    }
    
}