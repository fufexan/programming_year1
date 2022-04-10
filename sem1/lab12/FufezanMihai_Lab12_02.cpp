/*
 * Fufezan Mihai, 2012, lab12, ex 02
 *
 * Develop a C/C++ application considering an adequate data structure that will
 * be transferred by value as a parameter to a function, and then by address,
 * using pointers to other function. Please initialise the fields of the
 * structure within the main() function with data from the keyboard. In both
 * functions, display the field’s values with an adequate message.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[21], surname[21], country[21];
  int group, birth_year;
} Student;

void read_student(Student *);
void print_student(Student);

int main() {
  int k = -1;
  Student *v = nullptr;

  // read students
  printf("Enter students. To stop, enter `aaa` as the name.");
  do {
    k++;
    v = (Student *)realloc(v, sizeof(Student) * (k + 1));

    printf("\nStudent %d:\n", k);
    read_student(&v[k]);

    // if name is either aaa or AAA break out of the loop
    if (strstr(v[k].name, "AAA") || strstr(v[k].name, "aaa"))
      break;
  } while (true);

  // print students
  if (k <= 0)
    printf("\nThere are no students!\n");
  else {
    printf("\nThe students are:\n");

    for (int i = 0; i < k; i++) {
      printf("\nStudent %d:\n", i);
      print_student(v[i]);
    }
  }

  // dealloc
  free(v);
}

void read_student(Student *x) {
  // read student

  printf("Name: ");
  fgets(x->name, 20, stdin);

  // if name is either aaa or AAA, return to calling function
  if (strstr(x->name, "AAA") || strstr(x->name, "aaa"))
    return;

  printf("Surname: ");
  fgets(x->surname, 20, stdin);

  printf("Country: ");
  fgets(x->country, 20, stdin);

  printf("Group: ");
  scanf("%d", &x->group);

  printf("Birth year: ");
  scanf("%d", &x->birth_year);
  getchar();
}

void print_student(Student x) {
  // print student

  printf("Name:       %s", x.name);
  printf("Surname:    %s", x.surname);
  printf("Country:    %s", x.country);
  printf("Group:      %d\n", x.group);
  printf("Birth year: %d\n", x.birth_year);
}