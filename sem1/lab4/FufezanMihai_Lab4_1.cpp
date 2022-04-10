/*
 *  Fufezan Mihai, 2012, lab04, ex 1
 *
 *  Write a program that determines the average value of 3 non-integer numbers.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float mean_average(float, float, float);

int main() {
  float a, b, c;

  printf("Enter 3 non-integer numbers:\n");
  scanf("%f%f%f", &a, &b, &c);
  printf("The mean average of the three numbers is: %f", mean_average(a, b, c));

  return 0;
}

float mean_average(float a, float b, float c) { return (a + b + c) / 3.0; }
