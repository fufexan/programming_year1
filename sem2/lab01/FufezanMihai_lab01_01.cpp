/*
 * Fufezan Mihai, 2012, lab01, ex 01
 *
 * Define a macro function MAX that determines and display the maximum among 2
 * and other among 3 numbers introduced from the KB. Use different options
 * (conditional operator, if statement, respectively).
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_2(a, b) { \
  if (b > a) a = b; \
}

#define MAX_3(a, b, c) { \
  if (b > a) a = b; \
  if (c > a) a = c; \
}

int main() {
  int a, b, c, x, y, z;
  
  printf("Enter 3 integers: ");
  scanf("%d%d%d", &a, &b, &c);
  
  x = a, y = b, z = c;
  MAX_2(a, b);
  printf("\nThe maximum between the first two numbers is %d", a);
  MAX_3(x, y, z);
  printf("\nThe maximum between the three numbers is %d", x);
  
  return 0;
}
