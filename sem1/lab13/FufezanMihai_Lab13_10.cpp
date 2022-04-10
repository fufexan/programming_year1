/*
 * Fufezan Mihai, 2012, lab13, ex 10
 *
 * Write an application that:
 * - defines a structure called Student, having fields name, surname, group,
 * average mark ;
 * - reads from the keyboard an integer value n;
 * - for each Student it reads from the keyboard (in a function) the personal
 * data (all fields),
 * - stores the information for all the n students and into a binary file, the
 * filename being read from the keyboard;
 * - reads back the file’s contents, displaying the data related to the students
 * who have the average mark >= than a specific value given from the keyboard.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *name, *surname;
  int group;
  float gpa;
} Student;

Student read_student();
void print_student(Student);

int main() {
  FILE *fp;
  bool passing = false;
  int n, minimum;
  char filename[50];
  Student *arr;
  
  printf("Enter the number of students: ");
  scanf("%d", &n);
  arr = (Student*)malloc(sizeof(Student) * n);
  
  printf("Enter the students:\n");
  for(int i = 0; i < n; i++) {
    printf("\nStudent %d\n", i);
    arr[i] = read_student();
  }
  
  printf("\nEnter the filename where the student info will be saved: ");
  scanf("\n%[^\n]s", filename);
  fp = fopen(filename, "wb");
  
  // write array to file
  fwrite(arr, sizeof(Student), n, fp);
  fp = freopen(filename, "rb", fp);
  
  // dealloc array elements
  for(int i = 0; i < n; i++) {
    free(arr[i].name);
    free(arr[i].surname);
  }
  
  // read from file
  fread(arr, sizeof(Student), n, fp);
  fclose(fp);

  printf("\nEnter the minimum GPA: ");
  scanf("%d", &minimum);
  for(int i = 0; i < n; i++)
    if(arr[i].gpa >= minimum) {
      print_student(arr[i]);
      passing = true;
    }
    
  if(!passing) {
    printf("\nThere are no passing students!");
  }
      
  // dealloc
  for(int i = 0; i < n; i++) {
    free(arr[i].name);
    free(arr[i].surname);
  }
  free(arr);
}

Student read_student() {
  // read a student
  
  Student x;
  x.name = (char*)malloc(sizeof(char) * 20);
  x.surname = (char*)malloc(sizeof(char) * 20);
  
  printf("\nName: ");
  scanf("%s", x.name);
  printf("Surname: ");
  scanf("%s", x.surname);
  printf("Group: ");
  scanf("%d", &x.group);
  printf("Grade Point Average: ");
  scanf("%f", &x.gpa);
  
  return x;
}

void print_student(Student x) {
  // print a student
  
  printf("\nName: %s\n", x.name);
  printf("Surname: %s\n", x.surname);
  printf("Group: %d\n", x.group);
  printf("GPA: %.2f\n", x.gpa);
}
