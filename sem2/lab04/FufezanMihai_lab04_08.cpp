/*
 * Fufezan Mihai, 2012, lab04, ex 08
 *
 * Read from two files two one dimensional arrays composed of real values.
 * Generate a third array that contains all the values from the initial arrays
 * and all the values obtained by calculating the average of the corresponding
 * numbers. If the initial arrays have different numbers of values, the average
 * is calculated between the existent values and 0.0. Order the last array and
 * count the number of non-unique elements.
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin1("realnumbers1.txt");
ifstream fin2("realnumbers2.txt");

vector<float> averages(vector<float> v1, vector<float> v2);

int main() {
  vector<float> v1, v2, v3;

  // check if the files exist
  if (fin1.fail()) {
    cout << "File 'realnumbers1.txt' does not exist!";
    exit(1);
  }

  if (fin2.fail()) {
    cout << "File 'realnumbers2.txt' does not exist!";
    exit(1);
  }

  // read numbers
  int x;
  while (fin1 >> x)
    v1.push_back(x);
  while (fin2 >> x)
    v2.push_back(x);

  // copy vectors into 3rd vector
  copy(v1.begin(), v1.end(), back_inserter(v3));
  copy(v2.begin(), v2.end(), back_inserter(v3));

  // generate vector with averages
  vector<float> avgs = averages(v1, v2);
  copy(avgs.begin(), avgs.end(), back_inserter(v3));

  // sort averages vector
  sort(avgs.begin(), avgs.end());

  int dup{};
  for (int i{}; i < avgs.size() - 1; i++)
    if (avgs[i] == avgs[i + 1])
      dup++;

  cout << "\nThere are " << dup << " duplicate averages.";
}

vector<float> averages(vector<float> v1, vector<float> v2) {
  vector<float> x;

  for (int i{}; i < min(v1.size(), v2.size()); i++) {
    x.push_back((v1[i] + v2[i]) / 2.0f);
  }

  if (v1.size() > v2.size()) {
    for (int i{}; i < v1.size(); i++)
      x.push_back(v1[i] / 2.0f);
  }

  if (v2.size() > v1.size()) {
    for (int i{}; i < v2.size(); i++)
      x.push_back(v2[i] / 2.0f);
  }

  return x;
}
