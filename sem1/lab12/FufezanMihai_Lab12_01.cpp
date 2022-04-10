/*
 * Fufezan Mihai, 2012, lab12, ex 01
 *
 * Develop a C/C++ application considering an adequate data structure named
 * Student having the fields: name, surname, country, group and birth_year.
 * Count all the non-Romanian students from the group (MAX students in the
 * group). The effective fields will be introduced from the keyboard generating
 * an array of structures. A name AAA (upper or lower case) will finish the
 * introduction process.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[21], surname[21], country[21];
  int group, birth_year;
} Student;

int main() {
  bool stop = false;
  int k = -1;
  Student *v = nullptr;

  // read students
  printf("Enter students. To stop, enter `aaa` as the name.");
  do {
    k++;
    v = (Student *)realloc(v, sizeof(Student) * (k + 1));

    printf("\nStudent %d:\n", k);
    printf("Name: ");
    fgets(v[k].name, 20, stdin);
    // if name is either aaa or AAA break out of the loop
    if (strstr(v[k].name, "AAA") != NULL || strstr(v[k].name, "aaa") != NULL)
      break;

    printf("Surname: ");
    fgets(v[k].surname, 20, stdin);

    printf("Country: ");
    fgets(v[k].country, 20, stdin);

    printf("Group: ");
    scanf("%d", &v[k].group);

    printf("Birth year: ");
    scanf("%d", &v[k].birth_year);
    getchar();
  } while (true);

  // print students
  if (k <= 0)
    printf("\nThere are no students!\n");
  else {
    int ro = 0;

    for (int i = 0; i < k; i++) {
      char *c = v[i].country;
      // remove \n from string
      v[i].country[strlen(v[i].country) - 1] = '\0';
      if (!strcmp(c, "ro") || !strcmp(c, "RO") || !strcmp(c, "Ro") ||
          !strcmp(c, "romania") || !strcmp(c, "Romania") ||
          !strcmp(c, "ROMANIA"))
        ro++;
    }

    // print number of non-romanian students
    printf("\nThere are %d non-romanian students.\n", k - ro);
  }

  // dealloc
  free(v);
}
