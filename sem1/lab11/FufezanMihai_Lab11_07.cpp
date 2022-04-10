/*
 * Fufezan Mihai, 2012, lab11, ex 07
 *
 * Write a C/C++ application that allocates the necessary amount of memory for
 * storing 10,000 integer numbers. The program automatically initializes the
 * numbers with random values between 1 and 100 (use the library functions
 * srand() and/or rand() in VC++). Write a function that displays the most 10
 * frequently numbers and the number of their appearances in the initial array.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void top10(int *, int);
int compare(void const *, void const *);

typedef struct {
  int i;
  int v;
} Pair;

int main() {
  srand(time(0));

  // alloc
  int *v = (int *)malloc(sizeof(int) * 10000);

  // generate
  for (int i = 0; i < 10000; i++)
    v[i] = rand() % 101;

  // display the top 10 numbers
  top10(v, 10000);

  // dealloc
  free(v);
}

void top10(int *v, int n) {
  // get top 10 most common elements and print them

  Pair x[101]{};

  // compute how many times each number appears
  for (int i = 0; i < n; i++) {
    x[v[i]].v++;
    x[v[i]].i = v[i];
  }

  // sort array
  qsort(x, 101, sizeof(Pair), compare);

  // print the first 10 numbers
  puts("From the generated array,");
  for (int i = 0; i < 10; i++)
    printf("%3d appeared %3d times\n", x[i].i, x[i].v);
}

int compare(void const *a, void const *b) {
  // function used by qsort

  return (*(Pair *)b).v - (*(Pair *)a).v;
}
