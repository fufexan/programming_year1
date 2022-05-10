/*
 * Fufezan Mihai, 2012, lab12, ex 05
 *
 * Overload the extraction and insertion operators for the Complex class (both
 * the imaginary and real parts are represented as protected real values).
 * Create another class named Point that inherits the first class and introduces
 * the color attribute for a point that has as coordinates the real and
 * imaginary parts of the complex number. Overload again the extraction and
 * insertion operators. Create some instances of the defined classes and verify
 * the functionality of the overloaded operators. Assign an object of Point type
 * to an object of Complex type and dispaly the attributes of the obtained
 * object.
 */

#include <iostream>

using namespace std;

class Complex {
protected:
  float re, im;

public:
  friend istream &operator>>(istream &stream, Complex &c);
  friend ostream &operator<<(ostream &stream, const Complex &c);
};

class Point : public Complex {
protected:
  char color;

public:
  friend istream &operator>>(istream &stream, Point &p);
  friend ostream &operator<<(ostream &stream, Point &p);

  void setX(int x) { re = x; }
  void setY(int x) { im = x; }
  float getX() { return re; }
  float getY() { return im; }
};

int main() {
  Complex a;
  Point b;

  cin >> a;
  cout << a << "\n\n";
  cin >> b;
  cout << b << "\n\n";

  cout << "Point accessed from Complex:\n";
  Complex *p = &b;
  cout << *p;
}

istream &operator>>(istream &stream, Complex &c) {
  cout << "Enter a complex number\n";
  cout << "Real: ";
  cin >> c.re;
  cout << "Imaginary: ";
  cin >> c.im;
  cout << "\n";
  return stream;
}
ostream &operator<<(ostream &stream, const Complex &c) {
  return stream << "Real: " << c.re << ", Imaginary: " << c.im;
}

istream &operator>>(istream &stream, Point &p) {
  float x;
  cout << "Enter the position for a point\n";

  cout << "x: ";
  cin >> x;
  p.setX(x);

  cout << "y: ";
  cin >> x;
  p.setY(x);

  cout << "Enter a color for the circle (char): ";
  cin >> p.color;
  cout << "\n";

  return stream;
}
ostream &operator<<(ostream &stream, Point &p) {
  return stream << "x: " << p.getX() << ", y: " << p.getY()
                << ", color: " << p.color;
}
