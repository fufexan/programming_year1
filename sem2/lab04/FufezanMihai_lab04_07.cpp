/*
 * Fufezan Mihai, 2012, lab04, ex 07
 *
 * Write a program that sorts a stock of computers, represented in the program
 * as objects created from a structure that stores the computers’
 * characteristics: name (string of characters), processor type(string of
 * characters), frequency (long int), RAM memory (int), price (float).
 * The sorting is performed, as specified by the user, by price, memory amount,
 * frequency, or processor type. Use the qsort( ) library function or any other
 * sorting technique. Next sort the data using a character string and a
 * numerical field. Display the results
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Computer {
  string name, cpu_type;
  long freq;
  int ram;
  float price;
};

Computer read_computer();
void print_computer(Computer x);
void sort_computers(vector<Computer> &computers, char c);

bool cmp_n(Computer a, Computer b);
bool cmp_c(Computer a, Computer b);
bool cmp_f(Computer a, Computer b);
bool cmp_r(Computer a, Computer b);
bool cmp_p(Computer a, Computer b);

int main() {
  vector<Computer> computers;
  int n;

  cout << "How many computers do you want to enter? ";
  cin >> n;

  cout << "Enter the computers:\n";
  for (int i = 0; i < n; i++) {
    cout << "\nComputer #" << i + 1 << ":\n";
    computers.push_back(read_computer());
  }

  char c;
  cout << "\nWhat criteria do you want to sort by?\n"
          "n - name\nc - cpu type\nf - frequency\nr - ram size\np - price: ";
  cin >> c;

  sort_computers(computers, c);

  cout << "\nThe sorted computers are:\n";
  for (int i{}; i < computers.size(); i++) {
    cout << "\nComputer #" << i + 1 << endl;
    print_computer(computers[i]);
    cout << endl;
  }
}

Computer read_computer() {
  Computer x;

  cout << "Name: ";
  cin >> x.name;
  cout << "CPU type: ";
  cin >> x.cpu_type;
  cin.get();
  cout << "Frequency: ";
  cout.flush();
  cin >> x.freq;
  cout << "RAM size: ";
  cin >> x.ram;
  cout << "Price: ";
  cin >> x.price;

  return x;
}

void print_computer(Computer x) {
  cout << "Name: " << x.name << endl;
  cout << "CPU type: " << x.cpu_type << endl;
  cout << "Frequency: " << x.freq << endl;
  cout << "RAM: " << x.ram << endl;
  cout << "Price: " << x.price << endl;
}

void sort_computers(vector<Computer> &computers, char c) {
  bool (*cmp)(Computer a, Computer b);

  switch (c) {
  case 'n':
    cmp = cmp_n;
    break;
  case 'c':
    cmp = cmp_c;
    break;
  case 'f':
    cmp = cmp_f;
    break;
  case 'r':
    cmp = cmp_r;
    break;
  case 'p':
    cmp = cmp_p;
    break;
  }

  sort(computers.begin(), computers.end(), cmp);
}

bool cmp_n(Computer a, Computer b) { return (a.name.compare(b.name) < 0); }
bool cmp_c(Computer a, Computer b) {
  return (a.cpu_type.compare(b.cpu_type) < 0);
}
bool cmp_f(Computer a, Computer b) { return (a.freq < b.freq); }
bool cmp_r(Computer a, Computer b) { return (a.ram < b.ram); }
bool cmp_p(Computer a, Computer b) { return (a.price < b.price); }
