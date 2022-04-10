/*
 * Fufezan Mihai, 2012, lab10, ex 2
 *
 * Considering two integer and two float parameters from the command line,
 * display the sum and the product of these parameters.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int isum = atoi(argv[1]) + atoi(argv[2]);
  int iprod = atoi(argv[1]) * atoi(argv[2]);
  float fsum = atof(argv[3]) + atof(argv[4]);
  float fprod = atof(argv[3]) * atof(argv[4]);

  printf("The sum of integers is %d and their product is %d\n", isum, iprod);
  printf("The sum of floats is %.2f and their product is %.2f\n", fsum, fprod);
}
