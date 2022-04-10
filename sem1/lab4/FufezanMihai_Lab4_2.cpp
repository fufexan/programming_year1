/*
 *  Fufezan Mihai, 2012, lab04, ex 2
 *
 *  Write a program that determines the geometric average of 2 integer numbers.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

float geometric_average(int, int);

int main() {
  int a, b;

  printf("Enter 2 integer numbers:\n");
  scanf("%d%d", &a, &b);
  printf("The geometric average of the two numbers is: %f",
         geometric_average(a, b));

  return 0;
}

float geometric_average(int a, int b) { return sqrt(a * b); }
