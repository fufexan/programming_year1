/*
 * Fufezan Mihai, 2012, lab07, ex 5
 *
 * Write a program that: 
 * - determines the greatest prime number that’s smaller than a certain given number; 
 * - determines all the prime numbers smaller than a given number; 
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>

bool is_prime(int);
int find_greatest_prime(int);
void find_all_prime(int);

int main() {
  int x;

  printf("Enter an integer value: ");
  scanf("%d", &x);

  printf("The greatest prime number smaller than %d is %d\n", x,
          find_greatest_prime(x - 1));

  printf("All the prime numbers smaller than %d are: ", x);
  find_all_prime(x);
}

int find_greatest_prime(int x) {
  // find greatest prime number <= x
  if(x != 2 && x % 2 == 0) x--;

  while(!is_prime(x) && x) x -= 2;

  return x;
}

void find_all_prime(int x) {
  // find and print all prime numbers <= x
  while(x--) if(is_prime(x)) printf("%d ", x);
}

bool is_prime(int x) {
  // check if a given number is prime
  if(x == 2)
    return true;
  else if(x == 1 || x % 2 == 0)
    return false;
  else {
    for(int i = 3; i * i <= x; i += 2)
      if(x % i == 0) return false;
  }

  return true;
}
