/*
 * Fufezan Mihai, 2012, lab11, ex 08
 *
 * Write a C/C++ application that allocates memory for n integer numbers that
 * will be read from the keyboard. Write a function that determines the square
 * root of each number and stores the result into another dynamically allocated
 * array. Display the initial and computed values. Free the allocated memory.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void read(int *, int);

int main() {
  int n;

  printf("Enter the size of the array: ");
  scanf("%d", &n);

  // alloc and read
  int *a = (int *)malloc(sizeof(int) * n);
  puts("Enter array values:");
  read(a, n);

  // create second array and assign values
  float *b = (float *)malloc(sizeof(float) * n);
  for (int i = 0; i < n; i++)
    b[i] = sqrt(a[i]);

  // print and compare
  puts("\nThe square roots of the elements are:");
  for (int i = 0; i < n; i++) {
    printf("%d\t->\t%.1f\n", a[i], b[i]);
  };

  // dealloc
  free(a);
  free(b);
}

void read(int *a, int n) {
  // read array

  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%d", a + i);
  }
}
