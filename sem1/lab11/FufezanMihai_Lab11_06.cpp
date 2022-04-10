/*
 * Fufezan Mihai, 2012, lab11, ex 06
 *
 * Use the dynamic allocation for a matrix of m x n integer values (m, n <7).
 * Initialize the elements of the matrix. If n is equal to m, use the Sarrus
 * method to obtain the value of the “determinant”. Display the result and free
 * the allocated memory.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int sarrus(int **);

int main() {
  int n, m;

  printf("Enter the dimensions of a matrix: ");
  scanf("%d%d", &m, &n);
  while (m > 7 && n > 7) {
    printf("The values have to be 7 or lower! Reenter: ");
    scanf("%d%d", &m, &n);
  }

  if (m == n && m == 3) {
    // alloc matrix
    int **a = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
      a[i] = (int *)malloc(sizeof(int) * n);

    // read elements
    puts("Enter the matrix elements:");
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        scanf("%d", *(a + i) + j);

    // print determinant
    printf("\nThe determinant is %d.\n", sarrus(a));

    // dealloc
    for (int i = 0; i < n; i++)
      free(a[i]);
    free(a);
  } else
    puts("The determinant couldn't be calculated using Sarrus' rule because "
         "the matrix isn't 3x3.");
}

int sarrus(int **a) {
  // compute the determinant of a 3x3 matrix using Sarrus' rule

  int res = 0;
  res += a[0][0] * a[1][1] * a[2][2];
  res += a[1][0] * a[2][1] * a[0][2];
  res += a[2][0] * a[0][1] * a[1][2];
  res -= a[0][2] * a[1][1] * a[2][0];
  res -= a[1][2] * a[2][1] * a[0][0];
  res -= a[2][2] * a[0][1] * a[1][0];

  return res;
}
