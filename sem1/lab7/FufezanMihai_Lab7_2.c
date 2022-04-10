/*
 * Fufezan Mihai, 2012, lab07, ex 2
 *
 * Please verify if a natural number introduced from the keyboard is a perfect
 * square or not.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool is_pfsq(unsigned int);

int main() {
  unsigned int x;
  printf("Enter a natural number: ");
  scanf("%d", &x);

  printf("The number is%s a perfect square", is_pfsq(x) ? "" : "n't");
}

bool is_pfsq(unsigned int x) {
  int x_int = (int) sqrt(x);
  return (float) x_int == sqrt(x);
}
