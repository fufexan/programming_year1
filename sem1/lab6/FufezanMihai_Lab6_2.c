/*
 * Fufezan Mihai, 2012, lab06, ex 2
 *
 * Write a program that reads from the keyboard 3 values representing
 * the lengths of a triangle’s sides and than displays the triangle’s area.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>

float area(int, int, int);

int main() {
  int x, y, z;

  printf("Enter the values of a triangle's sides: ");
  scanf("%d%d%d", &x, &y, &z);

  if (x + y > z && x + z > y && y + z > x && x > 0 && y > 0 && z > 0) {
    printf("The area of the triangle is %.2f", area(x, y, z));
  } else {
    printf("The values do not correspond to a triangle!");
  }

  return 0;
}

float area(int x, int y, int z) {
  float s = (x + y + z) / 2.0f;
  return sqrt(s * (s - x) * (s - y) * (s - z));
}
