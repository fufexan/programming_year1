/*
 * Fufezan Mihai, 2012, lab13 ex 04
 *
 * Write a program that reads from the keyboard a single character and an
 * integer value n. Generate a text file that will contain n lines and on each
 * line write the character n times, n being read from the keyboard.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  FILE *fp = nullptr;
  char c;
  int x;
  fp = fopen("04.txt", "w");
  
  // read number and char
  printf("Enter a number and a character: ");
  scanf("%d %c", &x, &c);
  
  // print
  for(int i = 0; i < x; i++) {
    for(int j = 0; j < x; j++)
      fprintf(fp, "%c", c);
    fprintf(fp, "\n");
  }
  
  fclose(fp);
}
