/*
 * Fufezan Mihai, 2012, lab06, ex 4
 *
 * Write a program that monitors a communications channel on 16/32/64
 * bits. In order to do that, read from the keyboard an unsigned int value
 * a, that will be displayed in decimal, binary, octal and hexadecimal counting
 * bases. Use a function for converting the number from base 10 in base 2.
 * Implement another function called getsets() that receives 3 parameters:
 * - x: the value read from the keyboard
 * - p: the position of a bit of those 16/32 or 64 bits (counting from the
 * right).
 * - n: the number of bits that will be extracted from the array.
 *
 * The function returns, adjusted to the right, those n bits from the value x,
 * starting with the position p, where p<8*sizeof(x) and p>n. Display the result
 * in binary, octal and hexadecimal
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void to_binary(unsigned int x, int size);
int getsets(unsigned int x, int p, int n);

int main() {
  unsigned int a, p, n;
  int maxsize = sizeof(a) * 8 - 1;

  // input part
  printf("Enter a natural number: ");
  scanf("%d", &a);
  printf("Enter the position of a bit (max %d): ", maxsize);
  scanf("%d", &p);
  printf("Enter the number of bits to be extracted (max %d): ", maxsize - p);
  scanf("%d", &n);

  // handle errors
  if (p > maxsize) { printf("The position has to be at most %i!\n", maxsize); return 1; }
  if (p + n > maxsize) { printf("Can't read outside of value!"); return 1; }

  // compute selected bits
  int result = getsets(a, p, n);

  // output for original number
  printf("\nThe value in decimal is: %d\n", a);
  printf("The value in binary is: ");
  to_binary(a, sizeof(a)*8);
  printf("\nThe value in octal is: %o\n", a);
  printf("The value in hexadecimal is: %x\n", a);

  // output for selected number
  printf("\nThe selected value in decimal is: %d\n", result);
  printf("The selected value in binary is: ");
  to_binary(result, n);
  printf("\nThe selected value in octal is: %o\n", result);
  printf("The selected value in hexadecimal is: %x\n", result);
}

int getsets(unsigned int x, int p, int n) {
  // returns the selected bits from a number as a separate number

  /* old code
  int res = 0, pos = 0;

  for (int i = p + n; p < i; p++, pos++) {
    if(x & (1 << (p - 1)))
      res |= 1 << pos;
  }

  return res;
  */

  // simpler implementation
  // makes a mask of n bits
  unsigned int mask = (1 << n) - 1;  
  // extracts bits from the p position
  unsigned int bits = x >> p;
  // returns the wanted value
  return mask & bits;
}

void to_binary(unsigned int x, int size) {
  // prints the *size* bits of x in little-endian order
  // uses recursion, thus avoids arrays
  int a = 0;

  if (x) {
    // get last bit of x
    a = x & 1;
    // get next bit, so on
    if(size) to_binary(x >> 1, size - 1);
  } else {
    // if there are no more positive bits in the number, print the remaining
    // amount of zeroes from the binary representation, given by size

    // we decrement this since the last printf shows a 0 as well for the last
    // recursion
    size--;
    while(size--) printf("0");
  }

  // prints the current bit
  printf("%d", a);
}
