/*
 * Fufezan Mihai, 2012, lab11, ex 01
 *
 * Write a program that reads from the keyboard n real numbers, stores them into
 * a dinamically allocated array, displays the sum of the negative elements and
 * frees the allocated memory
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void read(int *, int);
int sum_neg(int *, int);

int main() {
  int n;

  // read array
  printf("Enter the size of an array: ");
  scanf("%d", &n);
  int *a = (int *)malloc(sizeof(int) * n);

  read(a, n);
  printf("The sum of the negative elements in the array is %d.\n",
         sum_neg(a, n));

  // dealloc
  free(a);
}

void read(int *a, int n) {
  // read an array

  puts("The array's elements are:");
  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%d", a + i);
  }
}

int sum_neg(int *a, int n) {
  // sum all the negative numbers in an array

  int s = 0;

  for (int i = 0; i < n; i++)
    if (a[i] < 0)
      s += a[i];

  return s;
}