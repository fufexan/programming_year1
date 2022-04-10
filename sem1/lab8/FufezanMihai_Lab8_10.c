/*
 * Fufezan Mihai, 2012, lab08, ex 10
 *
 * Write a program that reads the integer elements of a one-dimensional array.
 * Implement a function that builds another array containing the remainders
 * obtained by dividing the values in the initial array to the number of the
 * positive elements.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void read_arr(int, int[]);
void print_arr(int, int[]);
int positive_arr(int, int[]);

int main() {
  int n;

  // read size of dynamic array
  printf("Enter the number of elements in an array: ");
  scanf("%d", &n);
  while (n < 1) {
    printf("There must be at least 1 element! Retry: ");
    scanf("%d", &n);
  }

  // define and read array
  int arr[n];
  read_arr(n, arr);

  // get number of positive elements
  int pos = positive_arr(n, arr);

  // build second array
  int arr2[n];
  for(int i = 0; i < n; i++)
    arr2[i] = arr[i] % pos;

  // display second array
  printf("\nThe generated array is:\n");
  print_arr(n, arr2);
}

int positive_arr(int n, int arr[]) {
  // returns number of positive elements
  int x = 0;
  for (int i = 0; i < n; i++)
    if(arr[i] > 0) x++;

  return x;
}

void read_arr(int n, int arr[]) {
  // read array's elements
  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%d", &arr[i]);
  }
}

void print_arr(int n, int arr[]) {
  // print array
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
}
