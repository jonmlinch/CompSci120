// Jonathan Linch
// Course Section #08
// 01/11/24
// Assignment 0
#include<iostream>
using namespace std;

int main(){
  string name_input;
  string mood_input;
  cout << "Hello, what is your name? ";
  cin >> name_input;
  cout << "Hello, " + name_input + "! How are you doing?";
  cin >> mood_input;
  cout << "Ok. Well nice to meet you. Goodbye!" << endl;
}