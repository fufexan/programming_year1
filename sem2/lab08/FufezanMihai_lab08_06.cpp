/*
 * Fufezan Mihai, 2012, lab08, ex 06
 *
 * Write a C++ application that defines a class named Point with the private
 * attributes x and y. Implement a friend function that calculate and display
 * the area and perimeter of different shapes objects defined by two Point
 * parameters P0(x0, y0) and P1(x1, y1). Introduce another parameter named shape
 * that controls the way the two points are used. If we consider a circle, the
 * points delimit the circle’s diameter (shape=1). If we are dealing with a
 * right triangle (shape=2), the points determine the hypotenuse, and the other
 * sides are determined considering the 2 initial points. The point’s
 * coordinates and the shape selection will be realized using parameters
 * introduced from KB.
 */

#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

class Point {
  int x, y;

public:
  friend float dimension(Point p0, Point p1, int shape, char t);
  void setX(int x) { this->x = x; }
  void setY(int y) { this->y = y; }
};

int main() {
  Point a, b;
  int x, y, shape;
  char type;

  cout << "Enter Point A's coordinates: ";
  cin >> x >> y;
  a.setX(x);
  a.setY(y);

  cout << "Enter Point B's coordinates: ";
  cin >> x >> y;
  b.setX(x);
  b.setY(y);

  cout << "\nWhat do you want to calculate?\n"
          "a - area\np - perimeter: ";
  cin >> type;
  cout << "\nWhat shape do you want to calculate the area/perimeter for?\n"
          "1 - circle\n2 - right triangle: ";
  cin >> shape;

  float s = dimension(a, b, shape, type);

  char sh[20], t[20];
  if (shape == 1)
    strcpy(sh, "circle");
  else
    strcpy(sh, "right triangle");
  if (type == 'a')
    strcpy(t, "area");
  else
    strcpy(t, "perimeter");
  cout << "\nThe " << sh << "'s " << t << " is " << s;
}

float dimension(Point p0, Point p1, int shape, char t) {
  // circle variables
  float diameter = sqrt(pow(p1.x - p0.x, 2) + pow(p1.y - p0.y, 2));
  float radius = diameter / 2.0f;

  // triangle variables
  float c1 = abs(p1.x - p0.x);
  float c2 = abs(p1.y - p0.y);
  float hy = sqrt(c1 * c1 + c2 * c2);

  switch (shape) {
  case 1:
    if (t == 'a')
      return radius * radius * M_PI;
    else
      return diameter * M_PI;

    break;

  case 2:
    if (t == 'a')
      return c1 * c2 / 2;
    else
      return c1 + c2 + hy;

    break;

  default:
    return -1;
    cerr << "\nShape unknown!\n";
  }
}
