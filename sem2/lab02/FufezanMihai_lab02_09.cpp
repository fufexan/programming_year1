/*
 * Fufezan Mihai, 2012, lab02, ex 09
 *
 * Using a recursive function, calculate the sum of a series composed of
 * keyboard entered values. The values are read as long as the user desires so.
 * Modify the function in order to determine and display the average value of
 * the entered numbers. Print on the screen a significant message when the sum
 * is greater than a predefined value.
 */

#include <iostream>
#include <vector>

using namespace std;

int sum_series(vector<int>);

int main() {
  int x, threshold = 50;
  char c = '\n';

  vector<int> series{};

  cout << "Enter a series of numbers: ";
  while (c == '\n' || c == 'y' || c == 'Y') {
    cin >> x;
    series.push_back(x);

    cout << "Enter more? Y/n: ";
    c = getchar();
  }

  int sum = sum_series(series);
  cout << "\nThe sum of the series is " << sum;
  if(sum > threshold)
    cout << ".\nIt is bigger than " << threshold;
  cout << ".\nThe series average is " << sum / (series.size() - 1);
}

int sum_series(vector<int> series) {
  if (!series.empty()) {
    // get last element
    int le = series.back();
    // remove last element
    series.pop_back();
    // return last element + next iteration
    return (le + sum_series(series));
  }
  return 0;
}
