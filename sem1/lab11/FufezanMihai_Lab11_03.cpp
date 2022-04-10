/*
 * Fufezan Mihai, 2012, lab11, ex 03
 *
 * Write a program that allocates the necessary amount of memory for storing the
 * elements from two [m x n] integer matrices. Write a function that calculates
 * the sum of the inital matrices and another one for displaying both the
 * original values and the result.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int **readmatrix(int, int);
int **addmatrix(int **, int **, int, int);
void printmatrix(int **, int, int);

int main() {
  int m, n, p, q;

  // read sizes
  printf("Enter the dimensions of the first matrix: ");
  scanf("%d%d", &m, &n);
  printf("Enter the dimensions of the second matrix: ");
  scanf("%d%d", &p, &q);

  // read matrices
  puts("\nEnter the elements of the first matrix:");
  int **a = readmatrix(m, n);
  puts("\nEnter the elements of the first matrix:");
  int **b = readmatrix(p, q);

  // print matrices
  puts("\nFirst matrix is:");
  printmatrix(a, m, n);
  puts("\nSecond matrix is:");
  printmatrix(b, p, q);

  // add matrices
  if (m == p && n == q) {
    puts("\nThe added matrices result in this matrix:");
    printmatrix(addmatrix(a, b, m, n), m, n);
  } else
    printf(
        "\nThe matrices' dimensions aren't equal so they couldn't be added.");

  // dealloc
  free(a);
  free(b);
}

int **readmatrix(int m, int n) {
  // read a matrix' elements

  int **mat = malloc(sizeof(int *) * m);

  for (int i = 0; i < m; i++) {
    mat[i] = malloc(sizeof(int) * n);
    for (int j = 0; j < n; j++)
      scanf("%d", &mat[i][j]);
  }

  return mat;
}

void printmatrix(int **mat, int m, int n) {
  // print a matrix

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      printf("%d ", mat[i][j]);
    printf("\n");
  }
}

int **addmatrix(int **a, int **b, int m, int n) {
  // add 2 matrices

  int **c = malloc(sizeof(int *) * m);

  for (int i = 0; i < m; i++) {
    c[i] = malloc(sizeof(int) * n);
    for (int j = 0; j < n; j++)
      c[i][j] = a[i][j] + b[i][j];
  }

  return c;
}
