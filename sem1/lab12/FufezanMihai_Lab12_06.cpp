/*
 * Fufezan Mihai, 2012, lab12, ex 06
 *
 * Develop a C/C++ program that displays the name, surname, and gpa of the
 * student with the best results in the group after the winter exams. Define a
 * user-type table of structures named Student, using dynamic memory allocation
 * and a function that will return the record of the best student.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name, *surname;
  unsigned int gpa;
} Student;

void read_student(Student *);
void print_student(Student);

int main() {
  int k = 0, pos = 0;
  char confirm = 'Y';
  Student *v = nullptr;

  printf("Enter the data for a few students.\n");
  do {
    v = (Student *)realloc(v, sizeof(Student) * (k + 1));

    // read students
    printf("\nStudent %d\n", k);
    read_student(&v[k++]);

    // confirm adding a new student
    printf("\nContinue? Y/n: ");
    scanf("%c", &confirm);
  } while (confirm == 'Y' || confirm == 'y' || confirm == '\n');

  for (int i = 0; i < k; i++)
    if (v[i].gpa > v[pos].gpa)
      pos = i;

  printf("\nThe student with the highest GPA is:\n");
  print_student(v[pos]);

  // dealloc
  for (int i = 0; i < k; i++) {
    free(v[i].name);
    free(v[i].surname);
  }
  free(v);
}

void read_student(Student *x) {
  // read the data of a student

  x->name = (char *)malloc(sizeof(char) * 20);
  x->surname = (char *)malloc(sizeof(char) * 20);

  printf("Name: ");
  fgets(x->name, 20, stdin);

  printf("Surname: ");
  fgets(x->surname, 20, stdin);

  printf("Grade Point Average: ");
  scanf("%u", &x->gpa);
  getchar();
}

void print_student(Student x) {
  // print the data of a student

  printf("Name: %s", x.name);
  printf("Surname: %s", x.surname);
  printf("Grade Point Average: %u\n", x.gpa);
}
