/*
 * Fufezan Mihai, 2012, lab13, ex 01
 *
 * Write a program that uses the seekg() method for mid-file positioning and
 * then displays the file’s content, starting with this position. The filename
 * is read from the command line.
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
  if (fin.bad())
    return 1;

  // get middle of the file
  fin.seekg(0, fin.end);
  int end = fin.tellg();
  fin.seekg(end / 2);

  // print everything in the file from the middle
  char x;
  while (fin.get(x))
    cout << x;
}
