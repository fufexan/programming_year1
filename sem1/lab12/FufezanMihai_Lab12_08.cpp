/*
 * Fufezan Mihai, 2012, lab12, ex 08
 *
 * Declare a structure named A_structure that contains as fields one integer-
 * and one character-type variable and an array of 256 characters. Define in the
 * main function a variable of type A_structure and initialize its fields with
 * data read from the keyboard. Declare a pointer, named pa_structure and
 * initialize-it by allocating memory for a single variable of type A_structure.
 * Use this pointer define all the fields of your variable with data read from
 * the keyboard. Display all the fields of the structure, then free up the
 * allocated memory.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int num;
  char character;
  char str[256];
} A_structure;

void read_struct(A_structure *);
void print_struct(A_structure);

int main() {
  A_structure x;
  A_structure *pa_structure = (A_structure *)malloc(sizeof(A_structure));

  // read data
  printf("Enter the fields of the variable:\n");
  read_struct(&x);

  printf("\nEnter the fields of the pointer:\n");
  read_struct(pa_structure);

  // print data
  printf("\nThe variable's contents are:\n");
  print_struct(x);

  printf("\nThe pointer's contents are:\n");
  print_struct(*pa_structure);

  // dealloc
  free(pa_structure);
}

void read_struct(A_structure *x) {
  // read the fields of A_structure

  printf("Enter an integer: ");
  scanf("%d", &x->num);
  getchar();
  printf("Enter a character: ");
  scanf("%c", &x->character);
  getchar();
  printf("Enter a string: ");
  fgets(x->str, 256, stdin);
}

void print_struct(A_structure x) {
  // print the fields of A_structure

  printf("The integer is: %d\n", x.num);
  printf("The character is: %c\n", x.character);
  printf("The string is: %s", x.str);
}
