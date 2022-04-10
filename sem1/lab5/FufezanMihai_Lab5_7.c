/*
 * Fufezan Mihai, 2012, lab05, ex 7
 *
 * Read from the keyboard an integer number that represents the radius
 * of a circle. Display the length and area of the circle with 3 digits
 * precision, in a field that can store 10 characters. Use a symbolic constant
 * for the value of PI.
 */

#define _CRT_SECURE_NO_WARNINGS
#define PI 3.14
#include <stdio.h>

float length(int);
float area(int);

int main() {
  int radius;

  printf("Enter the radius of a circle: ");
  scanf("%d", &radius);

  printf("The length of the circle is %10.3f\n", length(radius));
  printf("The area of the circle is %10.3f\n", area(radius));
}

float length(int radius) {
  float len = 2 * PI * radius;
  return len;
}

float area(int radius) {
  float area = PI * radius * radius;
  return area;
}
