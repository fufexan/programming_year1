/*
 * Fufezan Mihai, 2012, lab09, ex 08
 *
 * Write the program that uses a class called Calculator that has as overloaded
 * public methods:
 * - int calcul(int x) that returns the square value of x;
 * - int calcul(int x, int y) that returns the product of x and y;
 * - double calcul(int x, int y, int z) that returns the result of f(x,y,z) =
 * (x-y)(x+z)/2.;
 * The program receives the parameters from the command line.
 * Consider the case when all the methods are static.
 * - ok
 * Is it possible to have in the same time static and non-static public methods?
 * - yes
 * Analyze the case that the class has 3 private attributes of type int, x, y,
 * z, that are modified with setter adequate methods. What must be modified to
 * perform the required operations?
 * - the function should take one argument which would switch between the 3
 * modes of operation
 */

#include <iostream>

using namespace std;

class Calculator {
public:
  static int compute(int x) { return x * x; }
  static int compute(int x, int y) { return x * y; }
  static double compute(int x, int y, int z) {
    return (x - y) * (x + z) / 2.0f;
  }
};

int main() {
  Calculator calc;
  int x, y, z;

  cout << "Enter 3 numbers: ";
  cin >> x >> y >> z;

  cout << "\n1 param: " << calc.compute(x);
  cout << "\n2 params: " << calc.compute(x, y);
  cout << "\n3 params: " << calc.compute(x, y, z);
}
