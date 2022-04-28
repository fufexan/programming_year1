/*
 * Fufezan Mihai, 2012, lab10, ex 03
 *
 * Implement a class that has 2 protected integer variables, that contains a
 * setter and getter methods for each attribute. Write a second class that
 * inherits the first defined class and implements the elementary arithmetic
 * operations (+, -, *, /) applied on the variables mentioned above the results
 * being returned by methods. Write a third class derived from the second one
 * that implements the methods for calculating the square root of a number (mul
 * result obtained by the previous derived class) received as parameter, and for
 * raising a numeric value to a certain power (the base (plus, result obtained
 * by the previous derived class) and the power (minus, result obtained by the
 * previous derived class) are sent to the method as parameters). Verify the
 * methods’s calling using objects at different hierarchy levels.
 */

#include <cmath>
#include <iostream>

using namespace std;

class Base {
protected:
  int a, b;

public:
  Base(int x = 1, int y = 0) {
    a = x;
    b = y;
  }
  void setA(int x) { a = x; }
  void setB(int x) { b = x; }
  int getA() { return a; }
  int getB() { return b; }
};

class Derived : public Base {
protected:
  Base d;

public:
  Derived(Base x = {1, 1}) { setD(x); }

  int getA() { return d.getA(); }
  int getB() { return d.getB(); }

  void setD(Base x) {
    d.setA(x.getA());
    d.setB(x.getB());
  }
  Base getD() { return d; }

  void operator=(Derived x) {
    d.setA(x.getA());
    d.setB(x.getB());
  }
  Base operator+(Base x) {
    Base res;
    res.setA(res.getA() + x.getA());
    res.setB(res.getB() + x.getB());
    return res;
  }
  Base operator-(Base x) {
    Base res;
    res.setA(res.getA() - x.getA());
    res.setB(res.getB() - x.getB());
    return res;
  }
  Base operator*(Base x) {
    Base res;
    res.setA(res.getA() * x.getA());
    res.setB(res.getB() * x.getB());
    return res;
  }
  Base operator/(Base x) {
    Base res;
    res.setA(res.getA() / x.getA());
    res.setB(res.getB() / x.getB());
    return res;
  }
};

class Powers : public Derived {
protected:
  Derived d;

public:
  Powers() {}
  Powers(Powers &x) { d = x.getD(); }
  int getA() { return d.getA(); }
  int getB() { return d.getB(); }

  void operator=(Powers x) {
    d.setA(x.getA());
    d.setB(x.getB());
  }
  void setD(Derived x) { d.setD(x.getD()); }

  Base sqrt(Base x) {
    Base y;
    y.setA(std::sqrt(x.getA()));
    y.setB(std::sqrt(x.getB()));
    return y;
  }

  Base pow(Base base, Base exp) {
    Base y;
    y.setA(std::pow(base.getA(), exp.getA()));
    y.setB(std::pow(base.getB(), exp.getB()));
    return y;
  }
};

int main() {
  int a, b;

  cout << "Enter 2 numbers for the object x: ";
  cin >> a >> b;

  Base x;
  x.setA(a);
  x.setB(b);

  cout << "Enter 2 numbers for the object y: ";
  cin >> a >> b;

  Base y;
  y.setA(a);
  y.setB(b);

  Derived d;
  d.setD(x);

  Derived c;
  c.setD(d + y);
  cout << "\nx + y = " << c.getA() << ' ' << c.getB();
  c.setD(d - y);
  cout << "\nx - y = " << c.getA() << ' ' << c.getB();
  c.setD(d * y);
  cout << "\nx * y = " << c.getA() << ' ' << c.getB();
  c.setD(d / y);
  cout << "\nx / y = " << c.getA() << ' ' << c.getB();
  Powers p;
  p.setD(d);
  c.setD(p.sqrt(x));
  cout << "\nsqrt(x) = " << c.getA() << ' ' << c.getB();
  c.setD(p.pow(x, y));
  cout << "\nx ^ y = " << c.getA() << ' ' << c.getB();
}
