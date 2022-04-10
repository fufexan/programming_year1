/*
 * Fufezan Mihai, 2012, lab07, ex 09
 *
 * Considering the previous task add in the Fraction class another attribute
 * consisting in a character array pointer (name) that identifies a fraction.
 * The constructor without parameters will allocate a max 20 characters memory
 * zone defined with ”Unknown”, the parameterized constructor will have another
 * last implicit parameter initialized with ”Unknown” that will represent the
 * fraction’s name and the reserved space will be twice the string dimension.
 * Implement setter and getter methods for the name attribute. Implement a copy
 * constructor and a destructor. In the main() function create two Fraction
 * objects, one using the constructor without parameters and the other using the
 * parameterized constructor. Modify the attributes of the first object using
 * setter methods. Create a third object using the copy constructor. Display the
 * attributes of this last object using the getter methods.
 */

#include <cstring>
#include <iostream>

using namespace std;

class Fraction {
  int a, b;
  int gcd();
  char *name;

public:
  // empty constructor
  Fraction() {
    a = 0;
    b = 1;
    name = new char[21];
    strcpy(name, "Unknown");
  }

  // parametric constructor
  Fraction(int x, int y, char *z = (char *)"Unknown") {
    a = x;
    if (y != 0)
      b = y;
    else
      cerr << "\nDenominator can't be 0!\n";

    name = new char[21];
    strcpy(name, z);
  }

  // copy constructor
  Fraction(const Fraction &x) {
    a = x.a;
    b = x.b;
    name = new char[sizeof(x.name) + 20];
    strcpy(name, x.name);
  }
  ~Fraction() { delete[] name; }

  // setters & getters
  void setA(int x) { a = x; }
  void setB(int x) { b = x; }
  void setName(char *x) { strcpy(name, x); }
  int getA() { return a; }
  int getB() { return b; }
  char *getName() { return name; }

  // operations
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
  char *z = new char[20];

  cout << "Enter fraction A's numerator, denominator and name: ";
  cin >> x >> y;
  cin >> z;
  Fraction a;
  a.setA(x);
  a.setB(y);
  a.setName(z);

  cout << "Enter fraction B's numerator, denominator and name: ";
  cin >> x >> y;
  cin >> z;
  Fraction b(x, y, z);

  Fraction res(a);
  cout << "Fraction \"" << res.getName() << "\" copied from A is " << res.getA()
       << " / " << res.getB();
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