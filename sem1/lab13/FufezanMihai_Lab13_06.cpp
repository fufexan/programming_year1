/*
 * Fufezan Mihai, 2012, lab13, ex 06
 *
 * Write a C/C++ program that reads from the keyboard (with confirmation) a
 * series of float values. Write the values into a text file that has the name
 * entered from the command line. Read the file’s content and display all the
 * values greater than a given number, read from the keyboard.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  char c = 'y';
  float x, m;
  char filename[21];
  FILE *fp = nullptr;

  printf("Enter the filename to store floats in: ");
  scanf("%[^\n]s", filename);
  getchar();
  fp = fopen(filename, "w");

  while (c == 'y' || c == 'Y' || c == '\n') {
    printf("Enter a real number: ");
    scanf("%f", &x);
    fprintf(fp, "%f ", x);

    printf("Continue entering values? (Y/n) ");
    getchar();
    scanf("%c", &c);
  }

  fp = freopen(filename, "r", fp);

  printf("Enter the minimum value to display: ");
  scanf("%f", &m);

  printf("\nThe numbers you entered are:\n");
  while (fscanf(fp, "%f", &x) != EOF)
    if (x >= m)
      printf("%f ", x);
}
