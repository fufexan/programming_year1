/*
 * Fufezan Mihai, 2012, lab11, ex 07
 *
 * Write a C++ application that defines the abstract base class
 * AbstractQuadrilateral having as protected attributes four instances of the
 * Point class (a pair of x and y coordinates, getter and setter methods) that
 * represent the quadrilateral’s corners. Declare two pure virtual methods for
 * determining the area and the perimeter of the shape. Implement the derived
 * class ActualQuadrilateral that implements the inherited abstract methods and
 * has another method for determining whether the quadrilateral is a square,
 * rectangle, or irregular quadrilateral. Instantiate the derived class and call
 * the defined methods. The area will be determined depending on the
 * quadrilateral type. The irregularr convex quadrilateral are wil be determined
 * considering the following formula that express the area in terms of the sides
 * a, b, c, d, the semiperimeter s, and the diagonals p, q: A=sqrt
 * {(s-a)(s-b)(s-c)(s-d)-1/4(ac+bd+pq)(ac+bd-pq)}. At the irregularr concave
 * quadrilateral will be determined only the perimeter.
 */

#include <iostream>

using namespace std;

#include "FufezanMihai_lab11_07.hpp"

int main() {
  ActualQuadrilateral aq;
  int x, y;
  Point a, b, c, d;

  cout << "Enter 4 points (x y):\n";

  cout << "Point #1: ";
  cin >> x >> y;
  a.setX(x);
  a.setY(y);

  cout << "Point #2: ";
  cin >> x >> y;
  b.setX(x);
  b.setY(y);

  cout << "Point #3: ";
  cin >> x >> y;
  c.setX(x);
  c.setY(y);

  cout << "Point #4: ";
  cin >> x >> y;
  d.setX(x);
  d.setY(y);

  aq.setPoints(a, b, c, d);

  cout << "\nPerimeter: " << aq.perim();
  float area = aq.area();
  if (area)
    cout << "\nArea: " << area;
}
