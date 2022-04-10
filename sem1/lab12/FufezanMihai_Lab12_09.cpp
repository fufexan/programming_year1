/*
 * Fufezan Mihai, 2012, lab12, ex 09
 *
 * Write a C/C++ application that allocates the necessary amount of memory for
 * storing n products, using a structure named Product having the fields: name,
 * price, quantity. After reading from the keyboard each product’s data, display
 * the item that has the biggest stock value. Free up the allocated memory.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[20];
  float price;
  int qty;
} Product;

Product read_prod();
void print_prod(Product);

int main() {
  int n, ind, mqty = 0;
  Product *arr;
  
  printf("Enter the number of products to store: ");
  scanf("%d", &n);
  
  arr = (Product*)malloc(sizeof(Product) * n);
  
  // read elements and find the one with the biggest stock value
  printf("\nEnter the products:");
  for(int i = 0; i < n; i++) {
    printf("\nProduct %d\n", i);
    arr[i] = read_prod();
    if(arr[i].qty > mqty) {
      mqty = arr[i].qty;
      ind = i;
    }
  }
    
  printf("\nThe item with the biggest stock value is:\n");
  print_prod(arr[ind]);
  
  free(arr);
}

Product read_prod() {
  // read a product
  
  Product x;
  printf("Name: ");
  scanf("\n%[^\n]s", x.name);
  
  printf("Price: ");
  scanf("%f", &x.price);

  printf("Quantity: ");
  scanf("%d", &x.qty);
  
  return x;
}

void print_prod(Product x) {
  // print a product
  
  printf("Name: %s\n", x.name);
  printf("Price: %.2f\n", x.price);
  printf("Quantity: %d\n", x.qty);
}
