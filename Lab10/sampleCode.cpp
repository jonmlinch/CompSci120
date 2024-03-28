#include<iostream>
using namespace std;

void fill(int a[][6], int, int);
void increment(int a[][6], int, int);
void printArray(int a[][6], int, int);

int main(){
   int a[3][6]; //ex: {{1-6}, {7-12}, {13-18}}
   fill(a,3,6); // actual array = {{1-6}, {2-12}, {3-18}}
    // 1, 2, 3, 4, 5, 6, 
    // 2, 4, 6, 8, 10, 12, 
    // 3, 6, 9, 12, 15, 18
   increment(a,3,4); // Will increment the values of the first 4 columns in the array by 1 so array is 
  // 2, 3, 4, 5, 5, 6, 
  // 3, 5, 7, 9, 10, 12, 
  // 4, 7, 10, 13, 15, 18
   int *p; 
   p = (int *)a;
   *p = 99; //sets value of a[0][0] to 99
   // 99, 3, 4, 5, 5, 6, 
   // 3, 5, 7, 9, 10, 12, 
   // 4, 7, 10, 13, 15, 18
   p[6] = 77;//sets value of a[1][0] (aka 6th element) to 77
   // 99, 3, 4, 5, 5, 6, 
   // 77, 5, 7, 9, 10, 12, 
   // 4, 7, 10, 13, 15, 18
   p = &a[2][2]; //sets p to the address of a[2][2], current value is 10
   p--; //decrements p to the address of a[2][1], current value is 7
   *p = 66; //sets value of a[2][1] to 66
  // 99, 3, 4, 5, 5, 6, 
   // 77, 5, 7, 9, 10, 12, 
   // 4, 66, 10, 13, 15, 18
   p = (int *)(a[0]+4); //sets p to the address of a[0][4], current value is 5
   *p = 44; //sets the value of a[0][4] to 44
   // 99, 3, 4, 44, 5, 6,
  // 77, 5, 7, 9, 10, 12, 
   // 4, 66, 10, 13, 15, 18
   p = (int *)(a+2); //sets p to the address of a[2][0], current value is 4
   *p = 55; //sets the value of a[2][0] to 55
  // 99, 3, 4, 44, 5, 6,
  // 77, 5, 7, 9, 10, 12, 
   // 55, 66, 10, 13, 15, 18
  printArray(a, 3, 6);
}


void fill(int data[][6], int rows, int columns){
  for(int r = 0; r < rows; r++){
     for(int c = 0; c < columns; c++){
        data[r][c] = (r+1)*(c+1); // ex: a[0][0] = (0+1)*(0+1) = 1, a[0][1] = (0+1)*(1+1) = 2, etc.
     }
  }
  // printArray(data, 3, 6);
  
}

void increment(int data[][6], int rows, int columns){
  for(int r = 0; r < rows; r++){
     for(int c = 0; c < columns; c++){
        data[r][c] += 1;
     }
  }
  // printArray(data, 3, 6);
}

void printArray(int data[][6], int rows, int columns) {
  for(int r = 0; r < 3; r++){
     for(int c = 0; c < 6; c++){
        cout << data[r][c] << ", ";
     }
     cout << endl;  // Why?
   }
}