/*
 * Fufezan Mihai, 2012, lab01, ex 01
 *
 * Consider a function with 3 implicit parameters (all) (int, float, double)
 * that returns the product of the values. Call that function with different
 * variants for effective parameters(no pram, 1 param, 2 params, 3 params).
 */

#include <iostream>

using namespace std;

double product(int a = 10, float b = 2.3, double c = 5.1223);

int main() {
  int a;
  float b;
  double c;

  cout << "Enter an integer, a float and a double: ";
  cin >> a >> b >> c;

  cout << "\nThe product of all parameters is: " << product(a, b, c) << endl;
  cout << "\nThe product of two parameters is: " << product(b, c) << endl;
  cout << "\nThe product of one parameter is: " << product(c) << endl;
  cout << "\nThe product with no parameters is: " << product() << endl;
}

double product(int a, float b, double c) { return a * b * c; }
