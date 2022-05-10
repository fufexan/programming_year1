/*
 * Fufezan Mihai, 2012, lab11, ex 01
 *
 * Considering the third example (simple inheritance, the base class Position
 * and the derived class Point), resolve the following tasks:
 * a. verify the order in which the constructors and destructors are called
 * b. extend the main function in order to use all the methods from the base and
 * derived class.
 * c. write a new class called Circle (attributes and methods) derived from
 * Position
 * d. write a program that uses the classes mentioned before.
 */

#include <iostream>
using namespace std;
#include "FufezanMihai_lab11_01.hpp"

int main() {
  Position pp0(7, 7);

  cout << "Base class methods:\n";
  pp0.display();
  pp0.movement(6, 9);
  pp0.display();

  cout << "Derived class methods:\n";
  Point p0(1, 1, 'V');
  p0.display();

  Point p1(p0);
  p1.show();
  p1.movement(10, 10);

  cout << "Upcasting - objects:\n";
  pp0 = p0;
  pp0.display();

  cout << "Upcasting - pointers:\n";
  Position *p;
  p = new Point(100, 100, 'Z');
  cout
      << "Derived class display: derived object if virtual, else base object\n";
  p->display();
  p = &pp0;
  cout << "Base class display: base object always\n";
  p->display();
  p = &p1;
  cout
      << "Derived class display: derived object if virtual, else base object\n";
  p->display();

  Point *pp;
  pp = &p1;
  cout << "Derived class display: derived object always\n";
  pp->display();

  cout << "Derived class movement by 10, 10\n";
  pp->movement(10, 10);
  cout << "Derived class display: derived object with hide()\n";
  pp->hide();
  pp->display();

  cout << "Derived class movement with 10, 10 and hide()\n";
  pp->movement(10, 10);
  cout << "Base class display: derived object displayed with base class "
          "method always\n";
  pp->Position::display();

  cout << "\nDowncasting:\n ";
  Point *pdown;
  pdown = (Point *)&pp0;
  cout << "Base class display: base bject using a derived pointer, else "
          "derived class\n";
  pdown->display();

  pdown = (Point *)p;
  cout << "Display from Derived, Point" << endl;
  pdown->display();
  return 0;
}