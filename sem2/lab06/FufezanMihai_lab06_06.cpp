/*
 * Fufezan Mihai, 2012, lab06, ex 06
 *
 * Write a C++ application that defines a class called Triangle. The class
 * contains as private int variables the triangle's sides a, b and c, a
 * constructor with parameters and adequate setter and getter methods. The class
 * will contain methods that will calculate the shape's area and perimeter.
 * Write a distinct method that will print a specific message if the triangle is
 * right. Develop a private method with parameters that will determine whether
 * the values of a, b and c form a triangle. The method will be called in setter
 * methods.
 */

#include <cmath>
#include <iostream>

using namespace std;

class Triangle {
  int a, b, c;
  bool isTriangle(int a, int b, int c);

public:
  Triangle(int a = 0, int b = 0, int c = 0) {
    this->a = a;
    this->b = b;
    this->c = c;
  }

  void setTriangle(int a, int b, int c);

  double area();
  double perimeter();

  bool right();
};

int main() {
  int a, b, c;

  cout << "Enter the 3 sides of a triangle: ";
  cin >> a >> b >> c;
  Triangle tri;
  tri.setTriangle(a, b, c);

  tri.right();
  cout << "\nPerimeter: " << tri.perimeter();
  cout << "\nArea: " << tri.area();
}

bool Triangle::isTriangle(int a, int b, int c) {
  if (a + b > c && a + c > b && b + c > a)
    return true;
  return false;
}

void Triangle::setTriangle(int a, int b, int c) {
  if (isTriangle(a, b, c)) {
    this->a = a;
    this->b = b;
    this->c = c;
  } else
    cout << "\nCoordinates don't form a triangle!\n";
}

double Triangle::area() {
  double p = perimeter() / 2;
  return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::perimeter() { return a + b + c; }

bool Triangle::right() {
  if (a * a + b * b == c * c || b * b + c * c == a * a ||
      a * a + c * c == b * b) {
    cout << "\nTriangle is right!\n";
    return true;
  }

  return false;
}
