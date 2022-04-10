/*
 * Fufezan Mihai, 2012, lab11, ex 05
 *
 * Declare a global float pointer. In function main(), read an integer value N
 * that represents the dimension of an array of float numbers. Allocate the
 * necessary ammount of memory for storing the array and than read it’s elements
 * from the keyboard. Determine the average value of those N elements and
 * calculate Mn=(sum(pow((xi-xmed),n))/N, where n=1,2,3. Display the results and
 * then free the allocated memory. Use the functions malloc() and free(). In
 * another function, generate the numbers in the array using a library function
 * that generates random numbers and determine the same values. Use new and
 * delete operators.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float *p;
void read(float *, int);
float average(float *, int);
void generate(float *, int);
void compute(float *, int);

int main() {
  srand(time(0));
  int N;

  printf("Enter the size of an array: ");
  scanf("%d", &N);

  // 1: array from input
  float *a = (float *)malloc(sizeof(float) * N);

  puts("\nEnter the array elements (real numbers):");
  read(a, N);
  printf("\nFormula for array read from keyboard:\n");
  compute(a, N);
  free(a);

  // 2: array generated
  float *b = new float[N];
  generate(b, N);
  printf("\nFormula for generated array:\n");
  for (int i = 0; i < N; i++)
    printf("%.1f ", b[i]);
  printf("\n\n");
  compute(b, N);
  delete[] b;
}

void read(float *a, int n) {
  // read an array

  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%f", a + i);
  }
}

float average(float *a, int n) {
  // compute the average value of an array

  float avg = 0;

  for (int i = 0; i < n; i++)
    avg += a[i];

  return avg / n;
}

void generate(float *a, int n) {
  // generate an array of floats

  for (int i = 0; i < n; i++)
    a[i] = (rand() % 10 * 0.1) + rand() % 100;
}

void compute(float *a, int n) {
  // compute the formula described
  float avg = average(a, n), sum = 0;
  float M[3];

  printf("\navg is %.1f\n", avg);

  for (int j = 0; j < n; j++)
    sum += a[j] - avg;

  printf("\nsum = %f\n", sum);

  for (int i = 0; i < 3; i++) {
    M[i] += pow(sum, i + 1) / n;
    printf("M[%d] = %.1f\n", i, M[i]);
  }
}