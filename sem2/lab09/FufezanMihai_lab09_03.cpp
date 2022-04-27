/*
 * Fufezan Mihai, 2012, lab09, ex 03
 *
 * Starting from examples 4b, enter set-type methods to the attributes of the
 * Person class, so entering data is done in the enter() method using setter
 * methods instead of the constructor. Take the options with confirmation as in
 * 4a example. At wrong option, continue with an adequate message. Ensure
 * consistency of overloading for indexing operators (when object is not found
 * with a specific message). Consider the name as char* attribute, the space
 * allocation is done in constructors. Define the copy constructor and overload
 * the assign operator within the Person class. define destructors in both
 * classes. Consider now a sorting process based on the same keys as at
 * searching the results being displayed in reverse order. Verify all introduced
 * functionalities.
 */

#include <cstring>
#include <iostream>
using namespace std;

const int maxx = 31;
const int dim = 5;

class Person {
  char name[maxx];
  double weight;
  int age;

public:
  Person() {
    strcpy(name, "Unknown");
    weight = 0.0;
    age = 0;
  }

  Person(char *name, double weight, int age) {
    strcpy(this->name, name);
    this->weight = weight;
    this->age = age;
  }

  Person(const Person &x) {
    strcpy(name, x.name);
    weight = x.weight;
    age = x.age;
  }

  void operator=(Person x) {
    strcpy(name, x.name);
    weight = x.weight;
    age = x.age;
  }

  char *getName() { return name; }
  double getWeight() { return weight; }
  int getAge() { return age; }

  void setName(char *x) { strcpy(name, x); }
  void setWeight(double x) { weight = x; }
  void setAge(int x) { age = x; }

  void display() {
    cout << "\nName: " << name;
    cout << "\nWeight: " << weight;
    cout << "\nAge: " << age;
  }
};

class Analyses {
  Person *p;
  int n;

public:
  Analyses() {
    p = new (nothrow) Person[dim];
    n = dim;
  }

  Analyses(int nr) {
    p = new (nothrow) Person[nr];
    n = nr;
  }

  void enter() {
    char name[maxx], c;
    double weight;
    int age;

    for (int j{}; j < n; j++) {
      cout << "\nPerson #" << j + 1 << " data:\n";

      // name
      c = 'n';
      do {
        cout << "\nName: ";
        cin >> name;
        if (strlen(name) > 30) {
          cout << "Name is too long! Reenter: ";
          cin >> name;
        }
        cout << "Set name as " << name << "? y/n: ";
        cin >> c;
      } while (c != 'y');

      // weight
      c = 'n';
      do {
        cout << "\nWeight: ";
        cin >> weight;
        if (weight < 0) {
          cout << "Weight can't be negative! Reenter: ";
          cin >> weight;
        }
        cout << "Set weight to " << weight << "? y/n: ";
        cin >> c;
      } while (c != 'y');

      // age
      c = 'n';
      do {
        cout << "\nAge: ";
        cin >> age;
        if (age < 0) {
          cout << "Age can't be negative! Reenter: ";
          cin >> age;
        }
        cout << "Set age to " << age << "? y/n: ";
        cin >> c;
      } while (c != 'y');

      p[j].setName(name);
      p[j].setWeight(weight);
      p[j].setAge(age);
    }
  }

  void operator[](char *name) {
    bool found = false;

    for (int j = n - 1; j >= 0; j++)
      if (strcmp(name, p[j].getName()) == 0)
        p[j].display(), found = true;

    if (!found)
      cout << "\nSearch didn't yield results!";
  }

  void operator[](double weight) {
    bool found = false;

    for (int j = n - 1; j >= 0; j++)
      if (weight == p[j].getWeight())
        p[j].display(), found = true;

    if (!found)
      cout << "\nSearch didn't yield results!";
  }

  void operator[](int age) {
    bool found = false;

    for (int j = n - 1; j >= 0; j++)
      if (age == p[j].getAge())
        p[j].display(), found = true;

    if (!found)
      cout << "\nSearch didn't yield results!";
  }
};

int main() {
  int n, age;
  char c, name[maxx];
  double weight;

  cout << "How many persons do you want to enter? ";
  cin >> n;
  Analyses a(n);
  a.enter();

  c = 0;
  while (c != 'e') {
    cout << "\nSearch based on (a)ge, (w)eight, (n)ame, (e)xit: ";
    cin >> c;

    switch (tolower(c)) {
    case 'a':
      cout << "\nAge: ";
      cin >> age;
      a[age];
      break;

    case 'w':
      cout << "\nWeight: ";
      cin >> weight;
      a[weight];
      break;

    case 'n':
      cout << "\nName: ";
      cin >> name;
      a[name];
      break;

    case 'e':
      return 0;
      break;

    default:
      cout << "\nUnknown character.\n";
    }
  }
}