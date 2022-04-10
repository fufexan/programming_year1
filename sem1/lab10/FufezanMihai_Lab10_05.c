/*
 * Fufezan Mihai, 2012, lab10, ex 5
 *
 * Define  an  array  of  character  pointers.  Each  location  will  store  one
 * of  the  following messages: L10 – pointeri2 10
 * - "value too small"
 * - "value too big"
 * - "correct value"
 * The  application  generates  a  random  number  between  0  and  100  and
 * then reads repeatedly the keyboard until the user enters the right number.
 * Use the previously defines messages  for informing the  client about  the
 * relation between  the  auto-generated  number and the last value entered from
 * the keyboard.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  char **msgs = malloc(sizeof(char *) * 3);
  *(msgs) = "value too small";
  *(msgs + 1) = "value too big";
  *(msgs + 2) = "correct value";

  int x;
  int gen = rand() % 101;

  printf("Guess the number: ");
  do {
    scanf("%d", &x);
    if (x > gen)
      printf("%s. retry: ", *(msgs + 1));
    else if (x < gen)
      printf("%s. retry: ", *(msgs));
    else
      printf("%s ", *(msgs + 2));
  } while (x != gen);

  for (int i = 0; i < 3; i++)
    free(msgs + i);
  free(*msgs);
}
