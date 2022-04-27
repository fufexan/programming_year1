/*
 * Fufezan Mihai, 2012, lab09, ex 12
 *
 * Using the same Fraction class, overload the composed arithmetical operators
 * (+=, -=, *=, /=) using member functions (methods). Overload the
 * pre-de/incrementation and post-de/incrementation operators that will
 * subtract/add the value 1 to an already existent Fraction object. Instantiate
 * 2 Fraction objects and read the appropriate data from the keyboard. Copy the
 * objects in other 2 temporary objects. Apply the overloaded operators using
 * the copied objects and assign the results to other 4 objects. Display the
 * characteristics of the final objects. Display the results obtained after
 * decrementing/incrementing post/prefixed of the final 4 results.
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

  Fraction operator+=(Fraction x);
  Fraction operator-=(Fraction x);
  Fraction operator*=(Fraction x);
  Fraction operator/=(Fraction x);

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

  Fraction add = t1 += t2;
  cout << "\n\nA + B = " << add.getA() << " / " << add.getB();
  t1 = a;
  Fraction sub = t1 -= t2;
  cout << "\nA - B = " << sub.getA() << " / " << sub.getB();
  t1 = a;
  Fraction mul = t1 *= t2;
  cout << "\nA * B = " << mul.getA() << " / " << mul.getB();
  t1 = a;
  Fraction div = t1 /= t2;
  cout << "\nA / B = " << div.getA() << " / " << div.getB();

  add++;
  cout << "\n\n(A + B)++= " << add.getA() << " / " << add.getB();
  sub--;
  cout << "\n(A - B)-- = " << sub.getA() << " / " << sub.getB();
  ++mul;
  cout << "\n++(A * B) = " << mul.getA() << " / " << mul.getB();
  --div;
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
