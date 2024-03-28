#include<iostream>
using namespace std;

int func(int, int &);
void func2(int, int []);

int main(){
   int x = 99, y = 55;
   int a[5] = {1,2,3,4,5};
   int *p;
   p = a;
   p++;
   *p = 8; //{1,8,3,4,5}
   p = &a[3]; //Sets pointer to address of a[3]
   *p = 12; //Since p is at a[3], array is {1,8,3,12,5} 
   p--; //Go back a spot on the array, so p is at a[2]
   *p = 11; //Set a[2] = 11, array is {1,8,11,12,5}
   a[0] = func(x,y); //Sets a[0] to returned value of function so array is {102,8,11,12,5}
   func2(x,a); //Passes x by value and a as a reference. The function changes a[4] to 456. array is {102,8,11,12,456}
   cout << "x = " << x << endl;
   cout << "y = " << y << endl;
   for(int i = 0; i < 5; i++){
      cout << "a[" << i << "] = " << a[i] << endl;
   }
}

int func(int a, int &b){
   a = 100;
   b = 101;
   return 102;
}

void func2(int a, int b[]){
   a = 123;
   b[4] = 456;
}