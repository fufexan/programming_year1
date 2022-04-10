/*
 * Fufezan Mihai, 2012, lab05, ex 3
 *
 * Read from the standard input 2 integer values that represent the catheters of
 * a rectangular triangle. Determine the hypotenuse and the perimeter of the
 * triangle. Display the results on different lines.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>

float hypothenuse(int, int);
float perimeter(int, int);
int readint();

int main() {
  int x, y;

  x = readint();
  y = readint();

  printf("The hypothenuse of the given triangle is: %.2f\n", hypothenuse(x, y));
  printf("The perimeter of the given triangle is: %.2f\n", perimeter(x, y));
}

float hypothenuse(int a, int b) {
  float h = sqrt(a * a + b * b);
  return h;
}

float perimeter(int a, int b) {
  float p = a + b + hypothenuse(a, b);
  return p;
}

int readint() {
  int x;
  printf("Enter an integer value: ");
  scanf("%d", &x);
  return x;
}
