/*
 * Fufezan Mihai, 2012, lab05, ex 04
 *
 * Write a program that implements a class called Number with an attribute of
 * int type, val. In function main(), declare two Number objects and a pointer
 * to one object of this type, used to call a method int sum_nr(Number) from the
 * class that will calculate and return the sum of 2 int numbers read from the
 * keyboard, associated to the instantiated objects (current, parameter).
 * Implement the method inside and outside the class (with different names).
 */

#include <iostream>

using namespace std;

class Number {
  int val;

public:
  int sum_nr(Number x);
  void setNumber(int val);
};

int sum_int(int x, int y);

int main() {
  Number a, b, *p = &b;
  int x, y;

  cout << "Enter two numbers: ";
  cin >> x >> y;
  a.setNumber(x);
  b.setNumber(y);

  cout << endl
       << "The numbers' sum calculated using the method is: " << p->sum_nr(a)
       << "." << endl;
  cout << "The numbers' sum calculated using a function is: " << sum_int(x, y)
       << "." << endl;
}

int Number::sum_nr(Number x) { return this->val + x.val; }
void Number::setNumber(int val) { this->val = val; }
int sum_int(int x, int y) { return x + y; }