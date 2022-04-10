/*
 * Fufezan Mihai, 2012, lab07, ex 4
 *
 * Write a program that reads from the keyboard an integer value n and
 * calculates n! (n-factorial).
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long factorial(int);

int main() {
  int x;
 
  printf("Enter an integer value: ");
  scanf("%d", &x);

  printf("%d! = %li", x, factorial(x));
}

long factorial(int x) {
  if(x == 0) return 1;
  return x * factorial(x - 1);
}
