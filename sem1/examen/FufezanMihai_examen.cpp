/*
 * Fufezan Mihai, 2012, sem. 1 exam
 *
 * Define a structure named Ball that contains the following fields
 * - a one dimensional array of maximum 30 characters for the name
 * - a one dimensional array of maximum 30 characters for the color
 * - a double value for the diameter, diameter
 * The program allocates dynamically the necessary amount of memory for storing
 * n (validated superior to be <100 and inferior depending on the problem
 * context) balls, n being read from the keyboard, then reads and displays the
 * balls’ data (specific functions will be used for each object (structure
 * variable)). The program sorts the balls in descending order considering the
 * name and color, then ascending based on diameter. The results are displayed.
 * The balls ordered by the imposed criterion are stored in a binary file having
 * the name read from the keyboard. Read from the file and display the data
 * corresponding to the first dim_n=3 (implicit) balls.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ball {
  char name[30];
  char color[30];
  double diameter;
};

Ball read_ball();
void print_ball(Ball);
int cmp_d(void const *, void const *);
int cmp_nc(void const *, void const *);

int main() {
  int n = 3;
  char c = '\n';

  // ask user whether to add more elements
  printf("The default number of elements is 3. Enter more? Y/n ");
  scanf("%c", &c);
  if (c == 'Y' || c == 'y' || c == '\n') {
    // read number of elements
    printf("Enter the number of balls you want to store: ");
    scanf("%d", &n);

    // validate
    while (n < 3 || n > 99) {
      printf("Value too %s! Reenter: ",
             n < 3 ? "high (over 99)" : "low (under 3)");
      scanf("%d", &n);
    }
  }

  // allocate ball array
  Ball *arr = (Ball *)malloc(sizeof(Ball) * n);

  // read balls
  for (int i = 0; i < n; i++) {
    printf("\nBall #%d\n\n", i);
    arr[i] = read_ball();
  }

  // sort array
  qsort(arr, n, sizeof(Ball), cmp_nc);
  qsort(arr, n, sizeof(Ball), cmp_d);

  // print balls
  printf("\nThe sorted balls are:");
  for (int i = 0; i < n; i++) {
    printf("\nBall #%d\n\n", i);
    print_ball(arr[i]);
  }

  // open file and print sorted array
  FILE *fp = fopen("FufezanMihai_exam.bin", "wb");
  fwrite(arr, n, sizeof(Ball), fp);

  // dealloc and close file
  fclose(fp);
  free(arr);
}

// read ball attributes
Ball read_ball() {
  Ball x;

  getchar();
  printf("Name: ");
  scanf("%[^\n]s", x.name);

  getchar();
  printf("Color: ");
  scanf("%[^\n]s", x.color);

  printf("Diameter: ");
  scanf("%lf", &x.diameter);

  return x;
}

// print ball attributes
void print_ball(Ball x) {
  printf("Name: %s\n", x.name);
  printf("Color: %s\n", x.color);
  printf("Diameter: %lf\n", x.diameter);
}

// sort array by name and color
int cmp_nc(void const *b, void const *a) {
  char *x = ((Ball *)a)->name;
  char *y = ((Ball *)b)->name;

  // sort by name
  if (strcmp(x, y))
    return strcmp(x, y);
  // sort by color
  else {
    char *x = ((Ball *)a)->color;
    char *y = ((Ball *)b)->color;

    return strcmp(x, y);
  }
}

// sort array by diameter
int cmp_d(void const *a, void const *b) {
  return (*(Ball *)a).diameter - (*(Ball *)b).diameter;
}
