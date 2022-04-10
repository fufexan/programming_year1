/*
 * Fufezan Mihai & Țepeș-Focșa Carina, e2012, practical test 1
 *
 * Write a C/C ++ application in which you read from the keyboard an n value (n
 * <= 10) and in a function then read n double values, which will be stored in a
 * one-dimensional array of double type. Display the elements of the array with
 * a function. Write another function, which will store in a one-dimensional
 * array of type int the values obtained by rounding the values in the first
 * array, up or down, as the case may be. Display the resulting array in the
 * main () function.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>

void print_elements(double[], int);
void to_int(double[], int[], int);

int main() {
  int n;
  double v[10];
  int iv[10];

  // read size of array and verify it's less than 10
  printf("Enter the size of the array (<10): ");
  scanf("%d", &n);
  while (n > 10) {
    printf("Wrong size. Enter again: ");
    scanf("%d", &n);
  }

  // read elements
  printf("Enter the array elements:\n");
  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%lf", &v[i]);
  }

  // print array
  print_elements(v, n);
  // convert array to rounded ints
  to_int(v, iv, n);

  // print int array
  printf("\nThe rounded int values are:\n");
  for (int i = 0; i < n; i++)
    printf("%d ", iv[i]);
}

void print_elements(double v[], int n) {
  // print an array's elements
  printf("The array's elements are:\n");
  for (int i = 0; i < n; i++)
    printf("%.2lf ", v[i]);
}

void to_int(double v[], int iv[], int n) {
  // convert doubles to ints by rounding
  for (int i = 0; i < n; i++)
    iv[i] = round(v[i]);
}
