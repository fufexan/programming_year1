/*
 * Fufezan Mihai, 2012, lab12, ex 11
 *
 * Write a C/C++ application that defines a union called group that contains various
 * fields (int, log, double, char, etc.). Read from the keyboard the data associated to a
 * group variable. Is it possible to display all the fields in the union using pointers or
 * fully qualified field-names? Display the accessible information and the dimension of
 * the union variable. Perform the same operations considering a regular structure
 * instead of the union.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

union Group {
  int a;
  long b;
  double c;
  char d;
};

struct group {
  int a;
  long b;
  double c;
  char d;
};

int main() {
  // union
  union Group x;
  
  printf("For a union:\n");
  
  printf("Enter an integer: ");
  scanf("%d", &x.a);

  printf("Enter a long number: ");
  scanf("%ld", &x.b);

  printf("Enter a double: ");
  scanf("%lf", &x.c);

  getchar();
  printf("Enter a character: ");
  scanf("%c", &x.d);
  
  printf("\nint: %d", x.a);
  printf("\nlong: %ld", x.b);
  printf("\ndouble: %lf", x.c);
  printf("\nchar: %c", x.d);
  printf("\nWe can't use all the fields simultaneously in a union.\n");
  
  // struct
  struct group y;
  printf("\nFor a struct:\n");
  
  printf("Enter an integer: ");
  scanf("%d", &y.a);

  printf("Enter a long number: ");
  scanf("%ld", &y.b);

  printf("Enter a double: ");
  scanf("%lf", &y.c);

  getchar();
  printf("Enter a character: ");
  scanf("%c", &y.d);
  
  printf("\nint: %d", y.a);
  printf("\nlong: %ld", y.b);
  printf("\ndouble: %lf", y.c);
  printf("\nchar: %c", y.d);
  printf("\nWe can use all the fields simultaneously in a struct.\n");
}
