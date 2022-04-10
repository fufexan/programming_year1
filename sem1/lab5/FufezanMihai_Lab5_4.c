/*
 * Fufezan Mihai, 2012, lab05, ex 4
 *
 * Read from the keyboard 2 integer values, a and b (a!=0),
 * representing the coefficients of the equation ax+b=0. Solve the equation
 * and display the result.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>

int readint();
float findx(int, int);

int main() {
  int a, b;

  a = readint();
  b = readint();

  if (a == 0) {
    printf("a needs to be non-zero!");
    return 1;
  };

  printf("In the equation ax + b = 0, x is %f\n", findx(a, b));

  return 0;
}

float findx(int a, int b) {
  float x;
  x = -b / (float)a;
  return x;
}

int readint() {
  int x;
  printf("Enter an integer value: ");
  scanf("%d", &x);
  return x;
}
