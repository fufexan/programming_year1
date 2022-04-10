/*
 * Fufezan Mihai, 2012, lab07, ex 05
 *
 * Write a C/C++ application that reads a point from the keyboard by giving the
 * x, y and z coordinates. Write a method that moves the point with a given
 * distance on each of the three axes. Verify if the line between the first and
 * the second position of the point crosses a third given point.
 */

#include <iostream>

using namespace std;

class Point {
  int x, y, z;

public:
  void setCoord(int coord, char c);
  int getCoord(char c);
  void moveAxis(int distance, char axis);
};

int main() {
  Point a, b, c;
  int x, y, z;
  char ch;

  cout << "Enter the coordinates for a point (x y z): ";
  cin >> x >> y >> z;
  a.setCoord(x, 'x');
  a.setCoord(y, 'y');
  a.setCoord(z, 'z');

  cout << "\nEnter a new value for a coordinate (value coordinate): ";
  cin >> x >> ch;
  b = a;
  b.setCoord(x, ch);

  cout << "\nEnter the coordinates for another point (x y z): ";
  cin >> x >> y >> z;
  c.setCoord(x, 'x');
  c.setCoord(y, 'y');
  c.setCoord(z, 'z');

  char axis = '\0';
  if (c.getCoord('x') == b.getCoord('x'))
    axis = 'x';
  else if (c.getCoord('y') == b.getCoord('y'))
    axis = 'y';
  else if (c.getCoord('z') == b.getCoord('z'))
    axis = 'z';

  if (axis != '\0')
    cout << "\nPoint 1 moved to a position crossing Point 2 on the " << axis
         << " axis.";
  else
    cout << "\nPoint 1 doesn't cross Point 2.";
}

void Point::setCoord(int coord, char c) {
  if (c == 'x')
    x = coord;
  else if (c == 'y')
    y = coord;
  else
    z = coord;
}
int Point::getCoord(char c) {
  if (c == 'x')
    return x;
  if (c == 'y')
    return y;
  return z;
}
void Point::moveAxis(int distance, char axis) {
  if (axis == 'x')
    x += distance;
  else if (axis == 'y')
    y += distance;
  else
    z += distance;
}
