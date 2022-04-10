/*
 * Fufezan Mihai, 2012, lab07, ex 3
 *
 * Write a program that calculates an, by repeated multiplications where n is
 * read from the keyboard (a is “hard coded”). 
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  int a = 5, n, res = 1;
  
  printf("Enter an integer value: ");
  scanf("%d", &n);

  for(int i = 0; i < n; i++)
    res *= a;

  printf("%d^%d = %d", a, n, res);
}
