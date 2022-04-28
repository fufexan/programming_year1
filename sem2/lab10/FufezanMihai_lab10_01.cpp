/*
 * Fufezan Mihai, 2012, lab10, ex 01
 *
 * Implement the program presented in the third example and examine the
 * compilation errors if are by eliminating the existing comments? Modify the
 * program so the object deriv_obj will be able to access the add() and
 * sub() methods, from the main() function keeping the private inheritance.
 */

class Base {
protected:
  int a, b;

public:
  Base() { a = 1, b = 1; }
  void setA(int x) { a = x; }
  void setB(int x) { b = x; }
  int getA() { return a; }
  int getB() { return b; }
  int add() { return a + b; }
  int sub() { return a - b; }
};

class Derived : private Base {
public:
  int mul() { return a * b; }
  int addWrapper() { return add(); }
  int subWrapper() { return sub(); }
};

#include <iostream>
using namespace std;

int main() {
  Base base_obj;

  cout << "Initial base values: " << base_obj.getA() << " " << base_obj.getB()
       << '\n';
  cout << "Base sum = " << base_obj.add();
  cout << "Base difference = " << base_obj.sub();

  base_obj.setA(2);
  base_obj.setB(3);
  cout << "\nModified base values: " << base_obj.getA() << " "
       << base_obj.getB() << '\n';
  cout << "Sum/Difference after modification = " << base_obj.add() << "/"
       << base_obj.sub() << '\n';

  Derived deriv_obj;
  cout << "\nProduct of initial values = " << deriv_obj.mul() << '\n';
  cout << "Sum of initial values = " << deriv_obj.addWrapper() << '\n';
  cout << "Difference of initial values = " << deriv_obj.subWrapper() << '\n';
}