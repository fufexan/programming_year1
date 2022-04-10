/*
 * Fufezan Mihai, 2012, lab07, ex 1
 *
 * Read from the keyboard 3 integer numbers (a, b and c). Determine the area of
 * the rectangle that has the sides equal to a and b and verify if the rectangle’s
 * diagonal is equal to c. 
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool diagonal(int, int, int);

int main() {
  int a, b, c;

  printf("Enter 3 integer numbers: ");
  scanf("%d%d%d", &a, &b, &c);

  printf("The area of the rectangle is %d\n", a * b);
  printf("The diagonal is%s c.", diagonal(a, b, c) ? "" : "n't");
}

bool diagonal(int a, int b, int c) {
   // check whether a given diagonal is equal to the computed one
   // 
   // returns true/false

   int py = a * a + b * b;
   float expr = sqrt(py);
   return c == expr;
}