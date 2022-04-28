/*
 * Fufezan Mihai, 2012, lab10, ex 04
 *
 * Define a class called Triangle with 3 attributes for the triangle sides that
 * has a method that calculates the perimeter of the triangle with the sides
 * introduced from the KB. Another class, Triangle_extended, is derived in
 * public mode from Triangle and defines a method for calculating the triangle’s
 * area. Using objects from both classes call the allowed methods. Verify before
 * to instantiate the objects the possibility to define a Triangle object.
 */

#include <cmath>
#include <iostream>

using namespace std;

class Triangle {
  float a, b, c;

public:
  float perim();

  void setA(float x) { a = x; }
  void setB(float x) { b = x; }
  void setC(float x) { c = x; }

  float getA() { return a; }
  float getB() { return b; }
  float getC() { return c; }
};

class Triangle_extended : public Triangle {
  Triangle t;

public:
  void setT(Triangle x) {
    t.setA(x.getA());
    t.setB(x.getB());
    t.setC(x.getC());
  };

  float area();
};

int main() {
  Triangle t;
  float a, b, c;

  cout << "Enter 3 sides of a triangle: ";
  cin >> a >> b >> c;
  t.setA(a);
  t.setB(b);
  t.setC(c);
  cout << "The perimeter is: " << t.perim() << endl;

  Triangle_extended e;
  e.setT(t);
  cout << "The area is: " << e.area();
}

float Triangle::perim() { return a + b + c; }

float Triangle_extended::area() {
  float p = t.perim() / 2;
  float a = pow(p - t.getA(), 2);
  float b = pow(p - t.getB(), 2);
  float c = pow(p - t.getC(), 2);

  return p * sqrt(a + b + c);
}
