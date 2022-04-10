/*
 * Fufezan Mihai, 2012, lab05, ex 07
 *
 * Write a program that implements a class named Arithmetics that has two
 * numeric (int, float or double) attributes a and b. The class will contain
 * setter and getter methods for attributes. Inside the class, implement a
 * method named sum(). The method difference() that also belongs to the class
 * is implemented outside the class, methods that will be called using
 * Arithmetics objects. Create 3 objects instantiated from the Arithmetics class
 * and make use of the defined methods. The methods return the numerical values
 * corresponding to the operation using the two attributes of the class results
 * that will be displayed in main(). For each addition / subtraction operation
 * group, display the values of the object attributes using the getter methods.
 */

#include <iostream>

using namespace std;

class Arithmetics {
  double a, b;

public:
  void setA(double x) { a = x; }
  double getA() { return a; }
  void setB(double x) { b = x; }
  double getB() { return b; }

  double sum();
  double difference();
};

int main() {
  Arithmetics a, b, c;
  double x, y;

  // a
  cout << "Enter two numbers for object 1: ";
  cin >> x >> y;
  a.setA(x);
  a.setB(y);

  // b
  cout << endl << "Enter two numbers for object 2: ";
  cin >> x >> y;
  b.setA(x);
  b.setB(y);

  // c
  cout << endl << "Enter two numbers for object 3: ";
  cin >> x >> y;
  c.setA(x);
  c.setB(y);

  cout << endl << endl;

  // a
  cout << "Object 1: " << a.getA() << " + " << a.getB() << " = " << a.sum()
       << endl;
  cout << "Object 1: " << a.getA() << " - " << a.getB() << " = "
       << a.difference() << endl;
  cout << endl << endl;

  // b
  cout << "Object 2: " << b.getA() << " + " << b.getB() << " = " << b.sum()
       << endl;
  cout << "Object 2: " << b.getA() << " - " << b.getB() << " = "
       << b.difference() << endl;
  cout << endl << endl;

  // c
  cout << "Object 3: " << c.getA() << " + " << c.getB() << " = " << c.sum()
       << endl;
  cout << "Object 3: " << c.getA() << " - " << c.getB() << " = "
       << c.difference() << endl;
}

double Arithmetics::sum() { return a + b; }
double Arithmetics::difference() { return a - b; }
