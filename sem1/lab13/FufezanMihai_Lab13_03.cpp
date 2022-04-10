/*
 * Fufezan Mihai, 2012, lab13, ex 03
 *
 * Write a program that reads from the keyboard n integer values and then stores
 * them into a text file. The filename has to be read from the keyboard. Then
 * read the numbers from file, calculate their average value, display-it and
 * append-it to the end of the text-file.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

float average(int *, int);

int main() {
  FILE *fp = nullptr;
  int n, x;
  char name[50]{};

  // read filename and open file in write mode
  printf("Enter the filename for storing numbers: ");
  scanf("%50[^\n]s", name);
  fp = fopen(name, "w");

  // read number of ints
  printf("\nEnter the number of integers to store: ");
  scanf("%d", &n);

  // read ints into file
  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%d", &x);
    fprintf(fp, "%d ", x);
  }

  // reopen file in read mode
  fp = freopen(name, "r", fp);

  // read ints from file into array
  int *arr = (int*)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++)
    fscanf(fp, "%d", &arr[i]);

  // reopen file in append mode
  fp = freopen(name, "a", fp);
  
  // compute and display average, then append to the file
  float avg = average(arr, n);
  printf("\nThe average of the integers is %.1f", avg);
  fprintf(fp, "\n%f\n", avg);
  
  // dealloc
  free(arr);
}

float average(int *arr, int n) {
  // compute the average of the array
  
  float s = 0;
  for(int i = 0; i < n; i++)
    s += arr[i];
    
  return s / n;
}
