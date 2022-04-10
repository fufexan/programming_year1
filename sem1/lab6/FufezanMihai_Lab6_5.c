/*
 * Fufezan Mihai, 2012, lab06, ex 5
 *
 * Write a program that reads from the standard input an integer number
 * and displays the number of zeroes from its binary representation.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int binary(int x);

int main() {
  int x;
  printf("Enter an integer value: ");
  scanf("%d", &x);

  printf("The number of 0's in the binary representation is: %d", binary(x));
}

int binary(int x) {
  int o = 0, nr = sizeof(x) * 8;

  while (x) {
    if(x % 2) o++;
    x >>=1;
  }

  return nr - o;
}