/*
 * Fufezan Mihai, 2012, lab08, ex 8
 *
 * Write a program that reads from the keyboard n integer values into a
 * one-dimensional array. Implement a function that calculates their average
 * value. Another function will display the elements from the initial array that
 * are greater than the computed average.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void read_array(int, int[]);
float avg_array(int, int[]);
void elem_gr_avg(int, int[], int);

int main() {
  int n;

  // read number of elements
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  // verify there's at least one element
  while (n < 1) {
    printf("There must be at least 1 element!\n");
    scanf("%d", &n);
  }

  int arr[n];
  read_array(n, arr);

  float avg = avg_array(n, arr);
  printf("\nThe average value of the array elements is %.1f\n", avg);

  printf("\nThe elements greater than the average are:\n");
  elem_gr_avg(n, arr, avg);
}

void read_array(int n, int arr[]) {
  // read elements of an array
  printf("Enter array elements:\n");
  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%d", &arr[i]);
  }
}

float avg_array(int n, int arr[]) {
  // compute average value of array
  float avg = 0;
  int k = 0;

  for (int i = 0; i < n; i++)
    avg += arr[i], k++;
  return avg / k;
}

void elem_gr_avg(int n, int arr[], int avg) {
  // print elements greater than avg
  for (int i = 0; i < n; i++)
    if (arr[i] > avg)
      printf("%d ", arr[i]);
}
