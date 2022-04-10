/*
 * Fufezan Mihai, 2012, lab07, ex 15
 *
 * Write a program that reads from the keyboard a single character. The program
 * should display that character on n rows, n times in a row, n read from the
 * keyboard.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  int n;
  char c;

  printf("Enter a character: ");
  scanf("%c", &c);
  printf("How many times should we display it? ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%c ", c);
    printf("\n");
  }
}
