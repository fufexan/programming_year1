/*
 * Fufezan Mihai, 2012, lab05, ex 9
 *
 * Two cars move towards each other, having the speeds v1 and v2 and
 * starting from two cities 100km apart. The speeds' values are read from
 * the keyboard. Display how many minutes will pass until the two cars meet
 * in the same point.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  float v1, v2;

  printf("The first car's speed is: ");
  scanf("%f", &v1);
  printf("The second car's speed is: ");
  scanf("%f", &v2);

  printf("The time it takes for the cars to meet is %.0f minutes",
         100 / (v1 + v2) * 60);
}
