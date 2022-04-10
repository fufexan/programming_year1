/*
 * Fufezan Mihai, 2012, lab09, ex 6
 *
 * Write a C/C++ program that reads from the keyboard an array of characters.
 * Write a function that displays the characters that are in the array and the
 * number of times they appear. Use pointers.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void print_ch(char *, int);

int main() {
  int n = 50;
  char *x = calloc(sizeof(char) * n, sizeof(char));

  // read string
  printf("Enter a string: ");
  fgets(x, n, stdin);

  printf("\nThe characters present and their counts in the string are:\n");
  print_ch(x, n);
}

void print_ch(char *x, int n) {
  // print characters found inside of string and the number of each

  // find elements and count them
  short *xc = calloc(sizeof(short) * 130, sizeof(short));
  for (int i = 0; i < n && *(x + i) != '\n'; i++)
    (*(xc + *(x + i)))++;

  // print elements
  for (int i = 0; i < 130; i++)
    if (*(xc + i) != 0)
      printf("%c: %d\n", i, *(xc + i));
}
