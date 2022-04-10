/*
 * Fufezan Mihai, 2012, lab09, ex 2
 *
 * Write a C/C++ application that generates 20 random numbers, each smaller than
 * 50 (use srand(), rand() and % operator). Write a function that eliminates the
 * odd elements from the one dimensional array (using pointers). Display both
 * the initial and the final array in the main function.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_arr(int, int *);
void x_odd(int *, int *);

int main() {
  int n = 20;
  int arr[n];

  // init rng with current time as seed
  srand(time(0));

  // fill array with generated values
  for (int i = 0; i < n; i++)
    arr[i] = rand() % 50;

  // print array
  printf("The generated array is:\n");
  print_arr(n, arr);

  // eliminate odd numbers from array
  x_odd(&n, arr);

  // print array
  printf("\nThe final array is:\n");
  print_arr(n, arr);
}

void print_arr(int n, int *arr) {
  // display array elements
  for (int i = 0; i < n; i++)
    printf("%d ", *(arr + i));
}

void x_odd(int *n, int *arr) {
  // eliminate odd numbers from the array
  for (int i = 0; i < *n; i++)
    if (*(arr + i) % 2) {
      (*n)--;
      // shift elements to the left
      for (int j = i; j < *n; j++)
        *(arr + j) = *(arr + j + 1);
    }
}
