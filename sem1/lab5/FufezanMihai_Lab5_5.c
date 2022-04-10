/*
 * Fufezan Mihai, 2012, lab05, ex 5
 *
 * Implement the 1-st and 2-nd problems in a single program. Make use
 * of all the possible similarities.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float division(float, float);
float addition(float, float);
float readf(char *);
void printeq(char *, float, float);

int main() {
  float a, b;
  int choice;

  printf("Do you want to calculate resistance or capacitance? (0 or 1): ");
  scanf("%d", &choice);

  if (choice) {
    a = readf("C1");
    b = readf("C2");

    printeq("capacitance", division(a, b), addition(a, b));
  } else {
    a = readf("R1");
    b = readf("R2");

    printeq("resistance", addition(a, b), division(a, b));
  }
}

float division(float a, float b) {
  float result = a * b / (a + b);
  return result;
}

float addition(float a, float b) {
  float result = a + b;
  return result;
}

float readf(char *c) {
  float x;

  printf("Enter the value of %s: ", c);
  scanf("%f", &x);
  return x;
}

void printeq(char *type, float series, float parallel) {
  printf("The series equivalent %s is %12.3f\n", type, series);
  printf("The parallel equivalent %s is %10.3f\n", type, parallel);
}
