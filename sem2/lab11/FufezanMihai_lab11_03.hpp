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

class Military {
public:
  virtual void im_military() { cout << "Military\n"; }
};

class Soldier : public Military {
public:
  virtual void im_military() { cout << "Soldier\n"; }
};
class Officer : public Military {
public:
  virtual void im_military() { cout << "Officer\n"; }
};

class SubLieutenant : public Officer {
public:
  virtual void im_military() { cout << "SubLieutenant\n"; }
};
class Lieutenant : public Officer {
public:
  virtual void im_military() { cout << "Lieutenant\n"; }
};
class Captain : public Officer {
public:
  virtual void im_military() { cout << "Captain\n"; }
};
class Major : public Officer {
public:
  virtual void im_military() { cout << "Major\n"; }
};
class Colonel : public Officer {
public:
  virtual void im_military() { cout << "Colonel\n"; }
};
class General : public Officer {
public:
  virtual void im_military() { cout << "General\n"; }
};
