/*
 * Fufezan Mihai, 2012, lab02, ex 04
 *
 * Considering the following recursive formulas (Gauss arithmetical-geometrical
 * media): a_n=(a_n-1 + b_n-1)/2 and b_n=sqrt(a_n-1 * b_n-1), determine a_n and
 * b_n for n, a_0 and b_0 read from the standard input.
 */

#include <iostream>
#include <cmath>

using namespace std;

int gaa(int n, int a, int b);
int gga(int n, int a, int b);

int main() {
  int n, a0, b0;

  cout << "Enter the number of times the Gaussian average is run: ";
  cin >> n;
  cout << "Enter a_0 and b_0: ";
  cin >> a0 >> b0;
  
  cout << "a_n = " << gaa(n, a0, b0) << endl;
  cout << "b_n = " << gga(n, a0, b0) << endl;
}

int gaa(int n, int a, int b) {
  if (n == 0)
    return 0;

  return (a + b) / 2 + gaa(n - 1, a + 1, b + 1);
}

int gga(int n, int a, int b) {
  if (n == 0)
    return 0;

  return sqrt(a * b) + gga(n - 1, a + 1, b + 1);
}
