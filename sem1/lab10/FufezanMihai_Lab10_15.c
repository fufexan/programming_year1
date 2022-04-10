/*
 * Fufezan Mihai, 2012, lab10, ex 15
 *
 * Order in increasing mode a one-dimensional array of integer type introduced
 * from the keyboard using qsort() from stdlib.h. Use the same algorithm for
 * float numbers and a decreasing order
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void readi(int *, int);
void readf(float *, int);
int compare(const void *, const void *);
void print(int *, int);

int main() {
  int m, n;
  printf("Enter the size of the integer array: ");
  scanf("%d", &m);
  int *a = (int *)malloc(sizeof(int) * m);
  readi(a, m);

  printf("\nEnter the size of the float array: ");
  scanf("%d", &n);
  float *b = (float *)malloc(sizeof(float) * n);
  readf(b, n);

  // sort array
  qsort(c, m + n, sizeof(int), compare);

  printf("\nThe arrays are:\n");
  printf("1: ");
  print(a, m);
  printf("\n2: ");
  print(b, n);
}

void readi(int *a, int n) {
  // read an integer array

  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%d", a + i);
  }
}

void readf(float *a, int n) {
  // read a float array

  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%f", a + i);
  }
}


int compare(const void *a, const void *b) {
  // function used by qsort to compare elements

  return (*(int *)a - *(int *)b);
}

void print(int *a, int n) {
  // print the elements of an array

  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
}
