/*
 * Fufezan Mihai, 2012, lab08, ex 7
 *
 * Read from the keyboard the elements of a 3x3 float matrix. Rearrange the
 * columns so that the sum of each column's elements is smaller than the sum of
 * the elements of the next column to the right.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void order_columns(int n, float mat[n][n]);
float sum_column(int n, int c, float mat[n][n]);
void switch_columns(int n, float mat[n][n], int c1, int c2);

int main() {
  int n = 3;
  float mat[n][n];

  // read matrix
  printf("Enter the elements of a 3x3 matrix (real numbers):\n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%f", &mat[i][j]);

  // order and display matrix
  order_columns(n, mat);
}

void order_columns(int n, float mat[n][n]) {
  // sort columns in order of their elements' sums

  // get the sum of all columns
  float s[n];
  for (int i = 0; i < n; i++)
    s[i] = sum_column(n, i, mat);

  printf("\n");
  // print the sums
  for (int i = 0; i < n; i++)
    printf("Sum of column %d = %.1f\n", i, s[i]);
  printf("\n");

  // switch columns
  if (s[0] < s[1] && s[1] < s[2] && s[0] < s[2] ||
      s[0] == s[1] && s[1] < s[2] || s[0] == s[1] && s[1] == s[2])
    printf("Matrix is already sorted.");
  else {
    do {
      if (s[0] > s[1])
        switch_columns(n, mat, 0, 1);
      else if (s[1] > s[2])
        switch_columns(n, mat, 1, 2);
      else if (s[0] > s[2])
        switch_columns(n, mat, 0, 2);

      // get the sum for all matrices again
      for (int i = 0; i < n; i++)
        s[i] = sum_column(n, i, mat);

    } while (s[0] > s[1] || s[1] > s[2] || s[0] > s[2]);

    // print sorted matrix
    printf("The sorted matrix is:\n");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        printf("%.1f ", mat[i][j]);
      printf("\n");
    }
  }
}

void switch_columns(int n, float mat[n][n], int c1, int c2) {
  // switches the elements of two columns
  for (int i = 0; i < n; i++) {
    float temp = mat[i][c1];
    mat[i][c1] = mat[i][c2];
    mat[i][c2] = temp;
  }
}

float sum_column(int n, int c, float mat[n][n]) {
  // calculate the sum of all the elements of a column
  float sum = 0;

  for (int i = 0; i < n; i++)
    sum += mat[i][c];

  return sum;
}
