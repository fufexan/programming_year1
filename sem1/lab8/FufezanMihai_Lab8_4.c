/*
 * Fufezan Mihai, 2012, lab08, ex 4
 *
 * Write a C/C++ application that defines a password (as a string of
 * characters). The program reads repeatedly the entries from the keyboard until
 * the user enters the right password. Display the number of trials the user
 * entered wrong passwords.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
  char pwd[] = "verystrong";
  char try[20];
  int tries = 0;

  printf("Guess the password: ");
  do {
    gets(try);

    if (strcmp(pwd, try))
      printf("Wrong password. Retry: "), tries++;
  } while (strcmp(pwd, try));

  printf("You guessed after %d tries.\n", tries);
}
