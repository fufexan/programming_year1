/*
 * Fufezan Mihai, 2012, lab10, ex 02
 *
 * Using the classes from public inheritance example, implement 2 classes with
 * the following requests:
 * - the base class has the methods for:
 * - coding an array of characters (using a user-defined algorithm – recommended
 * XOR with a fix mask) => public;
 * - displaying the original and the coded array = > public;
 * - the derived class has a method for:
 * - appending the coded array at the end of a previously created text file.
 * Each record respects the format: record_number: coded_array;
 * The methods located in both classes are accessed using an instance of the
 * derived class. The program that uses the classes reads from the keyboard an
 * array of characters and allows the user to choose whether the input will be
 * coded or will be appended at the end of the text file.
 */

class Base {
protected:
  char str[50];
  char mask = 0b01000111;

public:
  void setStr(char *str);
  void encode();
  void display();
};

class Derived : public Base {
public:
  void appendFile();
};

int getNum();

// includes
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

// init file streams
ifstream fin("records.txt");
ofstream fout("records.txt", ios_base::out | ios_base::app);

// get position
int number = getNum();

int main() {
  Derived deriv_obj;
  char str[50], type = 0;

  cout << "Enter a string: ";
  cin >> str;
  deriv_obj.setStr(str);

  while (type != 'q') {
    cout << "\nWhat do you want to do with the string?\ne - encode\na - "
            "append to file\nd - display string\nq - quit: ";
    cin >> type;

    switch (type) {
    case 'e':
      deriv_obj.encode();
      break;
    case 'a':
      deriv_obj.appendFile();
      break;
    case 'd':
      deriv_obj.display();
      break;
    case 'q':
      break;
    default:
      cout << "Unknown operation!";
    }
  }
}

// function implementations
void Base::encode() {
  for (int i{}; i < strlen(str); i++)
    str[i] ^= mask;
}
void Base::display() { cout << str << endl; }
void Base::setStr(char *str) { strcpy(this->str, str); }
void Derived::appendFile() { fout << number << " = " << str << endl; }

int getNum() {
  char str[60]{}, str2[60]{};

  // non-existent file
  if (fin.fail())
    return 1;

  // get last line
  while (!fin.eof()) {
    strcpy(str2, str);
    fin.getline(str, 60);
  }

  // return int from string
  return stoi(string(str2)) + 1;
}