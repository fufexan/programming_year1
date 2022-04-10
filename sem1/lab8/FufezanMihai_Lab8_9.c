/*
 * Fufezan Mihai, 2012, lab08, ex 9
 *
 * Write a program that reads from the keyboard n integer values into a
 * one-dimensional array. Display the number of negative odd elements and their
 * values.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>

void read_arr(int, int[]);
void print_negodd(int, int[]);

int main() {
  int n;
  bool has_negodd = false;

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

  // check if there's any negative number
  for (int i = 0; i < n && !has_negodd; i++)
    if (arr[i] < 0 && arr[i] % 2)
      has_negodd = true;

  // print negative and odd elements
  printf("\n");
  if (has_negodd)
    print_negodd(n, arr);
  else
    printf("There are no negative odd numbers in the array!");
}

void read_arr(int n, int arr[]) {
  // read array's elements
  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%d", &arr[i]);
  }
}

void print_negodd(int n, int arr[]) {
  // print negative odd numbers
  printf("The negative odd elements are:\n");

  for (int i = 0; i < n; i++)
    if (arr[i] < 0 && arr[i] % 2)
      printf("[%d] = %d\n", i, arr[i]);
}
