/*
 * Fufezan Mihai, 2012, lab02, ex 05
 *
 * Read a string of caracters from the keyboard, one character at a time, using
 * a character function. Reverse the string using a recursive function.
 */

#include <iostream>

using namespace std;

void strrev(char *);

int main() {
  char str[51]{};
  char x;
  int k{};

  cout << "Enter a string: ";
  x = getchar();
  while (x != '\n') {
    str[k++] = x;
    x = getchar();
  }
 
  cout << "The reversed string is: ";
  strrev(str);
}

void strrev(char *str) {
  if(*str) {
    strrev(str+1);
    cout << *str;
  }
}
