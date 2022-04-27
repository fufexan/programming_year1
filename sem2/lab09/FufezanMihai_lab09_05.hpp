/*
 * Fufezan Mihai, 2012, lab09, ex 05
 *
 * Overload the [] operator for the Department class that contains an array of
 * Employee objects (that has as variables the name (character array) and the
 * salary (float)). When the operator is applied to a Department object, it
 * returns (or displays) all the data related to the Employee object with that
 * index.
 */

#include <cstring>

class Employee {
  char *name;
  float salary;

public:
  ~Employee() { delete[] name; }

  char *getName() { return name; }
  void setName(char *x) {
    delete[] name;
    name = new char[sizeof(x) + 1];
    strcpy(name, x);
  }
  float getSalary() { return salary; }
  void setSalary(float x) { salary = x; }
  void setEmployee(Employee x) {
    setName(x.name);
    setSalary(x.salary);
  }
};

class Department {
  Employee employees[10];

public:
  Employee operator[](int pos) { return employees[pos]; }
  void setEmployee(int pos, Employee x) {
    employees[pos].setName(x.getName());
    employees[pos].setSalary(x.getSalary());
  }
};
