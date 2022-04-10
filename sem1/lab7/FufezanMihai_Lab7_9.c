/*
 * Fufezan Mihai, 2012, lab07, ex 9
 *
 * Write a program that determines the integer quotient of 2 integer numbers
 * using a series of subtractions.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int quotient(int, int);

int main() {
  int a, b;

  printf("Enter 2 integer numbers to divide: ");
  scanf("%d%d", &a, &b);

  printf("The quotient of the two numbers is %d", quotient(a, b));
}

int quotient(int a, int b) {
  // computes the result of dividing a and b using repeated substractions
  bool neg = false;
  int res = 0;

  // handle negatives
  if (a < 0 && b < 0 || a >= 0 && b >= 0)
    neg = true;
  a = abs(a);
  b = abs(b);

  while (a > 0 && a - b >= 0) {
    res++;
    a -= b;
  }

  return neg ? res : -res;
}
