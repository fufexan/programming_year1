/*
 *  Fufezan Mihai, 2012, lab04, ex 7
 *
 *  Display the value of 1/a + 1/b + 1/c.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float readf();
int readi();

int main() {
  float a, b, c;
  int d, e, f;

  a = readf();
  b = readf();
  c = readf();

  float resultf = 1 / a + 1 / b + 1 / c;
  printf("The value of the real numbers: %f\n", resultf);

  d = readi();
  e = readi();
  f = readi();

  float resulti = 1 / (float)d + 1 / (float)e + 1 / (float)f;
  printf("The value of the integer numbers: %f\n", resulti);

  return 0;
}

float readf() {
  // read float

  float nr;
  printf("Enter a real number: ");
  scanf("%f", &nr);
  return nr;
}

int readi() {
  // read int
  
  int nr;
  printf("Enter an integer number: ");
  scanf("%d", &nr);
  return nr;
}
