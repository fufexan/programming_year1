/*
 * Fufezan Mihai, 2012, lab08, ex 12
 *
 * Read from the keyboard the elements of an m x n integer matrix.
 * If the matrix is square, display the elements from the secondary diagonal. If
 * not, print the sum of all the elements from a certain column, c. The values
 * of m, n and c are read from the keyboard. All the operations should be
 * implemented in specific functions.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void read_matrix(int m, int n, int mat[m][n]);
void print_secondary(int m, int mat[m][m]);
int sum_column(int n, int c, int mat[][n]);

int main() {
  int m, n;

  // read matrix size
  printf("Enter the dimensions of a matrix: ");
  scanf("%d%d", &m, &n);

  // define matrix and read elements
  int mat[m][n];
  read_matrix(m, n, mat);

  printf("\n");
  if (m == n) {
    printf("The elements of the second diagonal are:\n");
    print_secondary(m, mat);
  } else {
    int c;
    printf("Enter the number of a column (<%d): ", n);
    scanf("%d", &c);

    // print the sum on the column
    printf("The sum of the elements on column %d is %d.", c, sum_column(n, c, mat));
  }
}

void read_matrix(int m, int n, int mat[m][n]) {
  // read matrix elements
  printf("Enter the matrix's elements:\n");
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &mat[i][j]);
}

void print_secondary(int m, int mat[m][m]) {
  // print elements from the secondary diagonal
  for (int i = 0; i < m; i++)
    printf("%d ", mat[i][m - i - 1]);
}

int sum_column(int n, int c, int mat[][n]) {
  // calculate the sum of all the elements of a column
  int sum = 0;

  for (int i = 0; i < n; i++)
    sum += mat[i][c];

  return sum;
}