/*
 * Fufezan Mihai, 2012, lab09, ex 06
 *
 * Overload the new and delete operators for one of the classes implemented
 * before, in order to allocate / de-allocate the necessary amount of memory.
 */

#include <cstdlib>
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

  void *operator new(size_t size) {
    void *p = malloc(size);
    return p;
  }

  void operator delete(void *p) { free(p); }
};
