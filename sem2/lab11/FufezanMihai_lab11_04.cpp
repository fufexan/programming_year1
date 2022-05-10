/*
 * Fufezan Mihai, 2012, lab11, ex 04
 *
 * Declare a class called Animal that contains a pure virtual method (breathe())
 * and 2 virtual methods (eat() and sleep()). The classes Dog and Fish inherit
 * the first class in a public mode and implements the pure virtual method. The
 * class Dog overrides the eat() method. The class Fish overrides the sleep()
 * method. Instantiate the derived classes and call the specific methods. After
 * that, define an array of Animal objects that will contain instances of the
 * derived classes, if that’s possible. If not, find an appropriate solution.
 */

#include <iostream>
using namespace std;
#include "FufezanMihai_lab11_04.hpp"

int main() {
  Dog dog;
  Fish fish;
  Animal *animals[] = {&dog, &fish};

  animals[0]->breathe();
  animals[0]->eat();
  animals[1]->breathe();
  animals[1]->sleep();
}
