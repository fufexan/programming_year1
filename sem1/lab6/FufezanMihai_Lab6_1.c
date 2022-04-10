/*
 * Fufezan Mihai, 2012, lab06, ex 1
 *
 * Write a program that displays the value of a 3-rd degree polynom, calculated
 * in a certain point x.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long poly(int, int, int, int, int);

int main() {
  int a, b, c, d, x;

  printf("Enter the coefficients of a 3rd degree polynomial: ");
  scanf("%d%d%d%d", &a, &b, &c, &d);
  printf("Enter a value for x: ");
  scanf("%d", &x);

  printf("The value of the polynomial is %ld", poly(a, b, c, d, x));
}

long poly(int a, int b, int c, int d, int x) {
  return (x * x * x * a + x * x * b + x * c + d);
}
