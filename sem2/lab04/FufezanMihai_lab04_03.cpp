/*
 * Fufezan Mihai, 2012, lab04, ex 03
 *
 * Use the library function "qsort()" for sorting an array of records that
 * contain a name, a surname, a personal identification code and an employment
 * date. The sorting is based on the data stored in some specific fields (like
 * name, employment date, etc.).
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

struct Date {
  int day, month, year;
};
struct Employee {
  int id;
  Date employment_date;
  char name[50], surname[50];
};

Employee read_employee();
void print_employee(Employee x);
void sort_employees(vector<Employee> employees, char mode);

int cmp_id(const void *a, const void *b);
int cmp_name(const void *a, const void *b);
int cmp_sname(const void *a, const void *b);
int cmp_date(const void *a, const void *b);

int main() {
  vector<Employee> employees;
  int n;

  cout << "How many employees do you want to store in an array? ";
  cin >> n;

  cout << "\nEnter the employees:\n";
  for (int i = 0; i < n; i++) {
    cout << "Employee #" << i + 1 << ":\n\n";
    employees.push_back(read_employee());
  }

  cout << "\nWhat do you want to sort by?\nn - name\ns - surname\nd - "
          "employment date\ni - ID: ";
  char mode;
  cin >> mode;

  sort_employees(employees, mode);
  cout << "\nThe sorted employees are:\n";
  for (Employee e : employees) {
    cout << "Employee #" << &e - &employees[0] << endl;
    print_employee(e);
  }
}

void sort_employees(vector<Employee> employees, char mode) {
  int (*compar)(const void *, const void *);

  switch (mode) {
  case 'n':
    compar = cmp_name;
    break;
  case 's':
    compar = cmp_sname;
    break;
  case 'd':
    compar = cmp_date;
    break;
  case 'i':
    compar = cmp_id;
    break;
  }

  qsort(&employees[0], employees.size(), sizeof(Employee), compar);
}

int cmp_name(const void *a, const void *b) {
  return strcmp(((Employee *)a)->name, ((Employee *)b)->name);
}

int cmp_sname(const void *a, const void *b) {
  return strcmp(((Employee *)a)->surname, ((Employee *)b)->surname);
}

int cmp_date(const void *a, const void *b) {
  Date date_a = (*(Employee *)a).employment_date;
  Date date_b = (*(Employee *)b).employment_date;

  int year = date_a.year - date_b.year;
  int month = date_a.month - date_b.month;
  int day = date_a.day - date_b.day;

  return year + day + month;
}

int cmp_id(const void *a, const void *b) {
  return ((Employee *)a)->id - ((Employee *)b)->id;
}

Employee read_employee() {
  Employee e;

  cin.get();
  cout << "Name: ";
  cin.getline(e.name, 50);

  cout << "Surname: ";
  cin.getline(e.surname, 50);

  cout << "Employment date (yyyy-mm-dd): ";
  scanf("%d-%d-%d", &e.employment_date.year, &e.employment_date.month,
        &e.employment_date.day);

  cout << "ID: ";
  cin >> e.id;

  return e;
}

void print_employee(Employee e) {
  cout << "Name: " << e.name << '\n';
  cout << "Surname: " << e.surname << '\n';
  cout << "Employment date: ";
  printf("%d-%0.2d-%0.2d", e.employment_date.year, e.employment_date.month,
         e.employment_date.day);
  cout << "\nID: " << e.id << '\n';
}
