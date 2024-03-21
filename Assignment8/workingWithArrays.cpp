/* 
    Jonathan Linch
    Course Section #08
    03/08/24
    Assignment 8
    All requirements should be met.
*/
#include <iostream>
#include <cmath>
using namespace std;

//Function Declarations
void generate(double data[], int size, double min, double max);
void print(double data[], int size);
double average(double data[], int size);
double min(double data[], int size);
double max(double data[], int size);
void addX(double data[], int size, double x);
int num_Less(double data[], int size);
int num_More(double data[], int size);
int num_Less(double data[], int size, double x);
double range(double data[], int size);
double std_dev(double data[], int size);

int main() {
  int size = 10;
  double data[size];
  double numToAdd;
  double numLessThan;
  
  //Generate my pseudo-random array and print it
  generate(data, size, -5.0, 5.0);
  cout << "Generated array: " << endl;
  print(data, size);

  //Print the average of the array
  cout << "Average: " << average(data, size) << endl;

  //Print the minimum value of the array
  cout << "Minimum: " << min(data, size) << endl;

  //Print the maximum value of the array
  cout << "Maximum: " << max(data, size) << endl;

  //Add a value to the array and print array
  cout << "Enter a value to add to the array: ";
  cin >> numToAdd;
  addX(data, size, numToAdd);
  cout << "Array with " << numToAdd << " added: ";
  print(data, size);

  //Print the number of values less than avg
  cout << "Number of values less than average: " << num_Less(data, size) << endl;
  
  //Print the number of values greater than avg
  cout << "Number of values greater than average: " << num_More(data, size) << endl;

  //Print the number of values less than a given value
  cout << "Enter a value to check for value less than: ";
  cin >> numLessThan;
  cout << "Number of values less than " << numLessThan << ": " << num_Less(data, size, numLessThan) << endl;

  //Print the range of the array
  cout << "Range: " << range(data, size) << endl;

  //Print the standard deviation of the array
  cout << "Standard Deviation: " << std_dev(data, size) << endl;
  
}

//Function to generate an array of pseudo random values
void generate(double data[], int size, double min, double max) {
  for (int i = 0; i < size; i++) {
    double inRangeRandom;
    //Since the % operator only works on int values. Need to use a different method to set range
    double f = (double)rand() / RAND_MAX;
    inRangeRandom = min + f * (max - min);
    
    //Setting the data to the array here transfers to the array in main() because it is pass by reference
    data[i] = inRangeRandom;
  }
}

//Function to print the values of the arrays
void print(double data[], int size) {
  cout << "[ ";
  for (int i = 0; i < size; i++) {
    //This if is used to create rows of 5 values
    if(i%5 == 0 && i > 0) {
      cout << endl;
    }

    // Used to determine whether to add a comma or closing brace
    if(i == size-1) {
      cout << data[i] << " ]" << endl;
    } else {
      cout << data[i] << ", ";
    }
  }
}

//Generates the average of the values in an array
double average(double data[], int size) {
  double sum = 0;

  for (int i = 0; i < size; i++) {
    sum += data[i];
  }

  return sum / size;
}

//Determines and returns the lowest value in an array
double min(double data[], int size) {
  double min = data[0];
  
  for (int i = 0; i < size; i++) {
    if (data[i] < min) {
      min = data[i];
    }
  }

  return min;
}

//Determines and returns the highest value in an array
double max(double data[], int size) {
  double max = data[0];

  for (int i = 0; i < size; i++) {
    if (data[i] > max) {
      max = data[i];
    }
  }

  return max;
}

//Adds a value x to every number in an array
void addX(double data[], int size, double x) {
  for (int i = 0; i < size; i++) {
    data[i] += x;
  }
}

//Determines and returns the number of values less than the avg of the array
int num_Less(double data[], int size) {
  int numLess = 0;
  double avg = average(data, size);

  for (int i = 0; i < size; i++) {
    if (data[i] < avg) {
      numLess++;
    }
  }

  return numLess;
}

//Determines and returns the number of values higher than the avg of the array
int num_More(double data[], int size) {
  int numMore = 0;
  double avg = average(data, size);

  for (int i = 0; i < size; i++) {
    if (data[i] > avg) {
      numMore++;
    }
  }

  return numMore;
}

//Determines and returns the number of values less than the some value x
int num_Less(double data[], int size, double x) {
  int numLess = 0;

  for (int i = 0; i < size; i++) {
    if (data[i] < x) {
      numLess++;
    }
  }

  return numLess;
}

//Determines and returns the range of the values in an array
double range(double data[], int size) {
  double minVal = min(data, size);
  double maxVal = max(data, size);

  return maxVal - minVal;
}

//Determines and returns the standard deviation of the values in the array
double std_dev(double data[], int size) {
  double avg = average(data, size);
  double varianceData[size];
  double variance; //This will be the avg of the varianceData array

  for(int i = 0; i < size; i++) {
    varianceData[i] = pow(data[i] - avg, 2);
  }

  variance = average(varianceData, size);

  return sqrt(variance);
}