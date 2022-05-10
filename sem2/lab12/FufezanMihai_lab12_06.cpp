/*
 * Fufezan Mihai, 2012, lab12, ex 06
 *
 * Consider the Fraction class that has two private attributes a and b for the
 * nominator and denominator and two corresponding setter and getter methods.
 * Declare a method named simplify() that simplifies a fraction and returns a
 * real value. Define an explicit constructor without parameters that
 * initializes a with 0 and b with 1 and another explicit constructor that
 * receives two parameters representing the values of the nominator and
 * denominator. For this constructor is verified if b!=0 before to be called.
 * Define a destructor that displays a message. Consider a static variable
 * icount that will be initialized with 0 and incremented in the class’s
 * constructors. Overload the addition, subtraction, multiplication and division
 * operators (+, -, *, /) using friend functions, without simplifying the
 * obtained results. Instantiate two Fraction objects and read the corresponding
 * data from the keyboard. Display the initial attributes of the objects, on
 * different lines, in 10 digits placeholders using * as filling character. The
 * denominator will be left aligned while the nominator will pe positioned in
 * the right part of the displaying field. Using an accesor method display the
 * value of icount as a signed integer, on 15 characters, left aligned, using
 * ’$’ as filling character. Perform the operations implemented with friend
 * functions initializing another four objects with the obtained results.
 * Display the data (denominator/nominator) by overloading the output (<<,
 * insertion) operator and the counter (as a signed integer, on 20 characters,
 * right aligned, using ’#’ as filling character) after the last operation.
 * Simplify the results and display the resulting values as fixed float numbers
 * with 4 digits precision.
 */

#include <iomanip>
#include <iostream>

using namespace std;

class Fraction {
  int a, b;
  static int icount;

public:
  Fraction() {
    a = 0, b = 1;
    icount++;
  }
  Fraction(int x, int y) {
    a = x;
    if (y > 0)
      b = y;
    icount++;
  }
  Fraction(Fraction const &x) {
    *this = x;
    icount++;
  };
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

  static int getIcount() { return icount; }

  template <class T> Fraction op_fraction(Fraction x, Fraction y, T op);
  friend Fraction operator+(Fraction x, Fraction y);
  friend Fraction operator-(Fraction x, Fraction y);
  friend Fraction operator*(Fraction x, Fraction y);
  friend Fraction operator/(Fraction x, Fraction y);

  friend istream &operator>>(istream &stream, Fraction &f);
  friend ostream &operator<<(ostream &stream, const Fraction &f);
};

int Fraction::icount;
ostream &init(ostream &stream);

int main() {
  Fraction a, b;

  cout << "Enter fraction A:\n";
  cin >> a;

  cout << "Enter fraction B:\n";
  cin >> b;

  cout << "\nA: " << init << left << a.getA() << right << a.getB();
  cout << "\nB: " << init << left << b.getA() << right << b.getB();

  a = a.simplify();
  cout << "\nA simplified: " << a;

  b = b.simplify();
  cout << "\nB simplified: " << b;

  Fraction add = a + b;
  cout << "\n\nA + B = " << add;
  Fraction sub = a - b;
  cout << "\nA - B = " << sub;
  Fraction mul = a * b;
  cout << "\nA * B = " << mul;
  Fraction div = a / b;
  cout << "\nA / B = " << div;

  cout << "\n\nThe number of objects instantiated is: " << setw(20)
       << setfill('#') << left << (signed int)Fraction::getIcount();

  cout << "\n\nThe simplified results are:\n";
  add = add.simplify();
  sub = sub.simplify();
  mul = mul.simplify();
  div = div.simplify();
  cout << "A + B = " << setprecision(4) << add;
  cout << "\nA - B = " << setprecision(4) << sub;
  cout << "\nA * B = " << setprecision(4) << mul;
  cout << "\nA / B = " << setprecision(4) << div;
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

ostream &init(ostream &stream) { return stream << setw(10) << setfill('*'); }