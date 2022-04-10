/*
 * Fufezan Mihai, 2012, lab05, ex 8
 *
 * Read from the keyboard a train’s exact departure time from Cluj (hour and
 * minutes) and arrival time in Brasov. Calculate and display the travelling time,
 * represented in hours and minutes.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  int hc, hb, mc, mb, h, m;

  printf("Enter the departure time of a train from Cluj (hours and minutes): ");
  scanf("%d%d", &hc, &mc);
  printf("Enter the arrival time of a train in Brasov (hours and minutes): ");
  scanf("%d%d", &hb, &mb);

  if (hb >= hc) {
    h = hb - hc;

    if (mc > mb) {
      m = 60 - mc + mb;
      h--;
    } else {
      m = mb - mc;
    }
  } else {
    h = 24 - hc + hb;

    if (mc > mb) {
      m = 60 - mc + mb;
      h--;
    } else {
      m = mb - mc;
    }
  }

  printf("The journey's duration is ");
  if (h)
    printf("%d hour", h);
  if (h > 1)
    printf("s");
  if (m && h)
    printf(" and ");
  if (m)
    printf("%d minute", m);
  if (m > 1)
    printf("s");
  printf(".");
}
