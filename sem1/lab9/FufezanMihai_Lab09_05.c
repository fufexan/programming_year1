/*
 * Fufezan Mihai, 2012, lab09, ex 5
 *
 * Write a C/C++ application that reads from the keyboard two arrays of
 * characters and displays the total number of individual characters (the number
 * of characters that are in the first array and do not exist in the second one
 * + the number of characters that are in the second array and do not exist in
 * the first one). Use pointers for accessing the arrays of elements.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int num_distinct_chars(char *, char *, int);

int main() {
  // define pointers to arrays
  int n = 50;
  char *x = calloc(sizeof(char) * n, sizeof(char));
  char *y = calloc(sizeof(char) * n, sizeof(char));

  // read arrays
  printf("Enter a string: ");
  fgets(x, n, stdin);
  printf("Enter another string: ");
  fgets(y, n, stdin);

  printf("\nThe number of characters not shared by the strings is %d",
         num_distinct_chars(x, y, n));
}

int num_distinct_chars(char *x, char *y, int n) {
  // return num of characters that exist only in either of the arrays, but not
  // in both

  // these will keep track of the chars found
  short *xc = calloc(sizeof(short) * 130, sizeof(short));
  short *yc = calloc(sizeof(short) * 130, sizeof(short));

  // add chars to array. don't go further than \n because we don't need to count
  // NULLs
  for (int i = 0; i < n && *(x + i) != '\n'; i++)
    (*(xc + *(x + i)))++;
  // do this twice as the position of \n isn't the same
  for (int i = 0; i < n && *(y + i) != '\n'; i++)
    (*(yc + *(y + i)))++;

  // keep a counter
  int k = 0;
  // check characters present in both strings
  for (int i = 0; i < 130; i++)
    // there must be exactly one string containing a given character
    if (*(xc + i) == 0 && *(yc + i) != 0 || *(xc + i) != 0 && *(yc + i) == 0)
      k++;

  return k;
}
