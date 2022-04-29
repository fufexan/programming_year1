/*
 * Fufezan Mihai, 2012, lab10, ex 08
 *
 * Consider the Fraction class that has two protected attributes a and b for the
 * nominator and denominator and two corresponding setter and getter methods for
 * all attributes. Declare a public method named simplify() that simplifies a
 * fraction. Define an explicit constructor without parameters that initializes
 * a with 0 and b with 1 and another explicit constructor with two integer
 * parameters. For this constructor is verified if b!=0 before to be called.
 * Overload the addition, subtraction, multiplication and division operators (+,
 * -, *, /) using member methods that simplify (if necessary) the obtained
 * results. Define a class named Fraction_ext that inherits in a public mode the
 * Fraction class and has a parameterized constructor that calls the constructor
 * from the base class. Use member methods for overloading the pre-
 * incrementation and pre-decrementation operators that will add/subtract 1 to
 * the value of a Fraction_ext instance. Instantiate two Fraction objects
 * without parameters. Set the attributes using values read from the keyboard.
 * Perform the implemented operations and initialize other four objects with the
 * obtained results. Simplify the results. Instantiate two objects of
 * Fraction_ext type with data from the KB. Perform the available operations.
 * Assign the operation results to other existing Fraction_ext objects. Simplify
 * and display the obtained results.
 */

#include <iostream>

using namespace std;

class Fraction {
protected:
  int a, b;

public:
  Fraction() { a = 0, b = 1; }
  Fraction(int x, int y) {
    a = x;
    if (y > 0)
      b = y;
  }
  Fraction(Fraction const &x) { *this = x; };
  void operator=(Fraction const &x) {
    a = x.a;
    b = x.b;
  }

  void setA(int x) { a = x; }
  void setB(int x) { b = x; }
  int getA() { return a; }
  int getB() { return b; }

  Fraction simplify();
  int gcd();

  template <class T> Fraction op_fraction(Fraction x, Fraction y, T op);
  Fraction operator+=(Fraction x);
  Fraction operator-=(Fraction x);
  Fraction operator*=(Fraction x);
  Fraction operator/=(Fraction x);
};

class Fraction_ext : public Fraction {
public:
  Fraction_ext(int x, int y) : Fraction(x, y) {}
  Fraction_ext(Fraction x) : Fraction(x) {}

  Fraction operator++(int) {
    a++;
    return *this;
  };
  Fraction operator--(int) {
    a--;
    return *this;
  };
  Fraction operator++() {
    Fraction tmp = *this;
    a++;
    return tmp;
  };
  Fraction operator--() {
    Fraction tmp = *this;
    a--;
    return tmp;
  };
};

int main() {
  int x, y;

  cout << "Enter fraction A's numerator and denominator: ";
  cin >> x >> y;
  Fraction a;
  a.setA(x);
  a.setB(y);

  cout << "Enter fraction B's numerator and denominator: ";
  cin >> x >> y;
  Fraction b;
  b.setA(x);
  b.setB(y);

  Fraction t1, t2;

  t1 = a.simplify();
  cout << "\nA simplified: " << a.getA() << " / " << a.getB();

  t2 = b.simplify();
  cout << "\nB simplified: " << b.getA() << " / " << b.getB();

  Fraction add = t1 += t2;
  cout << "\n\nA + B = " << add.getA() << " / " << add.getB();
  t1 = a.simplify();
  Fraction sub = t1 -= t2;
  cout << "\nA - B = " << sub.getA() << " / " << sub.getB();
  t1 = a.simplify();
  Fraction mul = t1 *= t2;
  cout << "\nA * B = " << mul.getA() << " / " << mul.getB();
  t1 = a.simplify();
  Fraction div = t1 /= t2;
  cout << "\nA / B = " << div.getA() << " / " << div.getB();

  Fraction_ext eadd(add), esub(sub), emul(mul), ediv(div);
  eadd++;
  cout << "\n\n(A + B)++= " << add.getA() << " / " << add.getB();
  esub--;
  cout << "\n(A - B)-- = " << sub.getA() << " / " << sub.getB();
  ++emul;
  cout << "\n++(A * B) = " << mul.getA() << " / " << mul.getB();
  --ediv;
  cout << "\n--(A / B) = " << div.getA() << " / " << div.getB();
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

Fraction Fraction::operator+=(Fraction x) {
  return x.op_fraction(*this, x, plus<int>());
}
Fraction Fraction::operator-=(Fraction x) {
  return x.op_fraction(*this, x, minus<int>());
}
Fraction Fraction::operator*=(Fraction x) {
  return x.op_fraction(*this, x, multiplies<int>());
}
Fraction Fraction::operator/=(Fraction x) {
  return x.op_fraction(*this, x, divides<int>());
}
