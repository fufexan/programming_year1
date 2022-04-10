/*
 * Fufezan Mihai, 2012, lab07, ex 7
 *
 * Write a program that determines all the divisors of a value introduced from the KBD.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

void find_divisors(int);

int main() {
  int x;

  printf("Enter an integer value: ");
  scanf("%d", &x);

  printf("Its divisors are: ");
  find_divisors(x);
}

void find_divisors(int x) {
  // print all the divisors of an integer number
  if (x < 0) {
    printf("%d ", x);
    for(int i = x/2; i < -1; i++)
      if(x % i == 0) printf("%d ", i);
  }

  for(int i = 2; i <= abs(x)/2; i++)
    if(x % i == 0) printf("%d ", i);
  printf("%d", abs(x));
}
