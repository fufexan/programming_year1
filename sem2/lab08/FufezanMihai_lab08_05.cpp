/*
 * Fufezan Mihai, 2012, lab08, ex 05
 *
 * Implement the 4-th problem by changing the static variable’s access modifier
 * to private. Define a method that returns the counter’s value. Analyze the
 * case if the getter method is static or non-static and the way it is called.
 */

#include <iostream>

using namespace std;

class Test {
  static int var_static;

public:
  int getCount() { return var_static; }
  Test() { var_static++; }
};

int Test::var_static;

int main() {
  Test a, b, c, d, e;

  cout << "The constructor was called " << e.getCount() << " times.";
}
