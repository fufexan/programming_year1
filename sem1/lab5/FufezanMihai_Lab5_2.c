/*
 * Fufezan Mihai, 2012, lab05, ex 2
 *
 * Implement an  application that reads from the standard input 2 values for 2
 * capacitors identified with the C1 and C2 variables. The program calls 2
 * functions that calculate the series and parallel equivalent capacity. After
 * that, it displays the results left aligned and with 4 digits precision in the
 * fractional part.
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

  printf("The series equivalent capacitance is %12.3f\n", series(a, b));
  printf("The parallel equivalent capacitance is %10.3f\n", parallel(a, b));
}

float series(float a, float b) {
  float result = a * b / (a + b);
  return result;
}

float parallel(float a, float b) {
  float result = a + b;
  return result;
}

float readf() {
  float x;

  printf("Enter the value of a capacitor: ");
  scanf("%f", &x);
  return x;
}
