/*
 * Fufezan Mihai, 2012, lab06, ex 3
 *
 * Write a program that reads an unsigned char value and displays the binary
 * values resulting after recursively applying the shift right and the %
 * operators.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// void to_binary(unsigned char);
void to_binary_recursive(unsigned char x);

int main() {
  unsigned char x;
  printf("Enter a character: ");
  scanf("%c", &x);

  to_binary_recursive(x);
}

/*
void to_binary(unsigned char x) {
  int i = 8;
  int y[8] = {};

  while (x) {
    y[--i] = x % 2;
    x /= 2;
  }

  for (int i = 0; i < 8; i++)
    printf("%d", y[i]);
}
*/

void to_binary_recursive(unsigned char x) {
  // prints an unsigned char's bits using recursion
  int a;

  if (x) {
    a = x % 2;
    to_binary_recursive(x >> 1);
  }

  printf("%d", a);
}
