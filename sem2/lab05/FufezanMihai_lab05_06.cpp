/*
 * Fufezan Mihai, 2012, lab05, ex 06
 *
 * Define a class that manages complex numbers. Write the program that uses this
 * class considering 2 objects and displays the object’s characteristics and the
 * results of the defined operations. (Use exemple 3 with result in the current
 * object).
 */

#include <cmath>
#include <iostream>

using namespace std;

class Complex {
  double re, im;

public:
  Complex(double x = 0.0, double y = 0.0) {
    re = x;
    im = y;
  }

  double module() { return sqrt(re * re + im * im); }
  double phase();

  void setRe(double re) { this->re = re; }
  double getRe() { return re; }

  void setIm(double im) { this->im = im; }
  double getIm() { return im; }

  Complex add_complex(Complex b) {
    Complex x;

    x.re = re + b.re;
    x.im = im + b.im;

    return x;
  }

  Complex sub_complex(Complex b) {
    Complex x;

    x.re = re - b.re;
    x.im = im - b.im;

    return x;
  }
};

int main() {
  Complex obj1, obj2;
  double aux;

  // obj1
  cout << "Enter the first complex number (real & imaginary parts): ";
  cin >> aux;
  obj1.setRe(aux);
  cin >> aux;
  obj1.setIm(aux);

  // obj2
  cout << "Enter the second complex number (real & imaginary parts): ";
  cin >> aux;
  obj2.setRe(aux);
  cin >> aux;
  obj2.setIm(aux);

  // add
  Complex third = obj1.add_complex(obj2);
  cout << endl << "Number 1 + number 2 = ";
  cout << third.getRe() << " + " << third.getIm() << "i\n";

  // subtract
  third = obj1.sub_complex(obj2);
  cout << endl << "Number 1 - number 2 = ";
  cout << third.getRe() << " + " << third.getIm() << "i\n";
}