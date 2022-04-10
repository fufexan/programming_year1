/*
 * Fufezan Mihai, 2012, lab10, ex 12
 *
 * Write a C/C++ program that defines a function for reading from the keyboard
 * the integer type values that form a [n x n] matrix. Write a function that
 * interchanges two lines of the matrix. Use another function for displaying the
 * initial and the processed matrices. Read from the keyboard (in the main
 * function) the dimension (n) of the matrix and the indexes that indicate the
 * rows to be switched (do not use global variables)
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void readmatrix(int **, int);
void interchange(int **, int, int);
void printmatrix(int **, int);

int main() {
  int n, i1, i2;

  printf("Enter the size of a n x n matrix: ");
  scanf("%d", &n);

  // allocate memory
  int **mat = malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++)
    *(mat + i) = malloc(sizeof(int) * n);
  // read matrix
  puts("Enter matrix elements:");
  readmatrix(mat, n);

  // read lines to interchange
  printf("Enter the lines to interchange (<%d): ", n);
  scanf("%d%d", &i1, &i2);
  // make sure we're inside the matrix
  while (i1 > n - 1 || i2 > n - 1) {
    printf("Value(s) too big! Retry: ");
    scanf("%d%d", &i1, &i2);
  }

  // print initial matrix (here so we don't duplicate memory for the interchange)
  puts("The initial matrix is:");
  printmatrix(mat, n);

  // interchange lines
  interchange(mat, i1, i2);

  // print matrix
  puts("The initial matrix is:");
  printmatrix(mat, n);

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

void printmatrix(int **mat, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%d ", mat[i][j]);
    puts("");
  }
}

void interchange(int **mat, int i, int j) {
  int *tmp = *(mat + i);
  *(mat + i) = *(mat + j);
  *(mat + j) = tmp;
}