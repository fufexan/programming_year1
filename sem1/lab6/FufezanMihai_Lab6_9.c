/*
 * Fufezan Mihai, 2012, lab06, ex 9
 *
 * Read 2 integer values from the keyboard. If they are equal, determine the
 * area of a circle that has the radius equal with the read value. If the values
 * are not equal, determine the area of the rectangle that has as sides the
 * read values. In both cases, display the name of the geometrical shape
 * that corresponds to the calculated area.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float c_area(int);

int main() {
  int a, b;

  printf("Enter 2 integer values: ");
  scanf("%d%d", &a, &b);

  if (a == b)
    printf("The area of the circle with the radius you entered is %f",
           c_area(a));
  else
    printf("The area of the rectangle with the lengths you entered is %d",
           a * b);
}

float c_area(int r) {
  // computes the area of a circle given by a radius
  // returns area as a float

  const float pi = 3.14;

  return pi * r * r;
}
