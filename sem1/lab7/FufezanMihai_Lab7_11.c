/*
 * Fufezan Mihai, 2012, lab07, ex 11
 *
 * Write a program that reads from the keyboard n integer numbers. Display all
 * the odd numbers and store them in an array.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  int n;

  printf("Enter the number of integers you want to read: ");
  scanf("%d", &n);

  int v[n];
  printf("Enter the integer numbers:\n");
  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%d", &v[i]);
  }

  for (int i = 0; i < n; i++)
    if (v[i] % 2)
      printf("%d ", v[i]);
}
