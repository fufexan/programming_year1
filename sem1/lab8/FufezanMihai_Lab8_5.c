/*
 * Fufezan Mihai, 2012, lab08, ex 5
 *
 * Write a C/C++ application that that reads from the keyboard two arrays of
 * characters representing the name and surname of a person. Display them with
 * capital letters, separated by a <Tab> space.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>

int main() {
  char name[50], surname[50];
  bool n = true, sn = true;

  printf("Enter your last name: ");
  gets(name);
  printf("Enter your surname: ");
  gets(surname);

  // convert to uppercase
  for (int i = 0; i < 50; i++) {
    if (name[i] == '\0')
      n = false;
    else if (!n)
      name[i] -= 32;

    if (surname[i] == '\0')
      sn = false;
    else if (!sn)
      surname[i] -= 32;
  }

  printf("%s\t\t%s", name, surname);
}
