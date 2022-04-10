/*
 * Fufezan Mihai, 2012, lab07, ex 03
 *
 * Create a class named Student that has as private attributes the name,
 * surname, some marks (array 7 int values), the group. Allocate the necessary
 * amount of memory for storing n students. Determine the average mark with a
 * method from the class for each student and use it for sorting the students.
 * Display the ordered array (name, surname, group, average_mark). The
 * destructor will display a message.
 */

#include <cstring>
#include <iostream>

using namespace std;

class Student {
  char name[21];
  char surname[21];
  int *marks = new int[7];
  int group;

public:
  Student() {}
  Student(Student &x) {
    strcpy(name, x.name);
    strcpy(surname, x.surname);
    marks = x.marks;
    group = x.group;
  }
  ~Student() { cout << "\nObject destroyed.\n"; }

  char *getName() { return name; }
  void setName(char *x) { strcpy(name, x); }
  char *getSurname() { return surname; }
  void setSurname(char *x) { strcpy(surname, x); }
  int *getMarks() { return marks; }
  void setMarks(int *x) { marks = x; }
  int getGroup() { return group; }
  void setGroup(int x) { group = x; }

  float average() {
    float avg{};

    for (int i = 0; i < 7; i++)
      avg += marks[i];

    return avg / 7;
  }

  void readStudent();
};

void displayStudent(Student x);
int cmp(void const *a, void const *b) {
  return ((Student *)b)->average() - ((Student *)a)->average();
}

int main() {
  Student *students;

  cout << "How many students do you want to enter? ";
  int n;
  cin >> n;

  students = new Student[n];

  for (int i = 0; i < n; i++) {
    cout << "\nStudent #" << i << ":\n";
    students[i].readStudent();
  }

  cout << "\nThe students ordered decreasingly based on average mark:\n";
  qsort(students, n, sizeof(Student), cmp);
  for (int i = 0; i < n; i++) {
    cout << "\nStudent #" << i << ":\n";
    displayStudent(students[i]);
  }

  delete[] students;
}

void displayStudent(Student x) {
  cout << "\nName: " << x.getName();
  cout << "\nSurname: " << x.getSurname();
  cout << "\nMarks: ";

  int *y = x.getMarks();
  for (int i = 0; i < 7; i++)
    cout << y[i] << ' ';

  cout << "\nGroup: " << x.getGroup();
  cout << "\nAverage: " << x.average();
}

void Student::readStudent() {
  cout << "\nName: ";
  cin >> name;

  cout << "Surname: ";
  cin >> surname;

  cout << "Marks: ";
  for (int i = 0; i < 7; i++)
    cin >> marks[i];

  cout << "Group: ";
  cin >> group;
}
