/*
 * Fufezan Mihai, 2012, lab12, ex 10
 *
 * Define a structure named Car that contains the following variables: producer,
 * production_year, cylinder_volume and colour. Store in a newly allocated zone
 * of memory the data for n cars. Display the records for the red cars produced
 * after 2010.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char producer[20], colour[30];
  int production_year;
  float cylinder_volume;
} Car;

Car read_car();
void print_car(Car);

int main() {
  int n;

  printf("How many cars do you want to input? ");
  scanf("%d", &n);

  Car *arr = (Car *)malloc(sizeof(Car) * n);

  // read cars
  for (int i = 0; i < n; i++) {
    printf("\nCar #%d\n", i);
    arr[i] = read_car();
  }

  // print cars
  printf("\nThe red cars produced after 2010 are:\n");
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (!strcmp(arr[i].colour, "red") && !strcmp(arr[i].colour, "Red") &&
        !strcmp(arr[i].colour, "RED") && arr[i].production_year > 2010) {
      printf("\nCar #%d\n", k++);
      print_car(arr[i]);
    }
  }

  free(arr);
}

Car read_car() {
  // read a car

  Car x;
  getchar();
  printf("Producer: ");
  scanf("%[^\n]s", x.producer);

  printf("Production year: ");
  scanf("%d", &x.production_year);

  printf("Cylinder volume: ");
  scanf("%f", &x.cylinder_volume);

  getchar();
  printf("Colour: ");
  scanf("%[^\n]s", x.colour);

  return x;
}

void print_car(Car x) {
  // print car info

  printf("Producer: %s\n", x.producer);

  printf("Production year: %d\n", x.production_year);

  printf("Cylinder volume: %.2f\n", x.cylinder_volume);

  printf("Colour: %s\n", x.colour);
}
