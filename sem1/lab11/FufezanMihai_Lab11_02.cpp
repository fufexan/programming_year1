/*
 * Fufezan Mihai, 2012, lab11, ex 02
 *
 * Consider an application for managing a company’s distributed activity (5
 * different cities with 3 selling points in each one of them). Define a
 * function that declares an array of float pointers, each pointer being used
 * for referencing a heap zone of memory that stores 3 float values that
 * represent the total sales at the end of day. The program needs to process the
 * data using functions for:
 * - reading the data for all the selling points from all the cities;
 * - calculating and returning the total amount of sales in every city. The
 * values will be centralized in the main function and the average value will be
 * displayed.
 * - eliberating all the used memory
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

float *readcity(int, int);
void print(float *, int, int);

int main() {
  int cities = 5, sellpoints = 3;
  // alloc
  float **data = malloc(sizeof(float *) * cities);

  // read data
  printf("A company has selling points in 5 different cities. In each city "
         "there's\n"
         "3 selling points.\n\nEnter the number of sales in each of them.\n");
  for (int i = 0; i < cities; i++)
    data[i] = readcity(i, sellpoints);

  // display data
  puts("\nThe number of sales in each city was:");
  for (int i = 0; i < cities; i++)
    print(data[i], i, sellpoints);

  // dealloc
  for (int i = 0; i < cities; i++)
    free(data[i]);
  free(data);
}

float *readcity(int x, int sellpoints) {
  // read city data

  float *city = malloc(sizeof(float) * sellpoints);

  printf("\nCity %d\n", x + 1);
  for (int i = 0; i < sellpoints; i++) {
    printf("\tSellpoint %d's number of sales = ", i + 1);
    scanf("%f", city + i);
  }

  return city;
}

void print(float *data, int x, int sellpoints) {
  // print the number of sales in a city

  float s = 0;

  for (int i = 0; i < sellpoints; i++)
    s += data[i];

  printf("City %d had %.1f sales\n", x, s);
}
