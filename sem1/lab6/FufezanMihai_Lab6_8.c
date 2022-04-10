/*
 * Fufezan Mihai, 2012, lab06, ex 8
 *
 * Read from the keyboard several lowercase characters. Transform them
 * into uppercase letters using:
 * - an arithmetic operation;
 * - a logical operation, combined with a specific mask;
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>

int main() {
  char str[256];
  fgets(str, 256, stdin);

  bool ok = true;
  // turn every lowercase char into an uppercase one
  // search for '\n' entered by fgets and replace it with null;
  for (int i = 0; i < 256; i++) {
    if (str[i] == '\n') {
      str[i] = '\0';
      continue;
    } else if (str[i] != ' ')
      //str[i] -= 32;
      str[i] ^= 1 << 5;
  }

  printf("%s", str);
}
