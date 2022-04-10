/*
 * Fufezan Mihai, 2012, lab11, ex 04
 *
 * Write a program reads n characters arrays from the keyboard and stores them
 * into n dinamically allocated memory zones
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char *read(int);

int main() {
  int n;

  printf("How many strings do you want to read? ");
  scanf("%d", &n);
  getchar();

  // alloc and read
  char **str = malloc(sizeof(char *) * n);
  for (int i = 0; i < n; i++)
    str[i] = read(i);

  // print and dealloc
  puts("\nThe strings entered are:");
  for (int i = 0; i < n; i++) {
    printf("%s", str[i]);
    free(str[i]);
  }
  free(str);
}

char *read(int x) {
  // read a string

  char *s = malloc(sizeof(char) * 50);
  printf("String %d: ", x);
  fgets(s, 50, stdin);

  return s;
}
