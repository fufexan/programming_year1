/*
 * Fufezan Mihai, 2012, lab13, ex 07
 *
 * Write a C/C++ application that reads a text file character by character and
 * converts the first letter of each word into its uppercase equivalent.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  FILE *fp = fopen("07.txt", "r");
  char x, y;
 
  if(fp == NULL) {
    printf("File does not exist!");
    return 1;
  }
  
  x = ' ';
  while(fscanf(fp, "%c", &y) != EOF) {
    if(x == ' ' && y >= 'a' && y <= 'z')
      y -= 32;
    printf("%c", y);
    x = y;
  }
  
  fclose(fp);
}
