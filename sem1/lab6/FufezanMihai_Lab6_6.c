/*
 * Fufezan Mihai, 2012, labXX, ex Y
 *
 * Read an integer value from the standard input. Write, in decimal format,
 * the value of each byte of the value.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void byte(int x, int pos);
void to_binary(unsigned int x, int size);

int main() {
  int x;

  printf("Enter an integer value: ");
  scanf("%d", &x);

  to_binary(x, 32);
  printf("\n");

  for (int i = 0; i < 4; i++)
    byte(x, i);
}

void byte(int x, int pos) {
  x >>= pos * 8;
  int mask = (1 << 7) - 1;

  printf("Byte %d is %d\n", pos + 1, mask & x);
  to_binary(x, 7);
  printf("\n");
}

void to_binary(unsigned int x, int size) {
  // prints the *size* bits of x in little-endian order
  // uses recursion, thus avoids arrays
  int a = 0;

  if (x) {
    // get last bit of x
    a = x & 1;
    // get next bit, so on
    if (size)
      to_binary(x >> 1, size - 1);
  } else {
    // if there are no more positive bits in the number, print the remaining
    // amount of zeroes from the binary representation, given by size

    // we decrement this since the last printf shows a 0 as well for the last
    // recursion
    size--;
    while (size--)
      printf("0");
  }

  // prints the current bit
  printf("%d", a);
}
