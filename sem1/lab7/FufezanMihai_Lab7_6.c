/*
 * Fufezan Mihai, 2012, lab07, ex 6
 *
 * Write a program that determines the greatest common divisor of 2 integer
 * values read from the keyboard. 
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int gcd(int, int);

int main() {
  int a, b;
  
  printf("Enter 2 integer values: ");
  scanf("%d%d", &a, &b);

  printf("The greatest common divisor of the two numbers is %d", gcd(a, b));
}

int gcd(int a, int b) {
  a = abs(a);
  b = abs(b);

  while(a != b)
    if(a > b)
      a -= b;
    else
      b -= a;
  return a;
}
