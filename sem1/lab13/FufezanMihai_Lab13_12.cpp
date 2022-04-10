/*
 * Fufezan Mihai, 2012, lab13, ex 12
 *
 * Write a C/C++ program that reads from the comand line two file names. The
 * program should ask the user to introduce eight integer values fom the KBD,
 * saving them into the first file, in binary mode. Read back these values from
 * the file, and determine the arithmetical media of the values greather than 4.
 * Write the result into the second file in text mode, using the following
 * format: “The average value of ... is ...”. The first space needs to be
 * replaced with the values used for calculating the average, the second with
 * the average value itself, using a two digits precision.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  char filename1[20], filename2[20];
  int x;

  // get filenames
  printf("Enter a filename: ");
  scanf("%[^\n]s", filename1);
  getchar();
  FILE *fp1 = fopen(filename1, "wb");
  printf("Enter another filename: ");
  scanf("%[^\n]s", filename2);
  getchar();

  // scan and store values
  printf("\nEnter 8 integer values:\n");
  int n = 8;
  for (int i = 0; i < n; i++) {
    printf("[%d] = ", i);
    scanf("%d", &x);
    fwrite(&x, sizeof(int), 1, fp1);
  }

  // read back values and compute average
  int count = 0;
  float sum = 0;

  fp1 = freopen(filename1, "rb", fp1);
  FILE *fp2 = fopen(filename2, "wb");
  fprintf(fp2, "The average value of ");

  for (int i = 0; i < n; i++) {
    fread(&x, sizeof(int), 1, fp1);
    if (x > 4) {
      sum += x;
      count++;
      fprintf(fp2, "%d ", x);
    }
  }

  fprintf(fp2, "is %.2f", sum / count);

  fclose(fp1);
  fclose(fp2);
}
