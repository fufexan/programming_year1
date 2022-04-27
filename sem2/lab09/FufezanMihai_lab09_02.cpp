/*
 * Fufezan Mihai, 2012, lab09, ex 02
 *
 * Modify the operator overload - allowing multiple occurrences of the initial
 * string from example 1 to be dropped. Analyze the application functionalities.
 */

#include <cstring>
#include <iostream>
using namespace std;

const int size = 31; // 30+1 for \0

class String {
  char str[size];

public:
  String() = default;
  String(char x[size]) { strcpy(str, x); }

  char *getString() { return str; }

  String operator+(String x1) {
    String res;
    strcpy(res.str, str);
    strcat(res.str, x1.str);
    return res;
  }

  char operator[](int pos) {
    char res;
    res = str[pos];
    return res;
  }

  friend String operator-(String &x1, String &x2);
};

String operator-(String &x1, String &x2) {
  char *pp = strstr(x1.str, x2.str);

  if (!pp)
    return String(x1.str);

  char buf[size];
  while (pp) {
    strncpy(buf, x1.str, pp - x1.str);
    strcpy(buf + (pp - x1.str), pp + strlen(x2.str));

    pp = strstr(buf, x2.str);
  }

  return String(buf);
}

int main() {
  char xx[size];

  cout << "Enter first string: ";
  cin.getline(xx, sizeof(xx));
  String ob1(xx);

  cout << "Enter second string: ";
  cin.getline(xx, sizeof(xx));
  String ob2(xx);

  String ob3;
  ob3 = ob1 + ob2;

  cout << "\nAdding the two strings yields: " << ob3.getString();
  cout << "\nEnter a string to subtract from the first one: ";
  cin.getline(xx, sizeof(xx));
  String ob4(xx);

  String ob5 = ob1 - ob4;
  cout << "\nString obtained after subtraction: " << ob5.getString();
  char c = ob5[0];
  cout << "\nFirst character is: " << c;
}