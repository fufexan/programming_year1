/*
 * Fufezan Mihai, 2012, lab09, ex 07
 *
 * Write the program that considers a MyClass class with three int-type
 * attributes. The class considers on the basis of the overload mechanism public
 * methods int myFunction(...), which depending on the number of parameters
 * received, returns either the value received (1 parameter) or the product of
 * the input variables (0 - all, 2, 3 parameters). Instantiate an object of the
 * class in main(), set the attributes using dedicated setter methods from the
 * class, and display the values at method calls.
 */

#include <iostream>

using namespace std;

class MyClass {
  int a, b, c;

public:
  int myFunction(int val) { return val; }
  int myFunction() { return a * b * c; }
  int myFunction(int x, int y) { return x * y; }
  int myFunction(int x, int y, int z) { return x * y * z; }

  void setA(int x) { a = x; }
  void setB(int x) { b = x; }
  void setC(int x) { c = x; }
};

int main() {
  MyClass ob;
  int a, b, c;

  cout << "Enter 3 numbers: ";
  cin >> a >> b >> c;
  ob.setA(a);
  ob.setB(b);
  ob.setC(c);

  cout << "\n0 params: " << ob.myFunction();
  cout << "\n1 param: " << ob.myFunction(c);
  cout << "\n2 params: " << ob.myFunction(a, c);
  cout << "\n3 params: " << ob.myFunction(a, b, c);
}
