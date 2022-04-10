/*
 * Fufezan Mihai, 2012, lab07, ex 07
 *
 * Consider a Pair class that has two pointers to int type, *x and *y. Define
 * a constructor no parameters that initializes zones with 0, with two
 * parameters that initialize zones with values specified as parameters, a
 * constructor with one parameter that calls the two-parameter constructor with
 * parameter value, and 0. The class has a copy constructor, a move constructor,
 * a destructor (which distinguishes objects that are temporary) and setters and
 * getters that properly manage attributes. A sur() method is defined that has a
 * Pair object as a parameter and returns a Pair object sum of the current
 * object with the given one as a parameter. The class also contains an
 * mean() method that returns the double-type arithmetic mean of the content
 * from the two attributes. Instantiate 3 objects using no-parameter,
 * one-parameter, two-parameter constructors. Change the values for the
 * no-parameter object with setters. Display values from the addresses of the
 * parameters and mean value. Display values from the attribute addresses of
 * other objects. Add the first two objects into a new result object and display
 * the result. Consider appropriate messages in constructors and destructor.
 * Track the calls.
 */

#include <iostream>
#include <memory>

using namespace std;

class Pair {
  int *x, *y;

public:
  Pair() {
    cout << "\nCreating empty object.\n";
    x = nullptr;
    y = nullptr;
  }
  Pair(int *a, int *b) {
    cout << "\nCreating object with two parameters.\n";
    x = a;
    y = b;
  }
  Pair(int *a) { Pair(a, nullptr); }
  Pair(Pair &p) {
    x = p.x;
    y = p.y;
    cout << "\nCopying object.\n";
  }
  Pair(Pair &&p) {
    exchange(x, p.x);
    exchange(y, p.y);
    cout << "\nMoving object.\n";
  }
  ~Pair() { cout << "\nDestroying object.\n"; }

  int *getX() { return x; }
  int *getY() { return y; }
  void setX(int *x) { this->x = x; }
  void setY(int *y) { this->y = x; }

  Pair sum(Pair x) {
    int *a = nullptr, *b = nullptr;
    *a = *(x.getX()) + *(getX());
    *b = *(x.getY()) + *(getY());

    Pair y(a, b);

    return y;
  }

  double mean() { return (*getX() + *getY()) / 2.0; }
};

int main() {
  int x1, x2, x3, y1, y2, y3;

  cout << "Enter two numbers for the first pair: ";
  cin >> x1 >> y1;
  Pair a;
  a.setX(&x1);
  a.setY(&y1);

  cout << "\nEnter two numbers for the second pair: ";
  cin >> x2 >> y2;
  Pair b(&x2);
  b.setY(&y2);

  cout << "\nEnter two numbers for the third pair: ";
  cin >> x3 >> y3;
  Pair c(&x3, &y3);

  cout << "\nFirst pair's values are " << *(a.getX()) << ' ' << *(a.getY())
       << ", and its mean value is " << a.mean();
  cout << "\nSecond pair's values are " << *(b.getX()) << ' ' << *(b.getY())
       << ", and its mean value is " << b.mean();
  cout << "\nThird pair's values are " << *(c.getX()) << ' ' << *(c.getY())
       << ", and its mean value is " << c.mean();

  Pair result = move(a.sum(b));
  cout << "\nFirst object + second object = " << *(result.getX()) << ' '
       << *(result.getY()) << "\nThe mean value is " << result.mean();
}
