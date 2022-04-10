/*
 * Fufezan Mihai, 2012, lab13, ex 14
 *
 * Write into a binary file a series of integer numbers read from the keyboard.
 * Read back the numbers stored in the file on odd positions displaying wether
 * they are odd or even numbers.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  char c = 'y';
  int x;
  FILE *fp = fopen("14.bin", "wb");
  
  do {
    printf("\nEnter a number: ");
    scanf("%d", &x);
    fwrite(&x, sizeof(int), 1, fp);
    
    // continue confirmation
    printf("Continue entering? Y/n ");
    getchar();
    scanf("%c", &c);
  } while(c == 'y' || c == 'Y' || c == '\n');
  
  fp = freopen("14.bin", "rb", fp);
  
  
  // print values in file
  printf("\nThe values on odd positions are:\n");
  
  fseek(fp, sizeof(int), SEEK_CUR);
  while(fread(&x, sizeof(int), 1, fp)) {
    printf("%d is %s\n", x, x % 2 ? "odd" : "even");
    fseek(fp, sizeof(int), SEEK_CUR);
  }
  
  fclose(fp);
}
