/*
 *  Fufezan Mihai, 2012, lab04, ex 5
 *
 *  Write a program that defines 3 integer values. Calculate and display their
 *  weighted sum, the weights being represented as positive values smaller than
 *  1 that add up to 1.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int readi();

int main() {
  int a, b, c;

  a = readi();
  b = readi();
  c = readi();

  float result = a * 0.2 + b * 0.5 + c * 0.3;

  printf("The weighed sum of the numbers is %f", result);

  return 0;
}

int readi() {
  // read integer

  int nr;
  printf("Enter an integer: ");
  scanf("%d", &nr);
  return nr;
}
