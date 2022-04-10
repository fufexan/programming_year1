/*
 * Fufezan Mihai, 2012, lab08, ex 04
 *
 * Write a C++ application that stores inside a class a public static integer
 * variable called var_static. The variable is incremented each time the class’s
 * constructor is called. After instantiating several objects, display their
 * number using the value of the static variable.
 */

#include <iostream>

using namespace std;

class Test {
public:
  static int var_static;
  Test() { var_static++; }
};

int Test::var_static;

int main() {
  Test a, b, c, d, e;

  cout << "The constructor was called " << Test::var_static << " times.";
}
