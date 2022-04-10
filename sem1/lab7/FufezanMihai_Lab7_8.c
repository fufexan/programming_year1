/*
 * Fufezan Mihai, 2012, lab07, ex 8
 *
 * Calculate the product of 2 integer numbers using additions.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long prod(int, int);

int main() {
  int a, b;
  
  printf("Enter 2 integer numbers: ");
  scanf("%d%d", &a, &b);

  printf("The product of the two numbers is: %li", prod(a, b));
}

long prod(int a, int b) {
  // multiplies 2 integer numbers using addition
  long res = 0;
  
  // ensure negative multiplication works as well
  if (a < 0 && b < 0) a = -a;
  b = abs(b);

  while (b--) res += a;

  return res;
}
