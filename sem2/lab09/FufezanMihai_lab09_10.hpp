/*
 * Fufezan Mihai, 2012, lab09, ex 10
 *
 * Define a class named Number that has as private attribute a double variable.
 * The class contains an explicit empty constructor, a constructor with a
 * parameter and an accessor method that displays the value of the stored
 * variable. Write a class called Mathematics that has as attribute an instance
 * created from the first class and overloads the arithmetical operators (+, -,
 * /, *). Each method calculates the appropriate result by considering the data
 * extracted from the Number object.
 */

class Number {
  double a;

public:
  Number() {}
  Number(double x) { a = x; }
  double getNumber() { return a; }
};

class Mathematics {
  Number x;

public:
  int operator+(Number y) { return x.getNumber() + x.getNumber(); }
  int operator-(Number y) { return x.getNumber() - x.getNumber(); }
  int operator*(Number y) { return x.getNumber() * x.getNumber(); }
  int operator/(Number y) { return x.getNumber() / x.getNumber(); }
};
