/*
 * Fufezan Mihai, 2012, lab01, ex 05
 *
 * Using functions overloading define 3 functions with the same name but with
 * different prams type (int, int*, int&) that will return the square root of
 * the int value. Analyze the calling mechanism by value and reference.
 */

#include <cmath>
#include <iostream>

using namespace std;

float sq_rt(int);
float sq_rt(int *, int);
float sq_rt(int &, int);

int main() {
  int x;

  cout << "Enter a number: ";
  cin >> x;
  cout << "The square root of your number is: " << sq_rt(x) << endl;
  cout << "\nEnter another number: ";
  cin >> x;
  cout << "The square root of your number is: " << sq_rt(x, 1) << endl;
  cout << "\nEnter another number: ";
  cin >> x;
  cout << "The square root of your number is: " << sq_rt(x, 2) << endl;
}

float sq_rt(int x) { return sqrt(x); }
float sq_rt(int *x, int a) { return sqrt(*x); }
float sq_rt(int &x, int b) { return sqrt(x); }
