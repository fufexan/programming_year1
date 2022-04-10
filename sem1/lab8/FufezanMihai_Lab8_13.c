/*
 * Fufezan Mihai, 2012, lab08, ex 13
 *
 * Starting from the example 5 which shows how to display a three-dimensional
 * matrix from the perspective of xOy, write a program that goes through the
 * matrix considering the perspective xOz and yOz. Display the data specifying
 * from which perspective they were browsed.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// last limit - planes
#define Max1 3
// middle limit - rows
#define Max2 2
// first limit - columns
#define Max3 4

void print_3d(double[Max1][Max2][Max3], int, int, int);

int main() {
  double arr[Max1][Max2][Max3] = {
      {{-0.1, 0.22, 0.3, 4.3}, {2.3, 4.7, -0.9, 2}},
      {{0.9, 3.6, 4.5, 4}, {1.2, 2.4, 0.22, -1}},
      {{8.2, 3.12, 34.2, 0.1}, {2.1, 3.2, 4.3, -2.0}}};
  int k = Max1, i = Max2, j = Max3;

  printf("3D matrix represented in xOy\n");
  print_3d(arr, k, i, j);
  printf("3D matrix represented in xOz\n");
  print_3d(arr, j, i, k);
  printf("3D matrix represented in yOz\n");
  print_3d(arr, i, k, j);
}

void print_3d(double arr[Max1][Max2][Max3], int k, int i, int j) {
  for (int z = 0; z < k; z++) {
    printf("plane %d\n", z);
    for (int x = 0; x < i; x++) {
      for (int y = 0; y < j; y++) {
        printf("%6.2lf\t", arr[z][x][y]);
      }
      printf("\n\v");
    }
    printf("\n");
  }
}
