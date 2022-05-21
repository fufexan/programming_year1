/*
 * Fufezan Mihai, 2012, lab13, ex 04
 *
 * Write a C++ application that opens a binary file for reading. The filename is
 * read from the keyboard. Display a message if the file doesn’t exist and ask
 * the user to re-enter the filename. Assuming that the file contains some
 * agenda records (name, city, phone number) overload the insertion and
 * extraction operators for reading the file’s content and for displaying it on
 * the screen
 */

#include <fstream>
#include <iostream>

using namespace std;

struct Agenda {
  string name, city, phone;
};

int main() {
  string filename;

  cout << "Enter a filename: ";
  cin >> filename;

  ifstream fin(filename, ios::binary);

  while (fin.bad()) {
    cout << "File does not exist. Reenter name: ";
    cin >> filename;
  }

  Agenda agenda;
  fin >> agenda.name >> agenda.city >> agenda.phone;
  cout << agenda.name << agenda.city << agenda.phone;
}

// will never be used due to binary file
istream &operator>>(istream &stream, Agenda a) {
  return stream >> a.name >> a.city >> a.phone;
}

ostream &operator<<(ostream &stream, Agenda a) {
  return stream << a.name << a.city << a.phone;
}
