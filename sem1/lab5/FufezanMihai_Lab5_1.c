/*
 * Fufezan Mihai, 2012, lab05, ex 1
 *
 * Implement an application that reads from the standard input 2
 * values for 2 resistors identified with the R1 and R2 variables. The
 * program calls 2 functions that calculate the series and parallel equivalent
 * resistance. After that, it displays the results right aligned and with 3
 * digits precision in the fractional part.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float parallel(float, float);
float series(float, float);
float readf();

int main() {
  float a, b;
  a = readf();
  b = readf();

  printf("The series equivalent resistance is %12.3f\n", series(a, b));
  printf("The parallel equivalent resistance is %10.3f\n", parallel(a, b));
}

float parallel(float a, float b) {
  // compute parallel resistance

  float result = a * b / (a + b);
  return result;
}

float series(float a, float b) {
  // compute series resistance

  float result = a + b;
  return result;
}

float readf() {
  // read float

  float x;

  printf("Enter the value of a resistor: ");
  scanf("%f", &x);
  return x;
}
