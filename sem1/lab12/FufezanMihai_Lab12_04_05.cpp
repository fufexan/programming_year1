/*
 * Fufezan Mihai, 2012, lab12, ex 04-05
 *
 * Using included structures, Data_calend with fields day, month, year and
 * Personal_data with fields name, surname, occupation, code, department,
 * birth_date and empl_date of type Data_calend, generate an array of structures
 * of type Personal_data, containing couple of employees (max. 20), reading
 * their data from the keyboard. Considering "engineer", "teacher", "student"
 * and "manager" as possible values for the field occupation, display all
 * engineer’s records.
 *
 * Using the previous array of structures, generate a list of records being
 * sorted in ascending order by their code, and in descending order by the
 * empl_date.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int day, month, year;
} Data_calend;

typedef struct {
  char *name, *surname, *occupation, *department;
  int code;
  Data_calend birth_date, empl_date;
} Personal_data;

void read_employee(Personal_data *);
void print_employee(Personal_data);
int cmp_code(void const *, void const *);
int cmp_empl(void const *, void const *);

int main() {
  int k = 0;
  char confirm = 'Y';
  Personal_data *v = nullptr;

  printf("Enter the personal data for a few employees. Their occupation can be "
         "either engineer, teacher, student or manager.\n"
         "Dates are handled in ISO 8601 format.\n");
  do {
    v = (Personal_data *)realloc(v, sizeof(Personal_data) * (k + 1));

    // read employees
    printf("\nEmployee %d\n", k);
    read_employee(&v[k++]);

    // confirm adding a new employee
    printf("\nContinue? Y/n: ");
    scanf("%c", &confirm);
  } while (confirm == 'Y' || confirm == 'y' || confirm == '\n');

  // print employee info
  printf("\nThe employees are:\n");
  for (int i = 0; i < k; i++) {
    printf("\nEmployee %d\n", i);
    print_employee(v[i]);
  }

  // sort asc by code
  qsort(v, k, sizeof(Personal_data), cmp_code);
  printf(
      "\nThe employees sorted in ascending order based on their codes are:\n");
  for (int i = 0; i < k; i++) {
    printf("\nEmployee %d\n", i);
    print_employee(v[i]);
  }

  // sort desc by Empl_date
  qsort(v, k, sizeof(Personal_data), cmp_empl);
  printf("\nThe employees sorted in descending order based on their employment "
         "date are:\n");
  for (int i = 0; i < k; i++) {
    printf("\nEmployee %d\n", i);
    print_employee(v[i]);
  }

  // dealloc
  for (int i = 0; i < k; i++) {
    free(v[i].name);
    free(v[i].surname);
    free(v[i].occupation);
    free(v[i].department);
  }
  free(v);
}

void read_employee(Personal_data *x) {
  // read data about an employee

  x->name = (char *)malloc(sizeof(char) * 20);
  x->surname = (char *)malloc(sizeof(char) * 20);
  x->occupation = (char *)malloc(sizeof(char) * 20);
  x->department = (char *)malloc(sizeof(char) * 20);

  printf("Name: ");
  fgets(x->name, 20, stdin);

  printf("Surname: ");
  fgets(x->surname, 20, stdin);

  printf("Occupation: ");
  fgets(x->occupation, 20, stdin);

  printf("Department: ");
  fgets(x->department, 20, stdin);

  printf("Code: ");
  scanf("%d", &x->code);

  printf("Birth date: ");
  scanf("%d-%d-%d", &x->birth_date.year, &x->birth_date.month,
        &x->birth_date.day);

  printf("Employment date: ");
  scanf("%d-%d-%d", &x->empl_date.year, &x->empl_date.month, &x->empl_date.day);

  // catch last \n
  getchar();
}

void print_employee(Personal_data x) {
  // print data about an employee

  printf("Name:            %s", x.name);
  printf("Surname:         %s", x.surname);
  printf("Occupation:      %s", x.occupation);
  printf("Department:      %s", x.department);
  printf("Code:            %d\n", x.code);
  // pad day/month with zeroes
  printf("Birth date:      %d-%02d-%02d\n", x.birth_date.year,
         x.birth_date.month, x.birth_date.day);
  printf("Employment date: %d-%02d-%02d\n", x.empl_date.year, x.empl_date.month,
         x.empl_date.day);
}

int cmp_empl(void const *a, void const *b) {
  // compare elements based on employment date

  Data_calend y = ((Personal_data *)a)->empl_date;
  Data_calend x = ((Personal_data *)b)->empl_date;

  if (x.year != y.year)
    return x.year - y.year;
  else if (x.month != y.month)
    return x.month - y.month;
  else
    return x.day - y.day;

  return 0;
}

int cmp_code(void const *a, void const *b) {
  return ((Personal_data *)a)->code - ((Personal_data *)a)->code;
}
