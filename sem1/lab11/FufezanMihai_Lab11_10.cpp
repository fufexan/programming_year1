/*
 * Fufezan Mihai, 2012, lab11, ex 10
 *
 * Write a C/C++ application that allocates the necessary amount of memory for
 * storing an n x n integer matrix. Write a function that calculates the sum of
 * the positive numbers located below the main diagonal and another function
 * that displays the matrix. Print the matrix and the calculated sum. Free the
 * allocated memory.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int sum_below_diag(int **, int);
void print_matrix(int **, int);

int main() {
  int n;

  printf("Enter the dimension of the matrix: ");
  scanf("%d", &n);

  int **a = (int **)malloc(sizeof(int *) * n);

  // alloc and read
  puts("Enter the elements of the matrix:");
  for (int i = 0; i < n; i++) {
    a[i] = (int *)malloc(sizeof(int) * n);
    for (int j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
  }

  // print
  puts("\nThe matrix you entered is:");
  print_matrix(a, n);

  printf("\nThe sum of the elements below the main diagonal is: %d\n",
         sum_below_diag(a, n));

  // dealloc
  for (int i = 0; i < n; i++)
    free(a[i]);
  free(a);
}

int sum_below_diag(int **a, int n) {
  // calculate the sum of the elements below the main diagonal

  int s = 0;

  for (int i{}; i < n; i++)
    for (int j{}; j < n; j++)
      if (i > j)
        s += a[i][j];

  return s;
}

void print_matrix(int **a, int n) {
  // print a matrix

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%d ", a[i][j]);
    printf("\n");
  }
}