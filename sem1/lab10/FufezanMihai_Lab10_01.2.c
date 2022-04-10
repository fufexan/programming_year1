/*
 * Fufezan Mihai, 2012, lab10, ex 1.2 - lab08, ex 2
 *
 * Write a C/C++ program that determines the value of the smallest positive
 * element of a one-dimensional array.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int smallest(int *, int);

int main() {
  int n;

  printf("Enter the number of elements in an array: ");
  scanf("%d", &n);

  int v[n];

  printf("Enter the elements of the array:\n");
  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%d", v + i);
  }

  printf("The smallest positive element is %d", smallest(v, n));
}

int smallest(int *v, int n) {
  int min = 0;

  for (int i = 0; i < n; i++)
    if (*(v + i) > 0)
      min = *(v + i);

  for (int i = 0; i < n; i++)
    if (*(v + i) < min && *(v + i) > 0)
      min = *(v + i);

  return min;
}
