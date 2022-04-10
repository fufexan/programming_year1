/*
 * Fufezan Mihai, 2012, lab08, ex 11
 *
 * Read from the keyboard an array of characters. Define the function that
 * reverses the array and populates another array with the elements from the
 * even positions of the reverted array. Display the results.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void rev(char[]);
void rev_and_populate(char[], char[]);

int main() {
  char str[100] = {'\0'}, gen[100] = {'\0'};

  // read string
  printf("Enter a string: ");
  scanf("%s", &str);

  // reverse string
  rev_and_populate(str, gen);

  // print resulting strings
  printf("The reversed string is %s\n", str);
  printf("The generated string is %s\n", gen);
}

void rev(char str[]) {
  // reverse string
  int i = strlen(str) - 1, j = 0;

  char tmp;
  while (i > j) {
    tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
    i--, j++;
  }
}

void rev_and_populate(char str[], char gen[]) {
  // reverse an array and build another one with the reversed array's elements
  // from even positions
  rev(str);

  int k = 0;
  for(int i = 0; i < strlen(str); i+=2)
    gen[k++] = str[i];
}
