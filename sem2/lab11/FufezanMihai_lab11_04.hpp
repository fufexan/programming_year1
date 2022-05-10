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

class Animal {
public:
  virtual void breathe() = 0;
  virtual void eat();
  virtual void sleep();
};

class Dog : public Animal {
public:
  virtual void eat() override { cout << "The dog eats\n"; }
  virtual void breathe() override { cout << "The dog breathes\n"; }
};

class Fish : public Animal {
public:
  virtual void sleep() override { cout << "The fish doesn't sleep\n"; }
  virtual void breathe() override { cout << "The fish doesn't breathe\n"; }
};
