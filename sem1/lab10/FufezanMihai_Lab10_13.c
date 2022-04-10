/*
 * Fufezan Mihai, 2012, lab10, ex 13
 *
 * Considering the algorithm that directly introduces the numbers from KB in a
 * sorted mode in a one-dimensional array, use the mechanism to access by
 * pointers the elements. Develop a C/C++ application considering a function
 * having as formal parameters a pointer to a one-dimensional array of float
 * type and the dimension. (void dir_sort(float *, int n);)
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void dir_sort(float *, int);
void print(float *, int);

int main() {
  int n;

  // read array size
  printf("Enter the size of an array: ");
  scanf("%d", &n);

  // alloc and read
  float *a = malloc(sizeof(float) * n);
  dir_sort(a, n);

  // print
  puts("The elements of the array are");
  print(a, n);

  free(a);
}

void dir_sort(float *a, int n) {
  // read array with elements in ascending order

  float lastmin = -1;

  puts("Enter the real elements of the array in ascending order:");
  for (int i = 0; i < n; i++) {
    scanf("%f", a + i);
    while (*(a + i) < lastmin && lastmin != -1) {
      printf("Value too small! Retry: ");
      scanf("%f", a + i);
    }
    lastmin = *(a + i);
  }
}

void print(float *a, int n) {
  // print the elements of an array

  for (int i = 0; i < n; i++)
    printf("%.1f ", a[i]);
}
