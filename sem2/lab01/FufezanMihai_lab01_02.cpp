/*
 * Fufezan Mihai, 2012, lab01, ex 02
 *
 * Define an inline function min() that determines and display the minimum
 * among 2 and other among 3 numbers introduced from the KB. Consider
 * overloading functions.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

inline int min(int a, int b);
inline int min(int a, int b, int c);

int main() {
  int a, b, c;

  printf("Enter 3 integer numbers: ");
  scanf("%d%d%d", &a, &b, &c);

  printf("\nThe smallest of the first two numbers is: %d\n", min(a, b));
  printf("The smallest of the three numbers is: %d\n", min(a, b, c));
}

inline int min(int a, int b) {
  if (b < a)
    a = b;
  return a;
}
inline int min(int a, int b, int c) {
  if (b < a)
    a = b;
  if (c < a)
    a = c;
  return a;
}
