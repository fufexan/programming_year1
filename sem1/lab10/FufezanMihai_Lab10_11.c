/*
 * Fufezan Mihai, 2012, labXX, ex Y
 *
 * Write a C/C++ program that defines a function for reading from the keyboard
 * the integer type values that form a [n x n] matrix. Write a function that
 * determines the number of negative elements that are located above the
 * secondary diagonal. Display the result in the main function (don’t use global
 * variables).
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void readmatrix(int **, int);

int main() {
  int n;

  printf("Enter the size of a n x n matrix: ");
  scanf("%d", &n);

  // allocate memory
  int **mat = malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++)
    *(mat + i) = malloc(sizeof(int) * n);
  // read matrix
  puts("Enter matrix elements:");
  readmatrix(mat, n);

  // count negative elements above the second diagonal
  int neg = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i + j < n - 1 && mat[i][j] < 0)
        neg++;

  printf("\nThere are %d negative elements above the second diagonal.\n", neg);

  // dealloc memory
  for (int i = 0; i < n; i++)
    free(*(mat + i));
  free(mat);
}

void readmatrix(int **mat, int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &mat[i][j]);
}
