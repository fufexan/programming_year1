/*
 * Fufezan Mihai, 2012, lab12, ex 03
 *
 * Consider a data acquisition process from a hardware device (10 variables real
 * type). Display, using an appropriate message, the data in a minimal format
 * (the integer part). Determine the average value of the displayed numbers and
 * if it is greater than a previously defined (or entered) threshold, display
 * the data in a detailed format (float variables, 8 digits precision at the
 * fractional part).
 */

#include <iomanip>
#include <iostream>

using namespace std;

ostream &init(ostream &stream);

int main() {
  float v[10], avg{}, threshold;

  cout << "Enter 10 numbers: ";
  for (int i{}; i < 10; i++)
    cin >> v[i];

  cout << "\nThe numbers are:\n";
  for (int i{}; i < 10; i++) {
    cout << init << v[i] << '\n';
    avg += v[i];
  }

  cout << "\nEnter a threshold: ";
  cin >> threshold;

  if (avg / 10 >= threshold)
    cout.precision(8);
  cout << "\nThe average of the numbers is: " << avg / 10;
}

ostream &init(ostream &stream) {
  stream.precision(0);
  return stream;
}
