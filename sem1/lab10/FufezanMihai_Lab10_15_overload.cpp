/*
 * Fufezan Mihai, 2012, lab10, ex 15
 *
 * Order in increasing mode a one-dimensional array of integer type introduced
 * from the keyboard using qsort() from stdlib.h. Use the same algorithm for
 * float numbers and a decreasing order.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void read(int *, int);
void read(float *, int);
int compare(const void *, const void *);
void print(int *, int);
void print(float *, int);

int main() {
  int m, n;

  // read arrays
  printf("Enter the size of the integer array: ");
  scanf("%d", &m);
  int *a = (int *)malloc(sizeof(int) * m);
  read(a, m);

  printf("\nEnter the size of the float array: ");
  scanf("%d", &n);
  float *b = (float *)malloc(sizeof(float) * n);
  read(b, n);

  // sort array
  qsort(a, m, sizeof(int), compare);
  qsort(b, n, sizeof(float), compare);

  // print sorted arrays
  printf("\nThe sorted arrays are:\n");
  printf("Integer:\t");
  print(a, m);
  printf("\nFloat:\t\t");
  print(b, n);
}

void read(int *a, int n) {
  // read an integer array

  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%d", a + i);
  }
}

void read(float *a, int n) {
  // read a float array

  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%f", a + i);
  }
}

int compare(const void *a, const void *b) {
  // function used by qsort to compare elements

  return ceil(*(float *)a - *(float *)b);
}

void print(int *a, int n) {
  // print the elements of an integer array

  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
}

void print(float *a, int n) {
  // print the elements of a float array

  for (int i = 0; i < n; i++)
    printf("%.1f ", a[i]);
}
