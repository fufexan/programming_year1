/*
 * Fufezan Mihai, 2012, lab05, example
 */

#include <iostream>

using namespace std;

class Circle {
private:
  float radius;
  int xc, yc;

public:
  float length() { return radius * 3.14 * 2; }
  void setRadius(float v) { radius = v; }
  float getRadius() { return radius; }
};

int main() {
  Circle c;
  c.setRadius(5);
  cout << c.length();
}
