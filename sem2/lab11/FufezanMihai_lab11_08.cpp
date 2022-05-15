/*
 * Fufezan Mihai, 2012, lab11, ex 08
 *
 * Consider the Fraction class that has two protected attributes a and b for the
 * nominator and denominator and two corresponding setter and getter methods.
 * Declare a virtual method named simplify() that simplifies a fraction using
 * the greatest common divider determined using the % operator. Define an
 * explicit constructor without parameters that initializes a with 0 and b with
 * 1 and another explicit constructor with two integer parameters. For this
 * constructor is verified if b!=0 before to be called.
 *
 * Overload the addition, subtraction, multiplication and division operators (+,
 * -, *, /) using friend functions and simplify (if necessary) the obtained
 * results.
 *
 * Define a class named Fraction_ext that inherits in a public mode the
 * Fraction class and has a parameterized constructor that calls the constructor
 * from the base class. The derived class redefines the implementation of
 * simplify() by determining the greatest common divider using the differences
 * based algorithm. Display an appropriate message in this method.
 *
 * Overload the composed addition, subtraction, multiplication and division
 * operators (+=, -=, *=, /=) using member methods. Use member methods for
 * overloading the post-increment and post-decrement operators that will add 1
 * to the value of a Fraction_ext instance.
 *
 * Instantiate 2 Fraction objects without parameters. Set the attributes using
 * values read from the keyboard. Perform the operations implemented with friend
 * functions from the base class and initialize another 4 objects with the
 * obtained results. Simplify the results.
 *
 * Instantiate two objects of Fraction_ext type with data from the KB. Perform
 * the implemented operations with the member functions and methods. Assign the
 * operation results to other 4 existing Fraction_ext objects. Use for
 * operations copies of the initial objects. Simplify and display the obtained
 * results. Verify the possibility of using both simplify() methods (base and
 * derived class) using instances of the base and derived classes and a pointer
 * of Fraction type.
 */

#include <iostream>

using namespace std;

#include "FufezanMihai_lab11_08.hpp"

int Fraction::icount;

int main() {
  int x, y;

  cout << "Enter fraction A's numerator and denominator: ";
  cin >> x >> y;
  Fraction a(x, y);

  cout << "Enter fraction B's numerator and denominator: ";
  cin >> x >> y;
  Fraction b(x, y);

  Fraction t1, t2;

  t1 = a.simplify();
  cout << "\nA simplified: " << a.getA() << " / " << a.getB();

  t2 = b.simplify();
  cout << "\nB simplified: " << b.getA() << " / " << b.getB();

  Fraction add = t1 + t2;
  cout << "\n\nA + B = " << add.getA() << " / " << add.getB();
  t1 = a;
  Fraction sub = t1 - t2;
  cout << "\nA - B = " << sub.getA() << " / " << sub.getB();
  t1 = a;
  Fraction mul = t1 * t2;
  cout << "\nA * B = " << mul.getA() << " / " << mul.getB();
  t1 = a;
  Fraction div = t1 / t2;
  cout << "\nA / B = " << div.getA() << " / " << div.getB();

  Fraction_ext add_ext = add;
  add_ext++;
  cout << "\n\n(A + B)++= " << add.getA() << " / " << add.getB();
  Fraction_ext sub_ext = sub;
  sub_ext--;
  cout << "\n(A - B)-- = " << sub.getA() << " / " << sub.getB();
  Fraction_ext mul_ext = mul;
  ++mul_ext;
  cout << "\n++(A * B) = " << mul.getA() << " / " << mul.getB();
  Fraction_ext div_ext = div;
  --div_ext;
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

  return res;
}

Fraction Fraction_ext::operator+=(Fraction x) {
  return x.op_fraction(*this, x, plus<int>());
}
Fraction Fraction_ext::operator-=(Fraction x) {
  return x.op_fraction(*this, x, minus<int>());
}
Fraction Fraction_ext::operator*=(Fraction x) {
  return x.op_fraction(*this, x, multiplies<int>());
}
Fraction Fraction_ext::operator/=(Fraction x) {
  Fraction res(this->getA() * x.getB(), x.getA() * this->getB());
  return res;
}

Fraction operator+(Fraction x, Fraction y) {
  return x.op_fraction(x, y, plus<int>());
}
Fraction operator-(Fraction x, Fraction y) {
  return x.op_fraction(x, y, minus<int>());
}
Fraction operator*(Fraction x, Fraction y) {
  return x.op_fraction(x, y, multiplies<int>());
}
Fraction operator/(Fraction x, Fraction y) {
  Fraction res(x.getA() * y.getB(), y.getA() * x.getB());
  return res;
}

Fraction Fraction_ext::simplify() {
  Fraction res;

  int div = gcd();

  res.setA(a / div);
  res.setB(b / div);

  return res;
}

int Fraction_ext::gcd() {
  int c = a, d = b;

  while (c != d)
    if (c > d)
      c -= d;
    else
      d -= c;

  return c;
}
