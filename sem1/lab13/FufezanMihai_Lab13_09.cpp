/*
 * Fufezan Mihai, 2012, lab13, ex 09
 *
 * Write an application that:
 * - reads from the keyboard an integer value n;
 * - reads from the keyboard (using a function) n floating-point numbers, storing them into a
 * dynamically allocated one-dimensional array;
 * - writes out the floating-point values into a binary file, the filename being read from the
 * keyboard;
 * - reads back the file’s content, displaying the numbers with indexes 0, 3, 6, etc. using the
 * random file-access methods.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  char filename[100];
  
  // read number of elements
  printf("Enter the number of floats you want to read: ");
  scanf("%d", &n);
  
  // create array
  float *arr = (float*)malloc(sizeof(float) * n);
  
  // read array
  for(int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%f", arr + i);
    getchar();
  }
  
  // get filename and write array
  printf("\nEnter the name of the file where the numbers will be stored in: ");
  getchar();
  scanf("%[^\n]s", filename);
  FILE *fp = fopen(filename, "wb");
  fwrite(arr, sizeof(float), n, fp); 
  
  // read back content and display data
  fp = freopen(filename, "r", fp);
  
  for(int i = 0; i < n; i+=3) {
    fread(arr + i, sizeof(float), 1, fp);    
    fseek(fp, 3, SEEK_CUR);
    printf("[%d] = %.1f\n", i, arr[i]);
  }

  // dealloc and close streams
  free(arr);
  fclose(fp);
}
