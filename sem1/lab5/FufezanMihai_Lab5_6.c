/*
 * Fufezan Mihai, 2012, lab05, ex 6
 *
 * Read from the keyboard the names and the marks of 2 students (each student
 * has a single mark). Display, on separate lines, the name of each
 * student (right aligned and left aligned) in two 20 characters fields
 * and their marks with 2 digits precision.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  char name1[21], name2[21];
  float grade1, grade2;

  printf("Enter first student's name: ");
  scanf("%s", &name1);
  printf("Enter second student's name: ");
  scanf("%s", &name2);

  printf("Enter first student's grade: ");
  scanf("%f", &grade1);
  printf("Enter second student's grade: ");
  scanf("%f", &grade2);

  printf("%-20s's grade is %.2f\n", name1, grade1);
  printf("%20s's grade is %.2f\n", name2, grade2);
}
