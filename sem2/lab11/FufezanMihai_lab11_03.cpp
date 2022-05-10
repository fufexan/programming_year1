/*
 * Fufezan Mihai, 2012, lab11, ex 03
 *
 * Write a C++ program that defines a class called Military that has a public
 * virtual method im_military(). Define the classes Soldier and Officer, both
 * being derived from the first class. Extend further the Officer class by
 * implementing the classes SubLieutenant, Lieutenant, Captain, Major, Colonel,
 * General. Override the method im_military() for indicating the military
 * degree represented by each class. Instantiate each of the classes Soldier,
 * Lieutenant,...,General and call the im_military() method.
 */

#include <iostream>
using namespace std;
#include "FufezanMihai_lab11_03.hpp"

int main() {
  Military m;
  m.im_military();
  Soldier s;
  s.im_military();
  Officer o;
  o.im_military();
  SubLieutenant sl;
  sl.im_military();
  Lieutenant l;
  l.im_military();
  Captain c;
  c.im_military();
  Major mj;
  mj.im_military();
  Colonel cl;
  cl.im_military();
  General g;
  g.im_military();
}
