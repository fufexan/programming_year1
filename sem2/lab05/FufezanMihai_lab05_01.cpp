/*
 * Fufezan Mihai, 2012, lab05, ex 01
 *
 * Write a C/C++ application that uses a data structure named Scircle. The
 * structure has an integer variable that represents the circle’s radius.
 *
 * In the main() function that uses the Scircle structure, declare 2 Scircle
 * variables (c1 and c2) and calculate the area and the perimeter (using 2
 * methods) for 2 circles with the value of the radius read from the keyboard.
 *
 * Perform the same operations using a class called Circle (the radius is a
 * private member of the class). The class contains, besides those 2 methods
 * defined in the first application for area and perimeter, an explicit
 * constructor with 1 parameter, a destructor and another method displayRadius()
 * that will be display the radius. Extend the application by defining several
 * Circle objects, pointers to the declared objects and references to those
 * objects. Introduce an accessor method, getRadius() method that allows access
 * to the private radius attribute to display in the main() the radius of
 * objects witout using the dispalyRadius() method.
 */

#include <iostream>

using namespace std;

struct Scircle {
  int radius;
};

float scircle_area(int radius);
float scircle_length(int radius);

class Circle {
private:
  int radius;

public:
  Circle(int r) { radius = r; }
  ~Circle() { radius = 0; }

  float area() { return radius * radius * 3.14; }
  float length() { return radius * 3.14 * 2; }

  float getRadius() { return radius; }
  void setRadius(int r);
  void displayRadius() { cout << "Circle radius is " << radius << '.' << endl; }
};

int main() {
  Scircle c1, c2;

  // read scircles
  cout << "Enter a value for the first circle's radius: ";
  cin >> c1.radius;
  cout << "Area: " << scircle_area(c1.radius)
       << "\nLength: " << scircle_length(c1.radius) << endl;

  cout << "\nEnter a value for the second circle's radius: ";
  cin >> c2.radius;
  cout << "Area: " << scircle_area(c2.radius)
       << "\nLength: " << scircle_length(c2.radius) << endl;

  // same stuff with classes
  float r;
  cout << endl << "Now working with class-based circles." << endl;

  // read radii
  cout << endl << "Enter the first circle's radius: ";
  cin >> r;
  Circle *x1 = new Circle(r);
  x1->displayRadius();
  cout << "Area: " << x1->area();
  cout << "\nLength: " << x1->length() << endl;

  cout << endl << "Enter the second circle's radius: ";
  cin >> r;
  Circle x2(r);
  x2.displayRadius();
  cout << "Area: " << x2.area();
  cout << "\nLength: " << x2.length();

  delete x1;
}

float scircle_area(int radius) { return radius * radius * 3.14; }
float scircle_length(int radius) { return radius * 2 * 3.14; }

void Circle::setRadius(int r) {
  if (radius > 0)
    radius = r;
  else
    cout << "\nCircle can't have 0 or negative radius!";
}
