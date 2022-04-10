/*
 * Fufezan Mihai, 2012, lab07, ex 04
 *
 * Model in OOP a class named Student containing name, surname the number of
 * marks and the marks from the winter session exams specified as an int
 * pointer. Display the name of the students who have arears exams and the first
 * three students in the group based on the media that will be also displayed.
 */

#include <iostream>

using namespace std;

class Student {
  char name[21];
  char surname[21];
  int no_marks;
  int *marks;
  bool arears;

public:
  float average();
  void readStudent();
  void displayStudent();
  bool hasArears() { return arears; }
};

int cmp(void const *a, void const *b) {
  return ((Student *)b)->average() - ((Student *)a)->average();
}

int main() {
  int n;

  cout << "How many students do you want to enter? ";
  cin >> n;
  Student *students = new Student[n];

  cout << "\nEnter students:\n";
  for (int i{}; i < n; i++) {
    cout << "Student #" << i << ":\n";
    students[i].readStudent();
  }

  cout << "\nThe students which have arears are:\n";
  int k{};
  for (int i{}; i < n; i++)
    if (students[i].hasArears()) {
      cout << "Student #" << k++ << ":\n";
      students[i].displayStudent();
    }

  cout << "\nThe first three students based on average mark:\n";
  qsort(students, n, sizeof(Student), cmp);

  for (int i{}; i < 3; i++) {
    cout << "\nStudent #" << k++ << ":\n";
    students[i].displayStudent();
  }
}

void Student::readStudent() {
  cout << "\nName: ";
  cin >> name;

  cout << "Surname: ";
  cin >> surname;

  cout << "Number of marks: ";
  cin >> no_marks;
  marks = new (nothrow) int[no_marks];

  cout << "Marks: ";
  for (int i{}; i < no_marks; i++)
    cin >> marks[i];

  cout << "Has arears? (y/n)";
  char has_arear;
  cin >> has_arear;

  if (has_arear == 'y')
    arears = true;
  else
    arears = false;
}

void Student::displayStudent() {
  cout << "\nName: " << name;
  cout << "\nSurname: " << surname;
  cout << "\nNumber of marks: " << no_marks;
  cout << "\nMarks: ";

  for (int i{}; i < no_marks; i++)
    cout << marks[i] << ' ';
  cout << "\nAverage mark: " << average();
  cout << "\nHas arears: " << (arears ? 'y' : 'n') << endl;
}

float Student::average() {
  float avg{};

  for (int i{}; i < no_marks; i++)
    avg += marks[i];

  return avg / no_marks;
}
