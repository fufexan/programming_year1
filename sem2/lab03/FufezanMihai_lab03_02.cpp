/*
 * Fufezan Mihai, 2012, lab03, ex 02
 *
 * Consider a computing system that monitors the data transfer on a main
 * communication channel that has a maximum flow capacity of 40 MBps. The data
 * stream can be shared among max 10 users. The channel's data flow is divided
 * automatically by the monitoring program using max 10 (0...9) sub-unitary
 * weights, each of them being associated with a user. The weights are entered
 * from the keyboard when the program starts, and their sum must be 1. If the
 * weights are entered correctly, generate all the possible solutions for each
 * one of the max 10 individual channels, considering that the main channel has
 * the debit between 2MBps and 40 MBps. Calculate the solutions with a precision
 * of MBps. The 0 MBps will be assigned for those channels that cannot have the
 * minimum of 2MBps. Display the solutions. The implementation can be both
 * recursive and non-recursive.
 */

#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

#define MIN 2
#define MAX 40

void solution(int);

double w[10]; // weights
int x[10];    // users' bandwidth
int n = 1, cont;

int main(void) {
  int k, nr_users;

  // get number of users in the network
  cout << "Enter the number of network users (<= 10): ";
  cin >> nr_users;

  // make sure there are at most 10 users
  assert(nr_users <= 10);

  // read weights for each user
  float sum = 0;
  for (int i = 0; i < nr_users; i++) {
    cout << "Weight " << i << ": ";
    cin >> w[i];
    sum += w[i];
  }

  // make sure the weights sum up to 1
  if (sum != 1.0) {
    cout << "\nWrong weights!";
    exit(1);
  }

  while (n != 0) {
    // read bandwidth
    cout << "\nBandwidth: ";
    cin >> n;

    // when bandwidth is within limits
    if (n <= MAX) {
      cont = 0;
      k = 0;
      x[k] = 0;

      do {
        while (x[k] < MAX) {
          x[k]++;

          if (x[k] > MIN) {
            if (k == nr_users - 1)
              solution(nr_users);
            else
              x[k++] = 0;
          }
        }

        k--;
      } while (k >= 0);
    } else
      cout << "\nInvalid bandwidth";
  }
}

void solution(int nr_users) {
  int l;
  double fraction, integer;
  double number = 0;
  int nr;

  for (int i = 0; i < nr_users; i++)
    number += x[i] * w[i];

  fraction = modf(number, &integer);

  if (fraction >= .5)
    integer++;

  l = integer;

  if (l == n) {
    for (int i = 0; i < nr_users; i++) {
      nr = round(x[i] * w[i]);
      cout << "User " << i << " = " << nr << endl;
    }
    cout << "\n\n";
    cont++;
    if (cont > 20) {
      cont = 0;
      cout << "\nEnter a character to continue";
      cin.get();
    }
  }
}