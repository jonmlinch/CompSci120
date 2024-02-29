/* 
    Jonathan Linch
    Course Section #08
    02/22/24
    Assignment 6
    All requirements should be met.
    Assigned Tasks
    - 
*/

#include <iostream>
using namespace std;

class Rectangle {
  private:
    int width;
    int height;
    int name;
  public:
    Rectangle(int name);
    Rectangle(int w, int h, int name);
    int getWidth();
    int getHeight();
    void setWidth(int w);
    void setHeight(int h);
    void setWidthHeight(int w, int h);
    void printRectangle();
    int calculateArea();
    int calculatePerimeter();
};

Rectangle::Rectangle(int n) {
  name = n;
  width = 0;
  height = 0;
}

Rectangle::Rectangle(int w, int h, int n) {
  name = n;
  
  if(w < 0) {
    w = w * -1;
  }

  if(h < 0) {
    h = h * -1;
  }
  
  width = w;
  height = h;
}

int Rectangle::getWidth() {
  return width;
}

int Rectangle::getHeight() {
  return height;
}

void Rectangle::setWidth(int w) {
  width = w;
}

void Rectangle::setHeight(int h) {
  height = h;
}

void Rectangle::setWidthHeight(int w, int h){
  if(w < 0) {
    w = w * -1;
  }

  if(h < 0) {
    h = h * -1;
  }

  width = w;
  height = h;
}

void Rectangle::printRectangle() {
  cout << "Rectangle " << name << " has: " << endl;
  cout << "Width: " << width << endl;
  cout << "Height: " << height << endl;
}

int Rectangle::calculateArea() {
  return width * height;
}

int Rectangle::calculatePerimeter() {
  return (width * 2) + (height * 2);
}

Rectangle setWidthHeight(int width, int height);
void printRectangle(Rectangle rect);


int main() {
  int width;
  int height;
  
  cout << "Please enter a width for your rectangle: " << endl;
  cin >> width;

  cout << "Please enter a height for your rectangle: " << endl;
  cin >> height;

  Rectangle rect1 = Rectangle(1);
  rect1.setWidthHeight(width, height);
  rect1.printRectangle();
  Rectangle rect2 = Rectangle(width+1, height+1, 2);
  rect2.printRectangle();
  Rectangle rect3 = Rectangle(width+2, height+2, 3);
  rect3.printRectangle();

  cout << "The area of rectangle 1 is: " << rect1.calculateArea() << endl;
  cout << "The perimeter of rectangle 1 is: " << rect1.calculatePerimeter() << endl;
  cout << "The area of rectangle 2 is: " << rect2.calculateArea() << endl;
  cout << "The perimeter of rectangle 2 is: " << rect2.calculatePerimeter() << endl;
  cout << "The area of rectangle 3 is: " << rect3.calculateArea() << endl;
  cout << "The perimeter of rectangle 3 is: " << rect3.calculatePerimeter() << endl;
  
  return 0;
}