/*
 * Fufezan Mihai, 2012, lab11, ex 11
 *
 * Generate an array of pointers to constant strings using the strdup() method
 * or a specific method. Display the even entries of the array.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n = 7;
  // alloc and define first string
  const char **str1 = (const char **)malloc(sizeof(char *) * n);
  *(str1 + 0) = "hello";
  *(str1 + 1) = "there";
  *(str1 + 2) = "how";
  *(str1 + 3) = "are";
  *(str1 + 4) = "you";
  *(str1 + 5) = "today";
  *(str1 + 6) = "?";

  // alloc second string array
  const char **str2 = (const char **)malloc(sizeof(char *) * n);

  // duplicate strings
  for(int i = 0; i < n; i++)
    *(str2 + i) = strdup(*(str1 + i));

  // print elements
  for (int i = 0; i < n; i += 2)
    printf("%s\n", str2[i]);

  // free memory
  for (int i = 0; i < n; i++) {
    free(str1+i);
    free(str2+i);
  }
  free(str1);
  free(str2);
}
