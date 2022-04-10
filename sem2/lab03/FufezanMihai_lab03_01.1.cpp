#include <iostream>
using namespace std;

#define DIM 5

int possible(int);
void display_solution(int n);
void display_solution_color(int n);
void back(int k);

int x[DIM], n;
int h;
int main() {
  cout << "Enter the number of colors of a flag (<= " << DIM << "): ";
  cin >> n;

  cout << "Enter the maximum number of colors available for a strip: ";
  cin >> h;

  back(0); // call of recursive function
}

void back(int k) {
  for (int i = 1; i <= h; i++) {
    x[k] = i;

    if (possible(k)) {
      if (k == n - 1)
        display_solution_color(n); // final solution
      else
        back(k + 1); // move to next component
    }
  }
}

int possible(int k) {
  if (k == 0)
    return 1; // initially everything is possible
  if (x[k - 1] == x[k])
    return 0; // two identical colors next to each other - not possible
  return 1;   // the adjacent colors are not identical
}

void display_solution(int n) {
  // display the current solution for the flag components
  for (int i = 0; i < n; i++)
    cout << x[i];
  cout << "\n";
}

void display_solution_color(int n) {
  // display the current solution for the flag components as color blocks
  for (int i = 0; i < n; i++)
    cout << "\u001b[3" << x[i] << "m█";
  cout << "\u001b[30m]\n";
}