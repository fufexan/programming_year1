/*
 * Fufezan Mihai, 2012, lab10, ex 6
 *
 * Write a C/C++ application that defines an array of pointers to character
 * strings and initialize them with different messages. Display the messages.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
  // define 
  char *msgs[3];
  msgs[0] = "message number 1 at position 0";
  msgs[1] = "yet another message at position 1";
  msgs[2] = "third and final message. goodb ye";

  // print
  for(int i = 0; i < 3; i++)
    puts(*(msgs + i));
}
