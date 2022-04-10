/*
 * Fufezan Mihai, 2012, lab07, ex 12
 *
 * Read from the keyboard an integer number n. Read a series of real
 * numbers, until their sum is greater than n. Display the sum with a 2 digits
 * precision and how many numbers were introduced.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  int n, k = 0;
  float sum = 0, x;

  printf("Enter an integer number: ");
  scanf("%d", &n);

  printf("Now enter a series of real numbers:\n");

  while (sum <= n) {
    printf("Sum is %.2f + ", sum);
    scanf("%f", &x);
    sum += x;
    k++;
  }

  printf("The sum of %d numbers is %.2f, greater than %d.", k, sum, n);
}
