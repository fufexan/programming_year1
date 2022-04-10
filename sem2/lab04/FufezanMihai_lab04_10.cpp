/*
 * Fufezan Mihai, 2012, lab04, ex 10
 *
 * Generate 200 random float values. Store the integer parts (not bigger than
 * 100) into an array. The fractional parts (limited at 20 as an integer value
 * representing a 0.20 fractional part) are stored into another array with the
 * same size as the first one. The initial values re-calculated by combining the
 * elements stored into the previously described arrays are stored into another
 * vector. Display all the arrays. Use the qsort() library function for storing
 * the float values and display the final result.
 */

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int size = 200;

vector<double> gen_floats();
int cmp(const void *a, const void *b);

int main() {
  vector<double> floats = gen_floats(), frac, ints;

  cout << "The generated floats vector is:\n";
  for (float i : floats)
    cout << i << ' ';

  cout << "\n\nThe ints are:\n";
  for (int i{}; i < size; i++) {
    ints.push_back(i);
    frac.push_back(modf(floats[i], &ints[i]));
    cout << ints[i] << ' ';
  }

  cout << "\n\nThe fractional parts are:\n";
  for (int i{}; i < size; i++)
    cout << frac[i] << ' ';

  vector<double> constructed;
  cout << "\n\nThe reconstructed vector is:\n";

  for (int i{}; i < size; i++) {
    constructed.push_back(frac[i] + ints[i]);
    cout << constructed[i] << ' ';
  }

  qsort(&constructed[0], size, sizeof(double), cmp);
  cout << "\n\nThe sorted reconstructed vector is:\n";
  for (double i : constructed)
    cout << i << ' ';
}

vector<double> gen_floats() {
  vector<double> x;

  srand(time(0));
  for (int i{}; i < size; i++)
    x.push_back(rand() % 100 + (rand() % 100) * 0.01f);

  return x;
}

int cmp(const void *a, const void *b) { return *(double *)a - *(double *)b; }
