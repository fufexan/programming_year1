/*
 * Fufezan Mihai, 2012, lab08, ex 08
 *
 * Consider the Fraction class that has two private integer attributes a and b
 * for the denominator and nominator. Use two setter and getter methods for all
 * the class’s attributes.
 * Declare a friend function named simplify() that receives as parameter a
 * Fraction object and returns the corresponding simplified object.
 *
 * Consider a private static integer variable icount that will be initialized
 * with 0 and incremented in the class’s constructors.
 *
 * Define an explicit constructor without parameters that initializes a with 0
 * and b with 1 and another explicit constructor with two integer parameters.
 * For this constructor is verified if b!=0 before to be called.
 *
 * Define an explicit destructor that displays and decrements the value of
 * icount. Define a friend function f_add_fraction(...) that returns an object
 * reflecting the sum of the objects received as parameters. Implement similar
 * functions for fractions subtraction, multiplication and division. Instantiate
 * two Fraction objects and read the appropriate data from the keyboard.
 *
 * Display the initial attributes and the ones obtained after simplifying. Call
 * the implemented friend functions and store the results into another different
 * four objects.
 *
 * Display the results and the objects counter using the corresponding accesor
 * methods.
 */

#include <iostream>

using namespace std;

class Fraction {
  int a, b;
  int gcd();
  static int icount;

public:
  Fraction() {
    a = 0;
    b = 1;
    icount++;
  }
  Fraction(int x, int y) {
    a = x;
    if (y != 0)
      b = y;
    else
      cerr << "\nDenominator can't be 0!\n";
    icount++;
  }
  ~Fraction() {
    icount--;
    cout << "\nNumber of objects present: " << icount << ".\n";
  }

  void setA(int x) { a = x; }
  void setB(int x) { b = x; }
  int getA() { return a; }
  int getB() { return b; }
  int getIcount() { return icount; }

  Fraction simplify();
  template <class T> Fraction op_fraction(Fraction x, Fraction y, T op);
  friend Fraction f_add_fraction(Fraction x, Fraction y);
  friend Fraction f_sub_fraction(Fraction x, Fraction y);
  friend Fraction f_mul_fraction(Fraction x, Fraction y);
  friend Fraction f_div_fraction(Fraction x, Fraction y);
};

int Fraction::icount;

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

  Fraction add = f_add_fraction(a, b);
  cout << "\n\nA + B = " << add.getA() << " / " << add.getB();
  Fraction sub = f_sub_fraction(a, b);
  cout << "\nA - B = " << sub.getA() << " / " << sub.getB();
  Fraction mul = f_mul_fraction(a, b);
  cout << "\nA * B = " << mul.getA() << " / " << mul.getB();
  Fraction div = f_div_fraction(a, b);
  cout << "\nA / B = " << div.getA() << " / " << div.getB();
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

template <class T>
Fraction Fraction::op_fraction(Fraction x, Fraction y, T op) {
  int c, d, e, f;

  e = x.b * y.a;
  f = y.b * x.a;

  c = op(e, f);

  d = x.b * y.b;

  Fraction res(c, d);

  return res.simplify();
}

Fraction f_add_fraction(Fraction x, Fraction y) {
  return x.op_fraction(x, y, plus<int>());
}
Fraction f_sub_fraction(Fraction x, Fraction y) {
  return x.op_fraction(x, y, minus<int>());
}
Fraction f_mul_fraction(Fraction x, Fraction y) {
  return x.op_fraction(x, y, multiplies<int>());
}
Fraction f_div_fraction(Fraction x, Fraction y) {
  Fraction res(x.getA() * y.getB(), y.getA() * x.getB());
  return res;
}