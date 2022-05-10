/*
 * Fufezan Mihai, 2012, lab11, ex 02
 *
 * Extend the base class from the forth example by adding some other virtual
 * methods, which will be implemented in the derived classes (like the setter
 * and getter for the value of weight).
 */

#include <iostream>
using namespace std;
#include "FufezanMihai_lab11_02.hpp"

int main() {
  Vehicle motorcycle;
  Automobile ford;
  Truck semi;
  Boat fishing_boat;

  motorcycle.message();
  ford.message();
  semi.message();
  fishing_boat.message();

  Vehicle *pmotorcycle;
  Automobile *pford;
  Truck *psemi;
  Boat *pfishing_boat;

  cout << "\n";
  pmotorcycle = &motorcycle;
  pmotorcycle->message();

  pford = &ford;
  pford->message();

  psemi = &semi;
  psemi->message();

  pfishing_boat = &fishing_boat;
  pfishing_boat->message();

  cout << "\n";
  pmotorcycle = &motorcycle;
  pmotorcycle->message();

  pmotorcycle = &ford;
  pmotorcycle->message();

  pmotorcycle = &semi;
  pmotorcycle->message();

  pmotorcycle = &fishing_boat;
  pmotorcycle->message();
}