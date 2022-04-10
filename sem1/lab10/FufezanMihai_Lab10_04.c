/*
 * Fufezan Mihai, 2012, lab10, ex 4
 *
 * Write a C/C++ application that reads from the keyboard the elements of 2
 * integer matrices. Write a function that receives as parameters the pointers
 * to the matrices and returns the pointer to the sum matrix. The result is to
 * be displayed in function main. Display the elements from the second diagonal
 * of the sum matrix using the returned pointer.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void read_matrix(int, int, int **);
void add_matrices(int, int, int **, int **, int **);

int main() {
  int m[3], n[3];
  int ***mat = malloc(sizeof(int **) * 3);

  // read matrices' dimensions and their elements
  for (int i = 0; i < 2; i++) {
    printf("Enter the dimensions of matrix %d: ", i + 1);
    scanf("%d%d", &m[i], &n[i]);

    // allocate matrix space
    mat[i] = malloc(sizeof(int *) * m[i]);
    for (int j = 0; j < m[i]; j++)
      mat[i][j] = malloc(sizeof(int) * n[i]);

    // read elements
    printf("Enter the elements:\n");
    read_matrix(m[i], n[i], mat[i]);
  }

  // get size of sum matrix
  m[2] = fmin(m[0], m[1]);
  n[2] = fmin(n[0], n[1]);

  // allocate sum matrix space
  mat[2] = malloc(sizeof(int *) * m[2]);
  for (int j = 0; j < m[2]; j++)
    mat[2][j] = malloc(sizeof(int) * n[2]);

  // compute sum of matrices
  add_matrices(m[2], n[2], mat[0], mat[1], mat[2]);

  // free first 2 matrices
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < m[i]; j++)
      free(mat[i][j]);
    free(mat[i]);
  }

  // print elements from the second diagonal of the sum matrix
  printf("\nThe elements of the second diagonal of the sum matrix are:\n");
  for (int i = 0; i < m[2]; i++) {
    int k = m[2] - 1 - i;
    int j = m[2] - 1 - k;
    printf("%d ", mat[2][j][k]);
  }

  // free remaining elements
  for(int j = 0; j < m[2]; j++)
    free(mat[2][j]);

  free(mat[2]);
  free(mat);
}

void read_matrix(int m, int n, int **mat) {
  // read matrix elements

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &mat[i][j]);
}

void add_matrices(int m, int n, int **m1, int **m2, int **ms) {
  // compute the sum of 2 matrices and put the result into the third

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      ms[i][j] = m1[i][j] + m2[i][j];
}
