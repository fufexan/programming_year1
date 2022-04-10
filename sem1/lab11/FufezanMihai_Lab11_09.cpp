/*
 * Fufezan Mihai, 2012, lab11, ex 09
 *
 * Write a program that reads strings that can contain space that are
 * concatenated into another, dynamically allocated string. Display the initial
 * strings entered (less than 256 characters each), the concatenated one (the
 * strings will be separated by a space), the independent words (separated by a
 * space using strtoken ()), and their number. Free up dynamically allocated
 * memory. Repeat the process as many times as the user wants. Generalize
 * considering as delimitators the string: char delimiters[] = " .,;:!?-";
 * instead of space.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n, size = 256, fsize = 0, nrwords = 0;
  char delimiters[] = " .,;:!?-";

  printf("How many strings do you want to enter? ");
  scanf("%d", &n);
  getchar();

  // allocate array of strings
  char **a = (char **)malloc(sizeof(char *) * n);

  // allocate and read strings
  for (int i = 0; i < n; i++) {
    a[i] = (char *)calloc(sizeof(char) * size, sizeof(char));
    // read string
    fgets(a[i], size, stdin);
    // remove trailing newline
    a[i][strlen(a[i]) - 1] = '\0';
    // increase concatenated string size
    fsize += strlen(a[i]) + 1;
  }

  // concat
  char *s = (char *)malloc(sizeof(char) * fsize);
  for (int i = 0; i < n; i++) {
    strcat(s, a[i]);
    strcat(s, " ");
  }

  // display
  puts("\nThe initial strings were:");
  for (int i = 0; i < n; i++)
    printf("%s\n", a[i]);

  printf("\nThe concatenated strings form:\n%s\n", s);

  // print individual words and count them
  puts("\nThe individual tokens of the string are:");
  char *p = strtok(s, delimiters);
  while (p != NULL) {
    printf("%s\n", p);
    p = strtok(NULL, delimiters);
  }

  // dealloc
  for (int i = 0; i < n; i++)
    free(a[i]);
  free(a);
  free(s);
  free(p);
}
