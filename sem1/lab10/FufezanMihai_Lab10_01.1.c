/*
 * Fufezan Mihai, 2012, lab10, ex 1.1 - lab08, ex 1
 *
 * Write a C/C++ code, that determines the mean value of the negative/positive
 * elements from a one-dimensional array. (using pointers)
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float mean(int *, int, int);

int main() {
  int n;
  printf("Enter the number of elements in an array: ");
  scanf("%d", &n);

  int v[n];
  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%d", v + i);
  }

  printf("The mean value of the negative elements is: %.3f\n", mean(v, n, -1));
  printf("The mean value of the positive elements is: %.3f\n", mean(v, n, 1));
}

float mean(int *v, int dim, int p) {
  int neg = 0, pos = 0;
  float s_neg = 0, s_pos = 0;

  for (int i = 0; i < dim; i++) {
    if (*(v + i) < 0) {
      s_neg += *(v + i);
      neg++;
    } else {
      s_pos += *(v + i);
      pos++;
    }
  }

  if (!pos)
    pos++;
  if (!neg)
    neg++;

  return p == 1 ? s_pos / pos : s_neg / neg;
}
