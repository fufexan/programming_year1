/*
 * Fufezan Mihai, 2012, lab08, ex 03
 *
 * Define a class called Repository that has 2 integer private variables. The
 * class contains an empty constructor and another one with 2 parameters. An
 * accesor method that displays the variables values is also included in the
 * class. Write another class called Mathematics which is friend to the first
 * one. This class contains the implementation of the elementary arithmetical
 * operations (+, -, *, /) applied to the values stored in the first class. Each
 * arithmetical method receives as parameter an object instantiated from the
 * first class.
 */

#include <iostream>

using namespace std;

class Repository {
  int a, b;

public:
  Repository() {}
  Repository(int a, int b) {
    this->a = a;
    this->b = b;
  }

  void displayValues() { cout << a << ' ' << b; }

  friend class Mathematics;
};

class Mathematics {
public:
  int operator+(Repository x) { return x.a + x.b; }
  int operator-(Repository x) { return x.a - x.b; }
  int operator*(Repository x) { return x.a * x.b; }
  int operator/(Repository x) { return x.a / x.b; }
};

int main() {
  int x, y;
  cout << "Enter 2 integer values: ";
  cin >> x >> y;
  Repository r(x, y);
  Mathematics m;
  cout << "\nx + y = " << m + r;
  cout << "\nx - y = " << m - r;
  cout << "\nx * y = " << m * r;
  cout << "\nx / y = " << m / r;
}
