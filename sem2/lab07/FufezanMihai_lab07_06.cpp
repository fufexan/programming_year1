/*
 * Fufezan Mihai, 2012, lab07, ex 06
 *
 * Define a class called Complex that stores the double variables real, imag and
 * a pointer of character type that holds the name of the complex number. Define
 * an explicit constructor with 2 parameters that have 1.0 as implicit value.
 * The constructor also initializes the pointer with a 15 characters wide memory
 * zone. Define a copy constructor for this class. Implement the mutator/setter
 * and accessor/getter methods for each variable stored inside the class. All
 * the operations related to the complex numbers are also emulated using some
 * specific methods. An explicit destructor method is also part of the class.
 * Define an array of not more than 10 complex numbers. Determine the sum of all
 * the numbers in this array and use this value for initializing a new instance
 * of the class named complex_sum. Repeat this action for all the rest of the
 * operations implemented inside the class.
 */

#include <cstring>
#include <iostream>

using namespace std;

class Complex {
  double real, imag;
  char *name;

public:
  Complex(double re = 1.0, double im = 1.0) {
    real = re;
    imag = im;

    name = new char[15];
  }
  Complex(Complex const &x) {
    real = x.real;
    imag = x.imag;
    strcpy(name, x.name);
  }
  ~Complex() { delete[] name; }

  double getReal() { return real; }
  double getImag() { return imag; }
  void setReal(double x) { real = x; }
  void setImag(double x) { imag = x; }
  char *getName() { return name; }
  void setName(char *x) { strcpy(name, x); }

  Complex operator+(Complex x) {
    Complex y;
    y.setReal(real + x.real);
    y.setReal(real + x.real);
    return y;
  }
  Complex operator-(Complex x) {
    Complex y;
    y.setReal(real - x.real);
    y.setReal(real - x.real);
    return y;
  }
  Complex operator*(Complex x) {
    Complex y;
    y.setReal(real * x.real);
    y.setReal(real * x.real);
    return y;
  }
  Complex operator/(Complex x) {
    Complex y;
    y.setReal(real / x.real);
    y.setReal(real / x.real);
    return y;
  }
};

int main() {
  const int n = 10;
  Complex numbers[n];
  Complex complex_sum, complex_dif, complex_prod, complex_quot;
  double re, im;

  cout << "Enter complex numbers (real imaginary):\n";
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

  for (int i{2}; i < n; i++) {
    complex_sum = complex_sum + numbers[i];
    complex_dif = complex_dif - numbers[i];
    complex_prod = complex_prod * numbers[i];
    complex_quot = complex_quot / numbers[i];
  }

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
