/*
 * Fufezan Mihai, 2012, lab10, ex 7
 *
 * Write a C/C++ program that reads some character arrays from the command line
 * and displays the resulting concatenated string.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int count = 0;

  printf("Enter the number of strings you want to read: ");
  scanf("%d", &count);
  getchar(); // get rid of newline

  // allocate arrays
  char *str = malloc(sizeof(char) * 50 * count);
  char *crt = malloc(sizeof(char) * 50);

  for (int i = 0; i < count; i++) {
    // read each string
    printf("str %d: ", i);
    fgets(crt, 50, stdin);

    // get rid of newline
    char *c = strchr(crt, '\n');
    strcpy(c, "\0");

    // append to str
    strcat(str, crt);
  }

  // print concatenated strings
  printf("%s", str);

  // deallocate memory
  free(crt);
  free(str);
}
