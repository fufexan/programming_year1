/*
 * Fufezan Mihai, 2012, lab10, ex 9
 *
 * Write a C/C++ program that reads from the keyboard the float type elements of
 * a one-dimensional array. The values represent the average marks of a group
 * of students. Write a function that determines the number of students having
 * the average mark >= 8. Display the result in the main function. (use
 * pointers, avoid global variables).
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int count_passing(float *, int);

int main() {
  int n;

  printf("Enter the number of students whose average grades will be stored: ");
  scanf("%d", &n);
  // allocate array
  float *v = malloc(sizeof(float) * n);

  // read array
  puts("Enter elements (real numbers):");
  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%f", v + i);
  }

  // print number of students passing
  printf("\n%d students have the average mark >= 8.", count_passing(v, n));

  free(v);
}

int count_passing(float *v, int n) {
  // count how many students have an average grade of 8 or above
  int k = 0;

  for (int i = 0; i < n; i++)
    if (*(v + i) >= 8)
      k++;

  return k;
}
