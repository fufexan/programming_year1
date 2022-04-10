/*
 * Fufezan Mihai, 2012, lab12, ex 12
 *
 * Define an enumeration called White_Light that will contain the basic colors
 * (red, orange, yellow, green, blue, indigo and violet). Initialize a few
 * variables of type White_Light and try to generate some secondary colors by
 * combining the basic colors mentioned above. Use an enumeration based
 * mechanism for translating the color names into French, English or German.
 * Display all the colors mentioning the original and the translated names and
 * the associated value.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

enum White_Light { red, orange, yellow, green, blue, indigo, violet };
enum White_Light_French {
  rouge = red,
  jaune = yellow,
  vert = green,
  bleu = blue,
  mauve = violet
};
enum White_Light_German {
  rot = red,
  gelb = yellow,
  grun = green,
  blau = blue,
  indigoblauindigo = indigo,
  lila = violet
};

int main() {
 enum White_Light x = red;
 enum White_Light y = indigo;
 enum White_Light z = green;

 printf("%s")
}
