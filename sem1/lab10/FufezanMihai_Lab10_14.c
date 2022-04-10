/*
 * Fufezan Mihai, 2012, lab10, ex 14
 *
 * Develop the algorithm able to interclass two one-dimensional arrays of int
 * type. Use pointers.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void read(int *, int);
int *interclass(int *, int *, int, int);
int compare(const void *, const void *);
void print(int *, int);

int main() {
  int m, n;
  printf("Enter the size of the first array: ");
  scanf("%d", &m);
  int *a = (int *)malloc(sizeof(int) * m);
  read(a, m);

  printf("\nEnter the size of the second array: ");
  scanf("%d", &n);
  int *b = (int *)malloc(sizeof(int) * n);
  read(b, n);

  printf("\nThe arrays are:\n");
  printf("1: ");
  print(a, m);
  printf("\n2: ");
  print(b, n);

  printf("\n\nThe interclassed arrays result into the following array:\n");
  print(interclass(a, b, m, n), m + n);
}

void read(int *a, int n) {
  // read an array

  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%d", a + i);
  }
}

int *interclass(int *a, int *b, int m, int n) {
  // interclass 2 arrays

  // create a new array first
  int *c = malloc(sizeof(int) * (m + n));

  // copy elements from arrays into final array
  int k = 0;
  for (int i = 0; i < m; i++)
    c[k++] = a[i];
  for (int i = 0; i < n; i++)
    c[k++] = b[i];
  k--;

  // sort array
  qsort(c, m + n, sizeof(int), compare);
  // return sorted array
  return c;
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
