/*
 * Fufezan Mihai, 2012, lab13, ex 11
 *
 * Write an application that:
 * - reads from the keyboard an integer value n;
 * - reads from the keyboard, with a function, n integers, storing them into a
 * dynamically allocated one-dimensional array;
 * - writes these values into a binary file (the filename is also read from the
 * keyboard);
 * - reads the file’s content and displays the offset and content of all
 * positions where even numbers are found.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  int n, x, k = 0;
  char filename[20];

  printf("Enter the filename to store integers in: ");
  scanf("%[^\n]s", filename);
  getchar();

  printf("Enter the number of integers to read: ");
  scanf("%d", &n);

  FILE *fp = fopen(filename, "wb");
  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%d", &x);
    fwrite(&x, sizeof(int), 1, fp);
  }

  fp = freopen(filename, "rb", fp);

  printf("\nThe numbers on even positions are:\n");
  while (fread(&x, sizeof(int), 1, fp)) {
    if (k % 2 == 0)
      printf("[%d] = %d\n", k, x);
    k++;
  }
}
