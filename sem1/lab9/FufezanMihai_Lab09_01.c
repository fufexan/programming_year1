/*
 * Fufezan Mihai, 2012, lab09, ex 1
 *
 * Write a C/C++ application that reads from the keyboard two one dimensional
 * arrays of integers and displays the scalar product of the two arrays. Use a
 * function that reads the elements from the keyboard and another function that
 * calculates the scalar product, using pointers in both functions. Reading and
 * displaying the arrays’ elements should be done in the main function.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void read_elements(int, int *);
int dot_product(int, int, int *, int *);

int main() {
  int n, m;

  // read sizes of arrays
  printf("Enter the size of the first array: ");
  scanf("%d", &n);
  printf("Enter the size of the second array: ");
  scanf("%d", &m);

  int arr1[n], arr2[m];

  // read arrays
  read_elements(n, arr1);
  read_elements(m, arr2);

  // calculate and print the dot product
  printf("The scalar product of the two arrays is %d",
         dot_product(n, m, arr1, arr2));
}

void read_elements(int n, int *arr) {
  // read elements into an array
  printf("Enter array values:\n");
  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%d", arr + i);
  }
}

int dot_product(int n, int m, int *arr1, int *arr2) {
  // calculates the dot product of 2 arrays
  int dot = 0;

  while (n > m) {
    n--;
    dot += *(arr1 + n);
  }

  while (n < m) {
    m--;
    dot += *(arr2 + m);
  }

  while (n >= 0) {
    n--;
    dot += *(arr1 + n) * *(arr2 + n);
  }

  return dot;
}
