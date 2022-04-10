/*
 * Fufezan Mihai, 2012, lab11, ex 12
 *
 * Write a C/C ++ application that reads from the keyboard an array of up to 10
 * integers in range 2, ..., 10. The actual size is entered from the keyboard,
 * the array being allocated dynamically. Define two functions that consider the
 * array as a parameter and return the minimum and maximum values in the array.
 * Define another function that returns the average value of the elements of the
 * entered array. Define another function, olympic_filter(...), which considers
 * the initial array, returning the address of a dynamically allocated array
 * without the first occurrence of the minimum and maximum value ordered in
 * increasing mode. In main() also display the initial array, the minimum and
 * maximum value, the average of the elements of the initial array, the elements
 * of the newly obtained array returned by the function olympic_filter(...) and
 * the average obtained after the olympic filter. Validate the data entry
 * according to the requirements of the problem (array size, elements entered
 * with resumption). The operations with the elements of the arrays will be done
 * using pointers.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

float arr_avg(int *, int);
int arr_max(int *, int);
int arr_min(int *, int);
int cmp(void const *, void const *);
int *olympic_filter(int *&, int &);
void print_arr(int *, int);
void read_num(int &);
void rm_elem(int *&, int &, int);

int main() {
  int n;

  // read size
  printf("Enter the size of an array (up to 10): ");
  read_num(n);

  // alloc and read array
  int *a = (int *)malloc(sizeof(int) * n);
  puts("\nEnter the elements of the array (up to 10):");
  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    read_num(*(a+i));
  }

  // print biggest, smallest, and average value of read array
  printf("\n\nIn the read array, the max value is %d, min value is %d and "
         "average value is %.1f.\n",
         arr_max(a, n), arr_min(a, n), arr_avg(a, n));
  print_arr(a, n);

  // reorder array
  olympic_filter(a, n);

  if(n > 0) {
    printf("\n\nIn the generated array, the max value is %d, min value is %d and "
           "average value is %.1f.\n",
           arr_max(a, n), arr_min(a, n), arr_avg(a, n));
    print_arr(a, n);
  } else {
    printf("\n\nThere are no elements left in the array.\n");
  }

  // dealloc
  free(a);
}

int arr_min(int *a, int n) {
  // return minimum value in array

  int m = a[0];
  for (int i = 0; i < n; i++)
    if (m > *(a + i))
      m = *(a + i);

  return m;
}

int arr_max(int *a, int n) {
  // return maximum value in array

  int m = *a;
  for (int i = 0; i < n; i++)
    if (m < *(a + i))
      m = *(a + i);

  return m;
}

float arr_avg(int *a, int n) {
  // return average value of array

  float s = 0;

  for (int i = 0; i < n; i++)
    s += *(a + i);

  return s / n;
}

int *olympic_filter(int *&a, int &n) {
  // remove first smallest/biggest element in array, and sort it

  int a_min = arr_min(a, n);
  int a_max = arr_max(a, n);

  // reorder elements
  qsort(a, n, sizeof(int), cmp);

  if (*a == a_min)
    rm_elem(a, n, 0);
  if (*(a+n-1) == a_max)
    rm_elem(a, n, n-1);

  return a;
}
int cmp(void const *a, void const *b) { return (*(int *)a - *(int *)b); }

void rm_elem(int *&a, int &n, int x) {
  // remove element at position x from array

  n--;
  for (int j = x; j < n; j++)
    *(a + j) = *(a + j + 1);
}

void print_arr(int *a, int n) {
  // print arr

  printf("The array elements are:\n");
  for (int i = 0; i < n; i++)
    printf("%d ", *(a + i));
}

void read_num(int &x) {
  // read and verify input

  scanf("%d", &x);
  while (x > 10) {
    printf("Too big! Retry: ");
    scanf("%d", &x);
  }
}
