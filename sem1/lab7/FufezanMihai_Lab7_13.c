/*
 * Fufezan Mihai, 2012, lab07, ex 13
 *
 * Determine the least common multiple of 2 integer numbers read from the
 * keyboard.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int gcd(int, int);
int lcm(int, int);

int main() {
  int a, b;

  printf("Enter 2 integer numbers to calculate the least common multiple: ");
  scanf("%d%d", &a, &b);

  printf("Their least common multiple is %d", lcm(a, b));
}

int gcd(int a, int b) {
  a = abs(a);
  b = abs(b);

  while (a != b)
    if (a > b)
      a -= b;
    else
      b -= a;
  return a;
}

int lcm(int a, int b) { return a * b / gcd(a, b); }
