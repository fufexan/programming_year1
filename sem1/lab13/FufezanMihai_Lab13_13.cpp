/*
 * Fufezan Mihai, 2012, lab13, ex 13
 *
 * Define a structure called Cookie that contains as variables the name,
 * no_of_pieces and price. Read from the keyboard the data for n cookies and
 * save it into a binary file. Read back the file and display the information
 * belonging to the cheapest cookie.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[100];
  float price;
  int no_of_pieces;
} Cookie;

int main() {
  int n, ind;
  float cheapest = 0;

  printf("Enter how many cookies you want to store: ");
  scanf("%d", &n);

  // allocate array
  Cookie *arr = (Cookie *)malloc(sizeof(Cookie) * n);

  // open file
  FILE *fp = fopen("13.txt", "wb");

  for (int i = 0; i < n; i++) {
    printf("\nCookie #%d\n", i);

    // read cookie. won't write a function as we can't switch between binary and
    // text files easily
    getchar();
    printf("Name: ");
    scanf("%[^\n]s", arr[i].name);
    printf("Price: ");
    scanf("%f", &arr[i].price);
    printf("Number of pieces: ");
    scanf("%d", &arr[i].no_of_pieces);

    // print cookie to binary file
    fwrite(&arr[i], sizeof(Cookie), 1, fp);

    // check cheapest cookie
    if (arr[i].price < cheapest) {
      cheapest = arr[i].price;
      ind = i;
    }
  }

  // dealloc
  free(arr);

  fp = freopen("13.txt", "rb", fp);

  // print cheapest cookie
  fseek(fp, sizeof(Cookie) * ind, SEEK_SET);
  fread(arr, sizeof(Cookie), 1, fp);

  printf("\nThe cheapest cookie is:\n"
         "Name: %s\nPrice: %.2f\nNumber of pieces: %d",
         arr->name, arr->price, arr->no_of_pieces);
        
  fclose(fp);
}
