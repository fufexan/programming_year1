/*
 * Fufezan Mihai, 2012, lab10, ex 07
 *
 * Consider a base class Circle defined by a protected attribute radius, that
 * contains a constructor with parameters and a method that will determine the
 * area of the circle. Consider other base class, Square with a protected
 * attribute, length, similar to Circle class. Derive in public mode the class
 * RoundSquare from both classes that will contain a constructor that will call
 * the constructors from base classes and a method that will verify if the
 * square of length l may be included in the circle of radius r. The derived
 * class will also determine the perimeter of both shapes. Instantiate an object
 * from the derived class (data from the KB) and determine the area and
 * perimeter of the composed shapes. Display a message if the square may be
 * included in the circle.
 */

#include <cmath>
#include <iostream>

using namespace std;

class Circle {
protected:
  char *name;
  int radius;

public:
  Circle() = default;
  Circle(char *n, int r) : name(n), radius(r) {}
  Circle(Circle &c) : name(c.name), radius(c.radius) {}
  ~Circle() = default;

  void operator=(Circle &s) {
    name = s.getName();
    radius = s.radius;
  }

  void setName(char *n) { name = n; }
  char *getName() { return name; }
  void setRadius(int r) { radius = r; }
  int getRadius() { return radius; }

  float length() { return 2 * M_PI * radius; }
  float area() { return radius * radius * M_PI; }
};

class Square {
protected:
  char *name;
  int length;

public:
  Square() = default;
  Square(char *n, int l) : name(n), length(l) {}
  Square(Square &s) : name(s.name), length(s.length) {}
  ~Square() = default;

  void operator=(Square &s) {
    name = s.getName();
    length = s.length;
  }

  void setName(char *n) { name = n; }
  char *getName() { return name; }
  void setLength(int l) { length = l; }
  int getLength() { return length; }

  float perim() { return 4 * length; }
  float area() { return length * length; }
};

class RoundSquare : public Square, public Circle {
  Square s;
  Circle c;

public:
  RoundSquare(char *n, int r, int l) : s(n, l), c(n, r){};

  bool squareFitsInCircle();
  void display();
};

int main() {
  int r, l;
  char name[50];

  cout << "Enter a name and radius for a circle: ";
  cin >> name >> r;
  Circle c(name, r);

  cout << "Enter a name and length for a square: ";
  cin >> name >> l;
  Square s(name, l);

  RoundSquare rs(name, r, l);
  cout << "\nThe square does " << (rs.squareFitsInCircle() ? "" : "not ")
       << "fit in the circle.\n";
  rs.display();
}

bool RoundSquare::squareFitsInCircle() {
  float hy = s.getLength() * M_SQRT2 / 2.0f;

  return hy <= c.getRadius();
}

void RoundSquare::display() {
  cout << "\nName: " << s.getName();
  cout << "\nCircle radius: " << c.getRadius();
  cout << "\nSquare length: " << s.getLength();
}
