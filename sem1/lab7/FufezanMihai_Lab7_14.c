/*
 * Fufezan Mihai, 2012, lab07, ex 14
 *
 * Write a program that reads n integer numbers from the keyboard and
 * displays those that can be divided by 3
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  int n, x;

  printf("How many integers do you want to read? ");
  scanf("%d", &n);

  int v[n];

  for (int i = 0; i < n; i++) {
    printf("[%d]: ", i);
    scanf("%d", &v[i]);
  }

  printf("The numbers divisible by 3 are ");
  for (int i = 0; i < n; i++)
    if (v[i] % 3 == 0)
      printf("%d ", v[i]);
}
