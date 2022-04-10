/*
 * Fufezan Mihai, 2012, lab04, ex 09
 *
 * Generate in a random mode maximum 200 integers smaller than 100 and
 * store them into an array. Determine and display the minimum, the median and
 * the maximum value and sort the array in order to accomplish that. Determine
 * the average value and display the difference between it and the calculated
 * median. Check if the average value is part of the initial array.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> gen_numbers();

int main() {
  vector<int> v = gen_numbers();

  sort(v.begin(), v.end());
  cout << "The generated array's minimum value is " << v.front()
       << ", the maximum value is " << v.back() << " and the median value is "
       << v[v.size() / 2];

  float avg{};
  for (int i{}; i < v.size(); i++)
    avg += v[i];
  int iavg = avg / 200;

  cout << "\nThe average value of the array is " << iavg << ".\n";
  if (avg == v[v.size() / 2])
    cout << "It is equal with the median value at position 100.\n";
  else
    cout << "It differs from the median value by "
         << abs(iavg - v[v.size() / 2]) << ".\n";

  vector<int>::iterator it = find(v.begin(), v.end(), iavg);
  if (it == v.end())
    cout << "It isn't present in the vector.";
  else
    cout << "It was found at position " << it - v.begin() << " in the vector.";
}

vector<int> gen_numbers() {
  vector<int> x;

  srand(time(0));
  for (int i{}; i < 200; i++)
    x.push_back(rand() % 100 + 1);

  return x;
}
