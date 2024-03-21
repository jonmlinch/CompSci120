/* 
    Jonathan Linch
    Course Section #08
    03/07/24
    Lab 8
    All requirements should be met.
*/
#include <iostream>
#include <fstream>
using namespace std;

//Function Declarations
double highTemp(double high[], int numDays);
double lowTemp(double low[], int numDays);
double avgTemp(double tempArr[], int numDays);
double avgSnowDepthChangeDaily(double snowDepth[], int numDays);

int main() {
  //Creating an array representing each row in the weather data file
  int day[31];
  string month[31];
  int year[31];
  double high[31];
  double low[31];
  double precipitation[31];
  double snow[31];
  double snowDepth[31];
  string headerRow; //This variable will be throw away data to handle 

  //Opening the weather data file
  ifstream weather_file;
  weather_file.open("weather.txt");

  //Use getLine function to throw away the header row
  getline(weather_file, headerRow);

  //Build arrays of data from weather data file
  for(int i = 0; i < 31; i++) {
    weather_file >> day[i];
    weather_file >> month[i];
    weather_file >> year[i];
    weather_file >> high[i];
    weather_file >> low[i];
    weather_file >> precipitation[i];
    weather_file >> snow[i];
    weather_file >> snowDepth[i];
  }

  //Close weather data file
  weather_file.close();

  //Print the various calculations based on the data in the arrays
  cout << "The highest temperature is: " << highTemp(high, 31) << endl;
  cout << "The lowest temperature is: " << lowTemp(low, 31) << endl;
  cout << "The average high temperature is: " << avgTemp(high, 31) << endl;
  cout << "The average low temperature is: " << avgTemp(low, 31) << endl;
  cout << "The average snow depth change daily is: " << avgSnowDepthChangeDaily(snowDepth, 31) << endl;

  
}

double highTemp(double high[], int numDays) {
  double highest = high[0];
  for(int i = 0; i < numDays; i++) {
    if(high[i] > highest) {
      highest = high[i];
    }
  }

  return highest;
}

double lowTemp(double low[], int numDays) {
  double lowest = low[0];
  for(int i = 0; i < numDays; i++) {
    if(low[i] < lowest) {
      lowest = low[i];
    }
  }

  return lowest;
}

double avgTemp(double tempArr[], int numDays) {
  double sum = 0;

  for(int i = 0; i < numDays; i++) {
    sum += tempArr[i];
  }

  return sum / numDays;
}

double avgSnowDepthChangeDaily(double snowDepth[], int numDays) {
  double sum = 0;

  for(int i = 1; i < numDays; i++) {
    sum += snowDepth[i-1] - snowDepth[i];
  }

  return sum / numDays;
}
