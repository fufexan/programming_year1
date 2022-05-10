/*
 * Fufezan Mihai, 2012, lab12, ex 04
 *
 * Define a class called AcceleratedMovement that contains the private
 * attributes dc (the current distance), vc (the current speed) and a (the
 * acceleration). The values of dc, vc and a are initialized in the constructor
 * and their values are equal to d0, v0 and a0 (as parameters). The class
 * overloads the extraction and insertion operators for initializing and
 * displaying the characteristics of a certain instance. Implement the method
 * determineMovement that re-calculates the values of dc and vc, considering a
 * number of seconds (received as paramenter) and the law of uniformly
 * accelerated linear motion with a0 acceleration. Instantiate the class and use
 * the defined members.
 */

#include <iostream>

using namespace std;

class AcceleratedMovement {
  float dc, vc, a;

public:
  AcceleratedMovement() {
    dc = 0;
    vc = 0;
    a = 0;
  }
  AcceleratedMovement(float d0, float v0, float a0) {
    dc = d0;
    vc = v0;
    a = a0;
  }

  friend istream &operator>>(istream &stream, AcceleratedMovement &am);
  friend ostream &operator<<(ostream &stream, const AcceleratedMovement &am);

  void determineMovement(int s) {
    dc += vc * s + a / 2 * s * s;
    vc += a * s;
  }
};

int main() {
  AcceleratedMovement am;
  int s;

  cin >> am;

  cout << "Enter a duration (in seconds): ";
  cin >> s;

  am.determineMovement(s);

  cout << "After " << s << " seconds, the values are:\n";
  cout << am;
}

istream &operator>>(istream &stream, AcceleratedMovement &am) {
  cout << "Enter a value for distance: ";
  stream >> am.dc;
  cout << "Enter a value for velocity: ";
  stream >> am.vc;
  cout << "Enter a value for acceleration: ";
  stream >> am.a;
  return stream;
}

ostream &operator<<(ostream &stream, const AcceleratedMovement &am) {
  stream << "Distance: " << am.dc << ", Velocity: " << am.vc
         << ", Acceleration: " << am.a;
  return stream;
}
