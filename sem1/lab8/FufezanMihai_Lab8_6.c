/*
 * Fufezan Mihai, 2012, lab08, ex 6
 *
 * Write a C/C++ application that defines two matrices of integer values. The
 * matrices' dimensions and their elements are read from the keyboard. Write the
 * functions that display:
 *   a) the positions of the odd elements in each matrix;
 *   b) the sum of all even elements in both matrices;
 *   c) the sum of the two initial matrices;
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void pos_odd(int n, int m, int[n][m]);
long sum_even(int n, int m, int mat[n][m]);
void matrix_sum(int n1, int m1, int n2, int m2, int mat1[n1][m1],
                int mat2[n2][m2]);

int main() {
  int n1, m1, n2, m2;

  // read matrix dimensions
  printf("Enter the dimensions for the first matrix: ");
  scanf("%d%d", &n1, &m1);
  printf("Enter the dimensions for the second matrix: ");
  scanf("%d%d", &n2, &m2);

  int mat1[n1][m1];
  int mat2[n2][m2];

  // read elements
  printf("Enter the elements of the first matrix:\n");
  for (int i = 0; i < n1; i++)
    for (int j = 0; j < m1; j++)
      scanf("%d", &mat1[i][j]);

  printf("Enter the elements of the second matrix:\n");
  for (int i = 0; i < n2; i++)
    for (int j = 0; j < m2; j++)
      scanf("%d", &mat2[i][j]);

  printf("\n");

  // a)
  printf("The odd elements of the first matrix are:\n");
  pos_odd(n1, m1, mat1);
  printf("The odd elements of the second matrix are:\n");
  pos_odd(n2, m2, mat2);

  printf("\n");

  // b)
  long s1 = sum_even(n1, m1, mat1);
  long s2 = sum_even(n2, m2, mat2);
  printf("The sum of all even elements from both matrices is %li\n", s1 + s2);

  printf("\n");

  // c)
  matrix_sum(n1, m1, n2, m2, mat1, mat2);
}

void pos_odd(int n, int m, int mat[n][m]) {
  // check and display where the odd elements are in a matrix
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (mat[i][j] % 2)
        printf("[%d][%d] = %d\n", i, j, mat[i][j]);
}

long sum_even(int n, int m, int mat[n][m]) {
  // calculate the sum of all even numbers in a matrix
  long sum = 0;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (mat[i][j] % 2)
        sum += mat[i][j];

  return sum;
}

void matrix_sum(int n1, int m1, int n2, int m2, int mat1[n1][m1],
                int mat2[n2][m2]) {
  // check if matrices have the same sizes
  if (n1 != n2 || m1 != m2) {
    printf("The matrices can't be added!");
  } else {
    // addition
    for (int i = 0; i < n1; i++)
      for (int j = 0; j < m1; j++)
        mat1[i][j] += mat2[i][j];

    // print the elements
    for (int i = 0; i < n1; i++) {
      for (int j = 0; j < m1; j++)
        printf("%d ", mat1[i][j]);
      printf("\n");
    }
  };
}
