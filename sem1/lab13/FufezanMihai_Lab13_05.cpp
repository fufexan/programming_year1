/*
 * Fufezan Mihai, 2012, lab13, ex 05
 *
 * Develop a C/C++ application that will display (line by line) the content of a
 * previously created text file then one created by program.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void generate_file(FILE*);

int main() {
  FILE *fp = nullptr;
  char buf[1024];
  fp = fopen("05.txt", "r");
  
  while(fgets(buf, 1024, fp) != NULL)
    printf("%s", buf);
  
  fclose(fp);
}
