/*
 * Fufezan Mihai, 2012, lab12, ex 07
 *
 * Write a C/C++ application that allocates dynamically memory for the data of n
 * students (surname, name, gendre), reading from the keyboard all the required
 * info, the program displays the number of female students and frees up the
 * allocated memory.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name, *surname, *gender;
} Student;

void read_student(Student *);

int main() {
  int k = 0, fem = 0;
  char confirm = 'Y';
  Student *v = nullptr;

  printf("Enter the data for a few students.\n");
  do {
    v = (Student *)realloc(v, sizeof(Student) * (k + 1));

    // read students
    printf("\nStudent %d\n", k);
    read_student(&v[k++]);

    // count female students
    if (!strcmp(v[k - 1].gender, "female"))
      fem++;

    // confirm adding a new student
    printf("\nContinue? Y/n: ");
    scanf("%c", &confirm);
  } while (confirm == 'Y' || confirm == 'y' || confirm == '\n');

  printf("\nThere are %d female students.\n", fem);

  // dealloc
  for (int i = 0; i < k; i++) {
    free(v[i].name);
    free(v[i].surname);
    free(v[i].gender);
  }
  free(v);
}

void read_student(Student *x) {
  // read the data of a student

  x->name = (char *)malloc(sizeof(char) * 20);
  x->surname = (char *)malloc(sizeof(char) * 20);
  x->gender = (char *)malloc(sizeof(char) * 7);

  printf("Name: ");
  scanf("%s", x->name);

  printf("Surname: ");
  scanf("%s", x->surname);

  printf("Gender: ");
  scanf("%s", x->gender);
  getchar();

  // validation
  while (strcmp(x->gender, "male") && strcmp(x->gender, "female")) {
    printf("The genders are male or female! Retry: ");
    scanf("%s", x->gender);
    getchar();
  }
}
