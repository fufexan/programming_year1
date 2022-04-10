/*
 * Fufezan Mihai, 2012, lab07, ex 08
 *
 * Consider a class named Fraction that has two private integer attributes a and
 * b for the denominator and nominator, two set() and get() methods and a
 * method simplify() that will simplify the current calling Fraction object and
 * will return as result a Fraction object. simplify() method will call a
 * private gcd() method to simplify the fraction. Define an explicit
 * constructor without parameters that initializes a with 0 and b with 1. Define
 * another explicit constructor that receives 2 integer parameters. For this
 * constructor is verified if b!=0 before to be called. Define a method named
 * add_fraction() that returns the object obtained by adding the current object
 * with the one received as parameter, as a Fraction object. Define in the same
 * manner the methods that subtract, multiply and divide two fractions.
 * Instantiate two Fraction objects having the corresponding data read from the
 * keyboard. Display the initial attributes and the ones obtained after
 * simplifying the fractions. Call the methods that apply the implemented
 * arithmetical operations and display the results.
 */

#include <iostream>

using namespace std;

class Fraction {
  int a, b;
  int gcd();

public:
  Fraction() {
    a = 0;
    b = 1;
  }
  Fraction(int x, int y) {
    a = x;
    if (y != 0)
      b = y;
    else
      cerr << "\nDenominator can't be 0!\n";
  }

  void setA(int x) { a = x; }
  void setB(int x) { b = x; }
  int getA() { return a; }
  int getB() { return b; }

  Fraction simplify();
  template <class T> Fraction op_fraction(Fraction x, T op);
  Fraction add_fraction(Fraction x) { return op_fraction(x, plus<int>()); }
  Fraction sub_fraction(Fraction x) { return op_fraction(x, minus<int>()); }
  Fraction mul_fraction(Fraction x) {
    return op_fraction(x, multiplies<int>());
  }
  Fraction div_fraction(Fraction x);
};

int main() {
  int x, y;

  cout << "Enter fraction A's numerator and denominator: ";
  cin >> x >> y;
  Fraction a(x, y);

  cout << "Enter fraction B's numerator and denominator: ";
  cin >> x >> y;
  Fraction b(x, y);

  a = a.simplify();
  cout << "\nA simplified: " << a.getA() << " / " << a.getB();

  b = b.simplify();
  cout << "\nB simplified: " << b.getA() << " / " << b.getB();

  Fraction res = a.add_fraction(b);
  cout << "\n\nA + B = " << res.getA() << " / " << res.getB();
  res = a.sub_fraction(b);
  cout << "\nA - B = " << res.getA() << " / " << res.getB();
  res = a.mul_fraction(b);
  cout << "\nA * B = " << res.getA() << " / " << res.getB();
  res = a.div_fraction(b);
  cout << "\nA / B = " << res.getA() << " / " << res.getB();
}

Fraction Fraction::simplify() {
  Fraction res;

  int div = gcd();

  res.setA(a / div);
  res.setB(b / div);

  return res;
}

int Fraction::gcd() {
  int c = a, d = b;

  while (c != d)
    if (c > d)
      c -= d;
    else
      d -= c;

  return c;
}

template <class T> Fraction Fraction::op_fraction(Fraction x, T op) {
  int c, d, e, f;

  e = x.b * a;
  f = b * x.a;

  c = op(e, f);

  d = x.b * b;

  Fraction res(c, d);

  return res.simplify();
}

Fraction Fraction::div_fraction(Fraction x) {
  Fraction res(a * x.b, b * x.a);
  return res;
}
