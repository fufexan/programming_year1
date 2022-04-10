/*
 * Fufezan Mihai, 2012, lab06, ex 02
 *
 * Modify example 2 so that the code can be launched in execution considering
 * the private class attribute and appropriate public get/set methods. In
 * main(), instantiate an object from the class that will be modified and then
 * accessed, also displaying the result.
 */

#include <iostream>

using namespace std;

class Test2 {
  int x;

public:
  Test2() {
    x = 0;
    cout << "\nExplicit empty constructor call.";
  }
  int getX() { return x; }
  void setX(int y) { x = y; }
};

int main() {
  Test2 ob1;
  int a;

  cout << "\nEnter an integer to set in the object: ";
  cin >> a;
  ob1.setX(a);
  cout << "\nObject successfully set to " << ob1.getX();
}
