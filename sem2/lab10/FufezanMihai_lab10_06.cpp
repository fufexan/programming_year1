/*
 * Fufezan Mihai, 2012, lab10, ex 06
 *
 * Define a class Shape that considers a shape with a name attribute as a
 * pointer to character string. The class will contain a constructor without
 * parameters, one with parameters, copy/move constructors and the assign
 * operator will be overloaded. The class will also have getter/setter methods
 * and a destructor.
 *
 * Derive in public mode a Circle class that adds an int type attribute to the
 * radius and appropriate constructors considering also the attributes (name,
 * radius) and a getter method for the radius and other methods that calculate
 * the area and perimeter of the circle of radius r, value entered in main ()
 * from the keyboard.
 *
 * In the same mode define other classes (Square, Rectangle, etc.) Instantiate
 * objects from the derived classes and display the area and the perimeter. The
 * data will be introduced from the KB.
 *
 * Define a Circle object with parameters introduced from the KB, to copy to a
 * new object and display its attributes.
 *
 * Define a Square object with parameters and another without parameters. Assign
 * the instantiated object with the parameters to the one without parameters and
 * display the attributes.
 */

#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

class Shape {
protected:
  char *name;

public:
  Shape() {}
  Shape(char *name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
  }
  Shape(Shape &s) { *this = s; }
  ~Shape() { delete[] name; }

  void operator=(Shape &s) {
    delete[] name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
  }

  void setName(char *n) {
    delete[] name;
    name = new char[strlen(n) + 1];
    strcpy(name, n);
  }
  char *getName() { return name; }
};

class Circle : public Shape {
  int radius;

public:
  Circle(char *n = (char *)"Unknown", int r = 1) {
    name = n;
    radius = r;
  }
  Circle(Circle &c) { *this = c; }
  void operator=(Circle &c) {
    name = c.getName();
    radius = c.radius;
  }

  void setRadius(int r) { radius = r; }
  int getRadius() { return radius; }

  float length() { return 2 * M_PI * radius; }
  float area() { return radius * radius * M_PI; }
};

class Square : public Shape {
  int length;

public:
  Square(char *n = (char *)"Unknown", int l = 1) {
    name = n;
    length = l;
  }
  Square(Square &s) { *this = s; }
  void operator=(Square &s) {
    name = s.getName();
    length = s.length;
  }

  void setLength(int l) { length = l; }
  int getLength() { return length; }

  float perim() { return 4 * length; }
  float area() { return length * length; }
};

int main() {
  int r, l;
  char name[50];

  cout << "Enter the name and radius of circle C1: ";
  cin >> name >> r;

  Circle c1(name, r);
  Circle c2(c1);

  cout << "\nCircle C2 instantiated from C1 has the attributes:\nName: "
       << c2.getName() << "\nRadius: " << c2.getRadius()
       << "\nLength: " << c2.length() << "\nArea: " << c2.area() << endl;

  cout << "\nEnter the name and length of square S1: ";
  cin >> name >> l;

  Square s1(name, l);
  Square s2;
  s2 = s1;
  cout << "\nSquare S2 instantiated from S1 has the attributes:\nName: "
       << s2.getName() << "\nLength: " << s2.getLength()
       << "\nPerimeter: " << s2.perim() << "\nArea: " << s2.area() << endl;
}
