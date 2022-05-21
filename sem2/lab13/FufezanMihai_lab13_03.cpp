/*
 * Fufezan Mihai, 2012, lab13, ex 03
 *
 * Write a C++ application that reads a file’s content using the read() method.
 * The obtained data is displayed on the screen. Check the system’s state after
 * each reading operation. The filename is read from the command line.
 */

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  ifstream fin;
  // try to open file
  if (argc)
    fin.open(argv[1]);

  // if file couldn't be opened, exit
  if (fin.bad()) {
    cout << "File couldn't be opened! (Maybe it doesn't exist?)";
    return 1;
  }

  // read contents to string
  string str;
  fin.read(&str[0], 100);

  cout << str;
}
