/*
 * Fufezan Mihai, 2012, lab07, ex 10
 *
 * Write a program that determines the number of figures that compose an integer
 * number read from the keyboard.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int figures(int);

int main() {
  int x;

  printf("Enter an integer number: ");
  scanf("%d", &x);

  printf("The number of figures in the given number is %d", figures(x));
}

int figures(int x) {
  int res = 0;

  while (x) {
    res++;
    x /= 10;
  }

  return res;
}
