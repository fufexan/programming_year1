/*
 * Fufezan Mihai, 2012, lab13, ex 02
 *
 * Write a program that reads from a text file 10 integer numbers. The file has
 * to be previously created using a different code or by using the operating
 * system’s facilities. Write the functions that:
 * - order the integers array in ascending/descending order and displays the
 * result
 * - count the number of even numbers in the array and display the result
 * Write the generated results into the original file
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmp(void const *a, void const *b);
void generate_file(FILE *);
void print_file(FILE *, int *);
void sort_arr(int *);

int main() {
  FILE *fp = nullptr;
  int n = 10, arr[n];
  fp = fopen("02.txt", "w+");
  
  generate_file(fp);
  for(int i = 0; i < n; i++)
    fscanf(fp, "%d", &arr[i]);
  
  sort_arr(arr);
  
  print_file(fp, arr);
  
  fp = freopen("02.txt", "w", fp);
  
  print_file(fp, arr);
  
  fclose(fp);
}

void generate_file(FILE *fp) {
  // generate array into file
  
  srand(time(0));
  
  for(int i = 0; i < 10; i++)
    fprintf(fp, "%d ", rand());
}

void sort_arr(int *arr) {
  // sort array

  qsort(arr, 10, sizeof(int), cmp);
}

void print_file(FILE *fp, int *arr) {
  // print array to file
    
  for(int i = 0; i < 10; i++)
    fprintf(fp, "%d ", arr[i]);
}

int cmp(void const *a, void const *b) { return *(int*)a - *(int*)b; }
