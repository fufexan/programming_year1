/*
 * Fufezan Mihai, 2012, lab05, ex 05
 *
 * Define a class that implements the following methods:
 * - int add(int x, int y), which returns the add of x and y;
 * - int sub(int x, int y), which returns the sub between x and y;
 * - int mul(int x, int y), which returns the result of x multiplied by y;
 * - float div(int x, int y), which returns the quotient of x and y;
 * Write the application that uses this class. Consider also the case that the
 * class contains two int attributes, x and y, and the class methods will have
 * no parameters.
 *
 * Remark: prevent the division of a number by 0. If this situation occurs,
 * display an error message.
 */

#include <iostream>

using namespace std;

class Operations {
  int x, y;

public:
  void setX(int x);
  void setY(int x);
  int add();
  int sub();
  int mul();
  int div();
};

class OperationsInt {
public:
  int add(int x, int y);
  int sub(int x, int y);
  int mul(int x, int y);
  int div(int x, int y);
};

int main() {
  int x, y;
  Operations a;
  OperationsInt o;

  cout << "Enter two integers: ";
  cin >> x >> y;

  a.setX(x);
  a.setY(y);

  cout << endl << "Operations using objects:" << endl;
  printf("%d + %d = %d\n", x, y, a.add());
  printf("%d - %d = %d\n", x, y, a.sub());
  printf("%d * %d = %d\n", x, y, a.mul());
  printf("%d / %d = %d\n", x, y, a.div());

  cout << endl << "Operations using ints:" << endl;
  printf("%d + %d = %d\n", x, y, o.add(x, y));
  printf("%d - %d = %d\n", x, y, o.sub(x, y));
  printf("%d * %d = %d\n", x, y, o.mul(x, y));
  printf("%d / %d = %d\n", x, y, o.div(x, y));
}

// operations without parameters
int Operations::add() { return x + y; }
int Operations::sub() { return x - y; }
int Operations::mul() { return x * y; }
int Operations::div() {
  if (y == 0) {
    cout << "ERROR: division by 0 is impossible!" << endl;
    return -1;
  }
  return x / y;
}
void Operations::setX(int x) { this->x = x; }
void Operations::setY(int x) { this->y = x; }

// operations with parameters
int OperationsInt::add(int x, int y) { return x + y; }
int OperationsInt::sub(int x, int y) { return x - y; }
int OperationsInt::mul(int x, int y) { return x * y; }
int OperationsInt::div(int x, int y) {
  if (y == 0) {
    cout << "ERROR: division by 0 is impossible!" << endl;
    return -1;
  }
  return x / y;
}
