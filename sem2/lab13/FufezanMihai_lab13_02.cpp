/*
 * Fufezan Mihai, 2012, lab13, ex 02
 *
 * Write a program that uses the write() method for writing some character
 * arrays into a file. Display the file’s content using the get() method. The
 * filename is read from the keyboard.
 */

#include <fstream>
#include <iostream>

using namespace std;

int main() {
  string filename;
  string contents;
  string contents2;

  cout << "Enter a file name: ";
  cin >> filename;

  cout << "Enter the contents of the file:\n";
  cin.ignore();
  getline(cin, contents);

  {
    ofstream fout(filename);
    fout.write(contents.data(), contents.size());
  }

  ifstream fin(filename);

  contents2.resize(contents.size());
  fin.get(&contents2[0], contents.size() + 1);

  cout << "Contents read back:\n" << contents2;
}