/*
 * Fufezan Mihai, 2012, lab10, ex 3
 *
 * Write a C/C++ application that reads from the keyboard an array of characters
 * that has more than 7 elements. Use a pointer for displaying the characters
 * that have the indexes 1, 3, 5 and 7.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n = 9;
  char *str = malloc(sizeof(char) * n);

  // read string
  printf("Enter a string (>7 characters): ");
  fgets(str, n, stdin);
  // verification
  while (strlen(str) < 8) {
    printf("Too short! Retry: ");
    fgets(str, n, stdin);
  }

  // print required chars
  for (int i = 0; i < 7; i += 2)
    printf("%c", *(str + i));
}
