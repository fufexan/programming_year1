/*
 * Fufezan Mihai, 2012, lab09, ex 4
 *
 * Write a C/C++ application that reads from the keyboard an array of characters
 * and displays the string obtained by eliminating the characters that appear
 * more than once in the original array using pointers.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rmextra(char *, int);

int main() {
  int n = 50;
  // init char array
  char *x = calloc(n * sizeof(char), sizeof(char));
  // read array
  printf("Enter a string: ");
  fgets(x, n, stdin);

  // remove extra chars then print string
  rmextra(x, n);
  printf("%s", x);
}

void rmextra(char *x, int n) {
  // check and remove extra chars
  // create array where to keep track of already present chars
  bool *a = calloc(130 * sizeof(bool), sizeof(bool));

  // iterate through the array and find doubled elements
  for (int i = 0; i < n; i++) {
    bool *crt = a + *(x + i);

    if (!*crt)
      *crt = true;
    else {
      // left-shift elements to remove current one
      for (int j = i; j < n - 1; j++)
        *(x + j) = *(x + j + 1);
      // make sure we don't enter infinite loops
      n--, i--;
    }
  }
}
