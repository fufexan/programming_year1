/*
 * Fufezan Mihai, 2012, lab13, ex 08
 *
 * Write a program that reads real values from a previously created file and
 * writes to another file the entire part of the positive numbers read.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  float x;
  FILE *fi = fopen("08.in", "r");
  FILE *fo = fopen("08.out", "w");
  
  if(!fi) {
    printf("No input file!");
    return 1;
  }
  
  while(fscanf(fi, "%f", &x) != EOF)
    if(x >= 0)
      fprintf(fo, "%d ", (int)x);
      
  fclose(fi);
  fclose(fo);
}
