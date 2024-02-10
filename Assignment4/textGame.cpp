/* 
    Jonathan Linch
    Course Section #08
    02/09/24
    Assignment 4
    All requirements should be met.
    Variations;
    - Instead of passing an int and using global variable to track health/wealth, I used a struct to tract health/wealth, progress, and dagger acquisition
*/
#include<iostream>

using namespace std;

struct Stats {
    int health;
    int wealth;
    int progress;
    int dagger;
};

//Funtion declarations
void print_health(Stats currentStats);
void print_wealth(Stats currentStats);
Stats room1(Stats currentStats);
Stats room2(Stats currentStats);
Stats room3(Stats currentStats);
Stats room4(Stats currentStats);
Stats start(Stats currentStats);
int end(Stats currentStats);


//Main function to run the program
int main() {
    char start_game;
    int restart_game;
    int chosen_room;
    int health = 100;
    int wealth = 0;
    int turns = 0;
    
    do {
        //Initializing the game values
        Stats playerStats;
        playerStats.health = 100;
        playerStats.wealth = 0;
        playerStats.progress = 0;
        playerStats.dagger = 0;
        
        //Intial story explaining the game
        cout << "Welcome to the mysterious labrynth of Ka'a." << endl;
        cout << "The labrynth will lead you through an elaborant network of rooms each with a set of doors leading deeper into the labrynth." << endl;
        cout << "Choose the right combination of doors and you just might make it out alive. Choose poorly and..." << endl;
        cout << "Well let's just say you wouldn't be the first to see their final moments in the labrynth." << endl;
        cout << endl << "Along the way look out for treasure to build your stash or riches but beware as danger lurks to wear down your health." << endl;
        cout << endl << "Shall we begin? (y/n)" << endl;
        cin >> start_game;
        
        if(start_game == 'y') { //If player chooses 'y' then the game begins, otherwise they die
            cout << endl << "Excellent! Then let us begin!" << endl;
            
            do { //Do-while statement to continue progressing through the game
                switch (playerStats.progress) { //Switch statement to determine which room to access
                    case 0: 
                        playerStats = start(playerStats);
                        break;
                    case 1:
                        playerStats = room1(playerStats);
                        break;
                    case 2:
                        playerStats = room2(playerStats);
                        break;
                    case 3:
                        playerStats = room3(playerStats);
                        break;
                    case 4:
                        playerStats = room4(playerStats);
                        break;
                }
                
            //If player has no health or they reach the end.
            } while (playerStats.health > 0 && playerStats.progress <= 4); 
            
            
            restart_game = end(playerStats); //Display either win or death message and returns user's decision to restart
            
        } else {
            playerStats.health = 0;
            
            restart_game = end(playerStats);
        }
    } while(restart_game == 1);
    

    return 0;
}

//------------ Start function representing the starting room of game ------------
// This function will start the game and the player to room 1 or kill them
Stats start(Stats currentStats) {
    int chosen_room;
    cout << endl << "We begin in a cavernous empty room. The walls are barren gray stone with fleck of mold." << endl;
    cout << "You hear a load 'CRASH!' as the door you entered from closes behind you followed by a quiet but definitive 'klink' signaling that the door is not locked." << endl;
    cout << "Alas, you a different but welcoming door in front of you. What do you do?" << endl;
    cout << "  1. Enter the next room through the new door" << endl;
    cout << "  2. Try desperately to break free through the door you came in from" << endl;
    cout << "Choose 1 or 2: ";
    cin >> chosen_room;
    
    if (chosen_room == 1) { //Choosing 1 moves on to room 1
        cout << "You approach the door hesitantly. Before entering you check on your condition and find you have..." << endl;
        print_health(currentStats);
        print_wealth(currentStats);
        cout << "Now you confidently burst forth into the first room" << endl;
        currentStats.progress = 1; 
    } else { //Any number other than 1 kills the player
        currentStats.health = 0; //A value of 0 signifies death
        currentStats.progress = 5;//A value of 5 ends the game and exits while loop
    }
    return currentStats;
}


Stats room1(Stats currentStats) {
    static int chestOpened = 0;
    int chosen_path;
    int chosen_door;
    
    if(chestOpened == 0) {
        cout << endl << "As your eyes adjust to the darkness of the first room, your face lights up at the site of a treasure chest positioned in the center of the chamber." << endl;
        cout << "You approach the chest and see an inscription that reads: " << endl;
        cout << "   'In this chest lies a treasure the likes of which have never been    " << endl;
        cout << "  known to those of mortal beginnings. It holds the highest of power but   " << endl;
        cout << "       Can only be wielded by one who knows the magic number.'    " << endl;
        cout << endl << "After reading the inscription, what do you do?" << endl;
        cout << "  1. Attempt a guess at the magic number and retrieve your treasure...hopefully" << endl;
        cout << "  2. Continue looking for a way out" << endl;
        cout << "Choose 1 or 2: ";
        cin >> chosen_path;
        
        if (chosen_path != 1 && chosen_path != 2 ) {
            currentStats.health = 0;
            currentStats.wealth = 0;
            return currentStats;
        }
        
        if(chosen_path == 1) {
            int magicNumber;
            chestOpened = 1; //Set that chest has been opened so it cannot be reopened
            cout << "You notice a quill with ink and proceed to write the 'magic number' on the chest. " << endl;
            cout << "What number do you write? (no decimals)" << endl;
            cin >> magicNumber;
            
            cout << "The ink begins to glow then suddenly bursts into a bright flash and... " << endl;
            
            if(magicNumber%2 == 0) {
                cout << "As the flash clears you realize that you have successfully guessed the magic number and the chest is sitting there open." << endl;
                cout << "You peer inside and find a pile of gold along with a dagger. The dagger is small and unassuming but you take it anyway." << endl;
                currentStats.wealth = currentStats.wealth + 100;
                currentStats.dagger = 1;
                print_wealth(currentStats);
            } else {
                cout << "Suddenly, you are surrounded by wing beats of swarm of bats as they descend upon you. They nibble at your flesh stripping you of your health." << endl;
                cout << "When they have had their fill, they move on as quickly as the appeared." << endl;
                currentStats.health = currentStats.health - 20;
                print_health(currentStats);
            }
        } 
    
    }
    
    cout << "You look for an exit to the room and realize there are 2 doors on the far side of the room. Which door will you go through?" << endl;
    cout << "  1. This door is made of heavy gauge metal and looks heavy to move" << endl;
    cout << "  2. This door is made of rainbows and light. An odd make up for a door to be sure." << endl;
    cout << "Choose 1 or 2: ";
    cin >> chosen_door;
    
    if(chosen_door == 1) {
        cout << "You push hard against the metal door, it creaks open, and you enter.";
        currentStats.progress = 2;
    }
    
    if(chosen_door == 2) {
        cout << "You push softly against the rainbow but it doesn't budge so you push harder and harder until suddenly you crash through to the other side." << endl;
        cout << "You take a hard spill landing flat on your face!" << endl;
        currentStats.health = currentStats.health - 10;
        print_health(currentStats);
        currentStats.progress = 3;
    }
    
    if(chosen_door != 1 && chosen_door != 2) {
        currentStats.health = 0;
        currentStats.wealth = 0;
        return currentStats;
    }
    
    return currentStats;
}


//Room 2 - Entered through the metal door in room 1
Stats room2(Stats currentStats) {
    static int previouslyVisited = 0;
    int chosen_door = 1;
    cout << "While the door was a challenge to move, you realize that it was not due to the heaviness of the door but rather due to the room being filled floor to ceiling with chicken nuggets!" << endl;
    cout << "The room is so full of chicken nuggets that you can't see to the other side" << endl;
    
    if(previouslyVisited == 1) {
        cout << "Since you have been to this room before, you decide the only path forward is through the chicken nuggets.";
        chosen_door = 1;
    } else {
        previouslyVisited++;
        cout << "However, you feel a draft suggesting there may be an opening on the other side. What would you like to do?" << endl;
        cout << "  1. Find a way through the nuggets to the other side." << endl;
        cout << "  2. Go back through the door you entered through." << endl;
        cout << "Choose 1 or 2: ";
        cin >> chosen_door;
        
        if(chosen_door != 1 && chosen_door != 2) {
            currentStats.health = 0;
            currentStats.wealth = 0;
            return currentStats;
        }
    }
    
    if(chosen_door == 1) { //Send the player to room room4
        if(currentStats.dagger == 1) {
            cout << "You grab your dagger and slash your way through the pile of nuggets to find...";
        } else {
            cout << "With great stuggle, you manage to eat a path through the mountain of nuggets." << endl;
            currentStats.health += 10;
            print_health(currentStats);
            cout<< "You are tired and full but eventually you find...";
        }
        
        cout << "a giant mouth! It's a vicious mouth full of sharp teeth. You notice the door has a handle which looks like a door knob." << endl;
        cout << "You reach out to open the door when 'SNAP' the door nearly bites you hand off. What do you do?" << endl;
        cout << "  1. Soothe the door with an arm full of nuggets." << endl;
        cout << "  2. Go back through the door you entered through." << endl;
        cout << "Choose 1 or 2: ";
        cin >> chosen_door;
        
        if(chosen_door != 1 && chosen_door != 2) {
            currentStats.health = 0;
            currentStats.wealth = 0;
            return currentStats;
        }
        
        if(chosen_door == 1) {
            cout << "The door relaxes and you try once again to open the door. This time the knob turns and you enter through the door." << endl;
            currentStats.progress = 4;
        }
    }
        
    if(chosen_door == 2) {
        cout << "You turn around and exit back into the room you we just in.";
        currentStats.progress = 1; //Send player back to room 1
    }
    
    
    return currentStats;
}

//Room 3 - Entered through the rainbow door in room 1
Stats room3(Stats currentStats) { //Rainbow door (rm1)
    static int treasureGathered = 0;
    int chosen_door;
    
    if(treasureGathered == 0) {
        cout << "As you gather yourself off the floor. You notice a giant pile of treasure in the middle of the room and behind it an old, crumbly wooden door." << endl;
        cout << "What do you do?" << endl;
        cout << "  1. Gather your treasure." << endl;
        cout << "  2. Go through the creaky old door." << endl;
        cout << "  3. Return the way you came." << endl;
        cout << "Choose 1, 2, 3: ";
        cin >> chosen_door;
    } else {
        cout << "With the treasure gone, the only thing to do is enter the creaky old door. " << endl;
        chosen_door = 2;
    }
    
    
    
    if(chosen_door == 1) {
        cout << "You gather your treasure and add to your collection. " << endl;
        currentStats.wealth += 100;
        print_wealth(currentStats);
        
        cout << "You're now left with 2 options: " << endl;
        cout << "  1. Go through the creaky old door." << endl;
        cout << "  2. Return the way you came." << endl;
        cout << "Choose 1, 2, 3: ";
        cin >> chosen_door;
        chosen_door++; //add one to the choice to match with previous numbering
    }
    
    if(chosen_door == 2) {
        cout << "You approach the old wooden door and when reach for the handle when suddenly it crashes to the ground having fallen off it's hinges." << endl;
        cout << "You shrug your shoulders and enter the room.";
        currentStats.progress = 4;
    }
    
    if(chosen_door == 3) {
        cout << "You turn around and head back." << endl;
        currentStats.progress = 1;
    }
    
    if(chosen_door != 1 && chosen_door != 2 && chosen_door != 3) {
        currentStats.health = 0;
        currentStats.wealth = 0;
    }
    
    return currentStats;
}

//Room 4 - Entered from either the mouth door in Room 2 or the wooden door in Room 3
Stats room4(Stats currentStats) {
    int chosen_door;
    int collectChalace = 0;
    cout << "Inside the room you see a pedestal topped with maginificent chalace covered in jewels." << endl;
    cout << "You also notice 2 doors. The closest door, curiously, has a pile of chicken nuggets strewn in from of it." << endl;
    cout << "The second door is best described as the darkest hole in a wall you have ever seen. You hear the squeak of bats and shudder at the thought of an encounter." << endl;
    cout << "What do you do?" << endl;
    cout << "  1. Collect the chalace from the pedestal." << endl;
    cout << "  2. Explore the closest door with the chicken nuggets." << endl;
    cout << "  3. Enter the dark hole on the other side of the room." << endl;
    cout << "Choose 1, 2, 3: ";
    cin >> chosen_door;
    
    if(chosen_door != 1 && chosen_door != 2 && chosen_door != 3) {
        currentStats.health = 0;
        currentStats.wealth = 0;
    }
    
    cout << "The chosen_door: " << chosen_door << endl;
    
    while(chosen_door == 1) {
        cout << "The collectedChalace: " << collectChalace << endl;
        if(collectChalace < 3) {
            cout << "You reach for the chalace and just as your finger tips connect with bejeweled goblet a lightning bolt strikes you" << endl;
            currentStats.health = currentStats.health - 20;
            print_health(currentStats);
            collectChalace++;
            cout << "What would you like to do now?" << endl;
            cout << "  1. Try again to collect the chalace from the pedestal. Maybe something different will happen." << endl;
            cout << "  2. Explore the closest door with the chicken nuggets." << endl;
            cout << "  3. Enter the dark hole on the other side of the room." << endl;
            cout << "Choose 1, 2, 3: ";
            cin >> chosen_door;
        } else {
            cout << "You gather the chalace and add it to your collection" << endl;
            currentStats.wealth += 1000;
            print_wealth(currentStats);
            chosen_door = 3;
        }
    }
    
    if(chosen_door == 2) {
        cout << "You approach the door and notice that it appears to only move in one direction and you cannot go through it." << endl;
        cout << "You sigh in disappointment and resign yourself to your fate by moving toward the farther door.";
        chosen_door = 3;
    }
    
    if(chosen_door == 3) {
        cout << "You now peer through the dark hole warily but ultimately decide to jump through head first. On the other side you find a giant sign saying..." << endl;
        currentStats.progress = 5;
    }
    
    return currentStats;
}

int end(Stats currentStats) {
    char restart;
    
    if(currentStats.health == 0) {
        cout << "You have made a poor decision and and perished tragically in the labrynth." << endl;
    } else {
        cout << "Congratulations! You survived the labrynth and have proven your valor to all." << endl;
    }
    
    cout << endl << "Would you like to play again? (y/n)" << endl;
    cin >> restart;
    
    if(restart == 'y') {
        return 1;
    } else {
        return 0;
    }
}

void print_health(Stats currentStats) {
    cout << "Health: " << currentStats.health << endl;
}

void print_wealth(Stats currentStats) {
    cout << "Wealth: " << currentStats.wealth << endl;
}

