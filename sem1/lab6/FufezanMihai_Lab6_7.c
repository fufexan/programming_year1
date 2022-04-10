/*
 * Fufezan Mihai, 2012, lab07, ex 7
 *
 * Read 2 float numbers from the keyboard. Calculate and display the
 * results obtained by applying the main arithmetic operations (+, -, *, /)
 * upon them. Cast the results into integer values, whithout using any specific
 * rounding functions. Display the minimum input value using the conditional
 * operator. 
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int round_f(float);

int main() {
  float a, b;
  
  printf("Enter 2 real numbers: ");
  scanf("%f%f", &a, &b);

  // print the rounded values
  printf("The sum is %d\n", round_f(a + b));
  printf("The difference is %d\n", round_f(a - b));
  printf("The product is %d\n", round_f(a * b));
  printf("The quotient is %d\n", round_f(a / b));
  
  // display minimum input value
  float minimum;
  if(a > b)
    minimum = b;
  else if (b > a)
    minimum = a;
  else {
    printf("The input values are equal.");
    return 0;
  }

  printf("The minimum value is %f", minimum);
}

int round_f(float x) {
  int y = (int) x;

  if (x - y >= 0.5) y++;
  else if (x - y <= -0.5) y--;

  return y;
}
