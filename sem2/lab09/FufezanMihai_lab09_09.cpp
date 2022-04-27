/*
 * Fufezan Mihai, 2012, lab09, ex 09
 *
 * Define a class called Student, containing as private member: name (pointer to
 * character array), marks (integer pointer) and no_marks (integer).
 *
 * The class also contains a constructor with parameters, a copy/move
 * constructor, a method for assign operator overloading, a method for marks
 * setting, a display method and a destructor.
 *
 * Create some objects using the constructor with parameters, another one using
 * the copy constructor as a clone object, displaying each time the attributes
 * of the created object.
 *
 * Copy an object into another one, both being created.
 * Display the result of the copy operation. Analyze the used methods.
 * Make another implementation in which the name is given by a fixed character
 * string or pseudo container string, and marks is a fixed size array specified
 * by a constant, the no_marks attribute being removed
 */

#include <cstring>
#include <iostream>

using namespace std;

class Student {
  char *name;
  int *marks;
  int no_marks;

public:
  Student(char *name = (char *)"Unknown", int *marks = {}, int no_marks = 0) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->marks = marks;

    this->no_marks = no_marks;
  }

  Student(Student &x) {
    delete[] name;
    name = new char[strlen(x.name) + 1];
    strcpy(name, x.name);

    no_marks = x.no_marks;

    delete[] marks;
    marks = x.marks;
  }

  ~Student() {
    delete[] name;
    delete[] marks;
  }

  void operator=(Student &x) {
    delete[] name;
    name = new char[strlen(x.name) + 1];
    strcpy(name, x.name);

    no_marks = x.no_marks;

    delete[] marks;
    marks = x.marks;
  }

  void setMarks(int n, int *m) {
    no_marks = n;

    delete[] marks;
    marks = m;
  }

  void display() {
    cout << "\nName: " << name;
    cout << "\nNo. marks: " << no_marks;
    cout << "\nMarks: ";
    for (int i{}; i < no_marks; i++)
      cout << marks[i] << ' ';
  }
};

int main() {
  char name[30];
  int marks[20], n;

  cout << "Enter student name: ";
  cin >> name;
  cout << "Enter no. marks: ";
  cin >> n;
  cout << "Enter marks: ";
  for (int i{}; i < n; i++)
    cin >> marks[i];
  Student a(name, marks, n);
  cout << "\nObject a:\n";
  a.display();

  cout << "\nObject b:\n";
  Student b(a);
  b.display();

  cout << "\nObject c:\n";
  Student c = b;
  c.display();
}
