/*
 * Fufezan Mihai, 2012, lab03, ex 05
 *
 * The optimum capital investment: an investor has a capital C and n offers; he
 * has to invest it into f_i investment funds each of them being associated with
 * a corresponding benefit b_i. Generate all the possible investing solutions.
 * Indicate the solution that brings the maximum profit.
 */

#include <iostream>
#include <vector>

using namespace std;

void back(int k);

int funds, offers;
vector<pair<int, int>> v;

int main() {
  // read number of funds
  cout << "Enter the investor's funds: ";
  cin >> funds;

  // read number of offers
  cout << "Enter the number of offers: ";
  cin >> offers;

  // read offers
  cout << "\nEnter the offers (investment, benefit):\n";
  pair<int, int> x;
  for (int i{}; i < offers; i++) {
    cout << "Offer #" << i << ": ";
    cin >> x.first >> x.second;
    v.push_back(x);
  }
}

void back(int k) {
  for (int i = 0; i < offers; i++) {
    v[k].first = i;
  }
}
