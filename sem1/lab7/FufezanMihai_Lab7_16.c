/*
 * Fufezan Mihai, 2012, lab07, ex 16
 *
 * Write a C/C++ application that reads from the keyboard a series of integer
 * numbers, until the user presses on the <Esc>-key. Determine and display the
 * average value of the odd positive numbers.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>

int main() {
  int no = 0, x, c;
  float avg = 0;

  do {
    printf("\nEnter an integer number: ");
    scanf("%d", &x);

    printf("Press any key to continue, ESC to stop");
    c = _getch();

    if (x % 2)
      avg += x, no++;
  } while (c != 27);

  printf("\n\nThe average value of the odd numbers is %.2f", avg / no);
}
