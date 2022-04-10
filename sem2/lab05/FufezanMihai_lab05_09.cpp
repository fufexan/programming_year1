/*
 * Fufezan Mihai, 2012, lab05, ex 09
 *
 * Declare a class named Fraction that has two private integer attributes a and
 * b representing a fraction’s numerator and denominator. Define two setter and
 * getter methods for the class’s attributes. Create 2 Fraction instances and
 * display the initial attributes and the ones established after using the
 * setter methods. Define a method named simplify() that determines and
 * displays all the common dividers of the nominator and denominator, simplifies
 * the fraction and prints in the method the final result (new fraction
 * numerator/ denominator).
 */

#include <iostream>

using namespace std;

class Fraction {
  int a, b;

public:
  void setA(int x) { a = x; }
  void setB(int x) { b = x; }
  int getA() { return a; }
  int getB() { return b; }

  Fraction simplify();
};

int gcd(int a, int b);

int main() {
  Fraction a, b;
  int x, y;

  cout << "Enter a fraction's numerator and denominator: ";
  cin >> x >> y;
  a.setA(x);
  a.setB(y);

  cout << "Enter another fraction's numerator and denominator: ";
  cin >> x >> y;
  b.setA(x);
  b.setB(y);

  cout << endl << "Fraction 1:\nDivisors: ";
  a.simplify();

  cout << endl << "Fraction 2:\nDivisors: ";
  b.simplify();
}

Fraction Fraction::simplify() {
  Fraction res;

  cout << endl;
  int div = gcd(a, b);

  res.setA(a / div);
  res.setB(b / div);

  cout << endl
       << "Simplified fraction: " << a << "/" << b << " -> " << res.a << "/"
       << res.b << endl;

  return res;
}

int gcd(int a, int b) {
  while (a != b)
    if (a > b) {
      a -= b;
      cout << a << ' ';
    } else {
      b -= a;
      cout << b << ' ';
    }

  return a;
}
