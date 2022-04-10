/*
 * Fufezan Mihai, 2012, lab13, ex 01
 *
 * Write a program that displays the integer elements read from a text file. The
 * filename is entered from the keyboard. The file has to be created in another
 * program or function.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void open_file(FILE **);

int main() {
  int x, n;
  FILE *fp = nullptr;

  open_file(&fp);

  // check if the file could be opened
  if(fp == NULL) {
    printf("File does not exist!");
    return 1;
  }
  
  // read number of elements
  fscanf(fp, "%d", &n);

  // read the numbers
  for(int i = 0; i < n - 1; i++) {
    fscanf(fp, "%d", &x);
    printf("%d ", x);
  }
  
  fclose(fp);
}

void open_file(FILE **fp) {
  // open a file for reading
  
  *fp = fopen("01.txt", "r");
}
