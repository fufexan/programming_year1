/*
 * Fufezan Mihai, 2012, lab09, ex 01
 *
 * Implement a class called Complex that overloads the arithmetical operators
 * (+, -, *, /) for performing the corresponding operations when applied to
 * Complex instances (use both friend functions (*, /) and member methods (+,
 * -)). Note: the Complex numbers will have a real and an imaginary part, both
 * coefficients being represented as real numbers.
 */

#include <iostream>

using namespace std;

class Complex {
  double real, imag;
  char *name;

public:
  Complex(double re = 1.0, double im = 1.0, char *name = (char *)"Unknown") {
    real = re;
    imag = im;

    this->name = name;
  }
  Complex(Complex const &x) {
    real = x.real;
    imag = x.imag;

    name = x.name;
  }

  double getReal() { return real; }
  double getImag() { return imag; }
  void setReal(double x) { real = x; }
  void setImag(double x) { imag = x; }
  char *getName() { return name; }
  void setName(char *x) { name = x; }

  void operator=(Complex const &x) {
    real = x.real;
    imag = x.imag;
    name = x.name;
  }

  Complex operator+(Complex x) {
    Complex y;
    y.setReal(real + x.real);
    y.setImag(imag + x.imag);
    return y;
  }
  Complex operator-(Complex x) {
    Complex y;
    y.setReal(real - x.real);
    y.setImag(imag - x.imag);
    return y;
  }
  friend Complex operator*(Complex a, Complex b);
  friend Complex operator/(Complex a, Complex b);
};

int main() {
  const int n = 2;
  Complex numbers[n];
  Complex complex_sum, complex_dif, complex_prod, complex_quot;
  double re, im;

  cout << "Enter two complex numbers (real imaginary):\n";
  for (int i{}; i < n; i++) {
    cout << "Number #" << i << ": ";
    cin >> re >> im;
    numbers[i].setReal(re);
    numbers[i].setImag(im);
  }

  complex_sum = numbers[0] + numbers[1];
  complex_dif = numbers[0] - numbers[1];
  complex_prod = numbers[0] * numbers[1];
  complex_quot = numbers[0] / numbers[1];

  cout << "\nResults of complex number operations:\n";
  cout << "\nSum: " << complex_sum.getReal() << " + " << complex_sum.getImag()
       << "i";
  cout << "\nDifference: " << complex_dif.getReal() << " + "
       << complex_dif.getImag() << "i";
  cout << "\nProduct: " << complex_prod.getReal() << " + "
       << complex_prod.getImag() << "i";
  cout << "\nQuotient: " << complex_quot.getReal() << " + "
       << complex_quot.getImag() << "i";
}

Complex operator*(Complex a, Complex b) {
  Complex y;
  y.setReal(a.real * b.real);
  y.setImag(a.imag * b.imag);
  return y;
}
Complex operator/(Complex a, Complex b) {
  Complex y;
  y.setReal(a.real / b.real);
  y.setImag(a.imag / b.imag);
  return y;
}
