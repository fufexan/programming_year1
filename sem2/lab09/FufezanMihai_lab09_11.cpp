/*
 * Fufezan Mihai, 2012, lab09, ex 11
 *
 * Consider a class named Fraction that has two integer private attributes a and
 * b for the denominator and nominator. Define set() and get() methods for all
 * the class’s attributes. Declare a method named simplify() that simplifies a
 * fraction. Consider a private static integer variable icount that will be
 * initialized with 0 and incremented in the constructors. Declare two explicit
 * constructors, one without parameters that initializes a with 0 and b with 1
 * and the other that has two integer parameters which will verify before if the
 * fraction can be defined (b!=0). Define an explicit destructor that will
 * display a message and the icount counter. Overload the arithmetic operators
 * (+, -, *, /) using friend functions. The results will be displayed after
 * being simplified. Instantiate 2 Fraction objects and read the appropriate
 * data from the keyboard. Display the original values of the numerators and
 * denominators. Using a specific accessor method, display the value of icount.
 * Apply the implemented friend functions and initialize other 4 objects with
 * the obtained results. Display the characteristics of the final objects and
 * the value of icount.
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
