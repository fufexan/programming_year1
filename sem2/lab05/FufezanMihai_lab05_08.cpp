/*
 * Fufezan Mihai, 2012, lab05, ex 08
 *
 * Starting with the Complex class ex.4, implement the addition, subtraction,
 * multiplication and division of complex numbers. The methods can be
 * implemented inside or outside the class. Test the defined methods by using
 * them upon some created objects. The methods will return Complex objects and
 * in main() with getter methods will be displayed the results.
 */

#include <iostream>

using namespace std;

class Complex {
  double re, im;

public:
  void setRe(double x) { re = x; }
  void setIm(double x) { im = x; }

  double getRe() { return re; }
  double getIm() { return im; }

  Complex sum(Complex c);
  Complex dif(Complex c);
  Complex mul(Complex c);
  Complex div(Complex c);
};

int main() {
  Complex x, y, z;
  srand(time(0));

  x.setRe(rand() % 100);
  x.setIm(rand() % 100);

  y.setRe(rand() % 100);
  y.setIm(rand() % 100);

  cout << "Two complex numbers were generated." << endl;
  z = x.sum(y);
  cout << x.getRe() << "+" << x.getIm() << "i + " << y.getRe() << "+"
       << y.getIm() << "i = " << z.getRe() << "+" << z.getIm() << "i." << endl;
  z = x.dif(y);
  cout << x.getRe() << "+" << x.getIm() << "i - " << y.getRe() << "+"
       << y.getIm() << "i = " << z.getRe() << "+" << z.getIm() << "i." << endl;
  z = x.mul(y);
  cout << x.getRe() << "+" << x.getIm() << "i * " << y.getRe() << "+"
       << y.getIm() << "i = " << z.getRe() << "+" << z.getIm() << "i." << endl;
  z = x.div(y);
  cout << x.getRe() << "+" << x.getIm() << "i / " << y.getRe() << "+"
       << y.getIm() << "i = " << z.getRe() << "+" << z.getIm() << "i." << endl;
}

Complex Complex::sum(Complex c) {
  Complex res;
  res.re = re + c.re;
  res.im = im + c.im;
  return res;
}

Complex Complex::dif(Complex c) {
  Complex x;

  x.re = re - c.re;
  x.im = im - c.im;

  return x;
}

Complex Complex::mul(Complex c) {
  Complex x;

  x.re = re * c.re;
  x.im = im * c.im;

  return x;
}

Complex Complex::div(Complex c) {
  Complex x;

  x.re = re / c.re;
  x.im = im / c.im;

  return x;
}
