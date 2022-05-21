/*
 * Fufezan Mihai, 2012, lab13, ex 05
 *
 * Consider the Fraction class that has two private attributes a and b for the
 * nominator and denominator and two corresponding setter and getter methods.
 * Declare a method named simplify() that simplifies a fraction. Define an
 * explicit constructor without parameters that initializes a with 0 and b with
 * 1 and another explicit constructor that receives two parameters representing
 * the values of the nominator and denominator. This constructor verifies if the
 * fraction can be defined (b != 0). Overload the addition, subtraction,
 * multiplication and division operators (+, -, *, /) using member methods that
 * simplify (if necessary) the obtained results. Overload the input (>>,
 * extraction) and output (<<, insertion) operators using friend functions that
 * allow reading and writing the data related to an entire object. Instantiate
 * two Fraction objects with data read from the keyboard. Display the initial
 * attributes of the objects by usign the insertion operator. Read another four
 * objects using the extraction operator. Perform the operations implemented
 * with member methods (the addition and subtraction of the first two objects,
 * the multiplication and division of the last ones) and store the results into
 * another four objects. Display the results. Write into a file the original
 * values and the obtained results, on different rows.
 */

#include <fstream>
#include <iostream>

using namespace std;

class Fraction {
  int a, b;

public:
  void setA(int x) { a = x; }
  void setB(int x) { b = x; }
  int getA() { return a; }
  int getB() { return b; }

  Fraction() {
    a = 0;
    b = 1;
  }
  Fraction(int x, int y) {
    if (y != 0) {
      a = x;
      b = y;
    }
  }

  Fraction simplify();
  int gcd();

  template <class T> Fraction op_fraction(Fraction x, Fraction y, T op);
  Fraction operator+(Fraction y);
  Fraction operator-(Fraction y);
  Fraction operator*(Fraction y);
  Fraction operator/(Fraction y);

  friend istream &operator>>(istream &stream, Fraction &f);
  friend ostream &operator<<(ostream &stream, const Fraction &f);
};

int main() {
  Fraction fa, fb;

  // read 2 objects
  cout << "Enter 2 fractions:\n";
  cin >> fa >> fb;
  cout << fa << "\n" << fb << "\n\n";

  // read 4 objects
  Fraction f1, f2, f3, f4;
  cout << "Enter 4 fractions:\n";
  cin >> f1 >> f2 >> f3 >> f4;

  // compute results
  Fraction add = f1 + f2;
  Fraction sub = f1 - f2;
  Fraction mul = f3 * f4;
  Fraction div = f3 / f4;

  // display results
  cout << "\nf1 + f2 = " << add << "\n";
  cout << "f1 - f2 = " << sub << "\n";
  cout << "f1 * f2 = " << mul << "\n";
  cout << "f1 / f2 = " << div << "\n";

  // write into file
  ofstream file("fractions.txt");
  file << "Initial 2 objects:\n" << fa << '\n' << fb << "\n\n";
  file << "4 objects read:\n"
       << f1 << '\n'
       << f2 << '\n'
       << f3 << '\n'
       << f4 << "\n\n";
  file << "Operations:\n";
  file << "f1 + f2 = " << add << "\n";
  file << "f1 - f2 = " << sub << "\n";
  file << "f1 * f2 = " << mul << "\n";
  file << "f1 / f2 = " << div << "\n";
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

Fraction Fraction::operator+(Fraction y) {
  return op_fraction(*this, y, plus<int>());
}
Fraction Fraction::operator-(Fraction y) {
  return op_fraction(*this, y, minus<int>());
}
Fraction Fraction::operator*(Fraction y) {
  return op_fraction(*this, y, multiplies<int>());
}
Fraction Fraction::operator/(Fraction y) {
  Fraction res(this->getA() * y.getB(), y.getA() * this->getB());
  return res.simplify();
}

istream &operator>>(istream &stream, Fraction &f) {
  cout << "Enter a numerator: ";
  stream >> f.a;
  cout << "Enter a denominator: ";
  stream >> f.b;
  return stream;
}
ostream &operator<<(ostream &stream, const Fraction &f) {
  return stream << f.a << " / " << f.b;
}
