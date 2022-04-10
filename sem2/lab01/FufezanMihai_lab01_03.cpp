/*
 * Fufezan Mihai, 2012, lab01, ex 03
 *
 * Consider a Student data structure, which contains a string field (maximum 30)
 * for name_surname and another note field of type int. Define a Student object
 * where the data will be read from the keyboard. Validate that name_surname has
 * at least 5 characters and the note should be> = 5 and <=10. Display the
 * object fields if entered correctly
 */

#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <stdio.h>
#include <string.h>

struct Student {
  char name_surname[30];
  int note;
};

int main() {
  struct Student student;

  printf("Enter a name for the student: ");
  scanf("%[^\n]s", student.name_surname);
  assert(strlen(student.name_surname) >= 5);

  printf("Enter a grade for the student: ");
  scanf("%d", &student.note);
  assert(student.note > 4 && student.note <= 10);

  printf("\nThe student's name is: %s\n", student.name_surname);
  printf("\nThe student's grade is: %d\n", student.note);
}
