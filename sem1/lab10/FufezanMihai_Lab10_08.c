/*
 * Fufezan Mihai, 2012, lab10, ex 8
 *
 * Write a C/C++ program that inverts a string of characters read from the
 * command line.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *revstr(char *);

int main() {
  char *str = calloc(sizeof(char) * 50, sizeof(char));
  // make sure we don't leave unmanaged memory
  char *stc = str;

  // read string
  puts("Enter a string");
  fgets(str, 50, stdin);

  // get rid of newline
  char *c = strchr(str, '\n');
  strncpy(c, "\0", 1);

  // reverse the string
  str = revstr(str);
  printf("The reversed string is: %s", str);

  // deallocate
  free(str);
  free(stc);
}

char *revstr(char *str) {
  // takes a string and returns it reversed

  int len = strlen(str);
  char *rev = calloc(sizeof(char) * (len + 1), sizeof(char));

  for (int i = 0; i < len; i++)
    rev[i] = str[len - i - 1];
  strcat(rev, "\0");

  return rev;
}
