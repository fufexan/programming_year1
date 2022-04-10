/*
 * Fufezan Mihai, 2012, lab08, ex 3
 *
 * Write a C/C++ application that reads from the keyboard an array of 10 integer
 * values. Define and implement a function that receives the array as parameter
 * and then displays its elements, ordered increasingly.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_sorted(int[], int);
void bubble(int[], int);

int main() {
  int n = 10, v[n];
  printf("Enter 10 integer values:\n");

  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%d", &v[i]);
  }

  print_sorted(v, n);
}

void bubble(int v[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (v[j] > v[j + 1]) {
        v[j] = v[j] ^ v[j + 1];
        v[j + 1] = v[j] ^ v[j + 1];
        v[j] = v[j + 1] ^ v[j];
        j--;
      }
    }
  }
}

void print_sorted(int v[], int n) {
  bubble(v, n);

  for (int i = 0; i < n; i++)
    printf("%d ", v[i]);
}
