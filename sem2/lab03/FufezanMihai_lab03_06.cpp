/*
 * Fufezan Mihai, 2012, lab03, ex 06
 *
 * Using the "divide et impera" programming method, read the integer values
 * generated in a random mode previously stored into file. Determine the minimum
 * and maximum values from the array. Update the original file by adding the
 * determined values.
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin("random.txt");
ofstream fout("random.txt", ios::app);

template <class Operator> int extrema_vector(vector<int> v, Operator op);

int main() {
  if (fin.fail()) {
    cout << "No input file found! Please supply one named \"random.txt\", "
            "which contains random numbers.";
    exit(1);
  }

  vector<int> v;
  int x;

  // read until EOF
  while (fin >> x)
    v.push_back(x);

  int minimum = extrema_vector(v, less<int>());
  int maximum = extrema_vector(v, greater<int>());

  cout << "\nThe minimum is " << minimum << " and the maximum is " << maximum;

  fout << ' ' << minimum << ' ' << maximum;
}

template <class Operator> int extrema_vector(vector<int> v, Operator op) {
  int ext = v.front();

  for (int i : v)
    if (op(i, ext))
      ext = i;

  return ext;
}
