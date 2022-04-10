/*
 * Fufezan Mihai, 2012, lab08, ex 01
 *
 * Implement a C++ application that defines the class called CurrentHour with
 * hour, minute, second as private attributes. The class has public
 * setter/getter methods for each attribute. Add a friend function that copies
 * the content of a CurrentHour object used as parameter into another instance
 * of the class that will be returned by the function, hour being modified to
 * Greenwich Mean Time. Use the computer local current time.
 */

#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

time_t t = time(0);
struct tm date = *(localtime(&t));

class CurrentHour {
  int h, m, s;

public:
  void setH(int h) { this->h = h; }
  void setM(int m) { this->m = m; }
  void setS(int s) { this->s = s; }
  int getH() { return h; }
  int getM() { return m; }
  int getS() { return s; }
  friend CurrentHour toGMT(CurrentHour x);
};

bool dateValid(int h, int m, int s);

int main() {
  CurrentHour x, y;
  int h, m, s;

  // read date
  cout << "Enter current time (HH MM SS): ";
  cin >> h >> m >> s;

  // verify
  while (!dateValid(h, m, s)) {
    cout << "Date invalid! Reenter (HH MM SS): ";
    cin >> h >> m >> s;
  }

  x.setH(h);
  x.setM(m);
  x.setS(s);

  y = toGMT(x);
  cout << "The time in GMT is: " << setfill('0') << setw(2) << y.getH() << ' '
       << setfill('0') << setw(2) << y.getM() << ' ' << setfill('0') << setw(2)
       << y.getS();
}

CurrentHour toGMT(CurrentHour x) {
  CurrentHour y;

  y.h = x.h - 2;
  if (date.tm_isdst)
    y.h--;
  y.m = x.m;
  y.s = x.s;

  // overflow checks
  while (y.s > 59) {
    y.m++;
    y.s -= 60;
  }
  while (y.m > 59) {
    y.h++;
    y.m -= 60;
  }

  // underflow checks
  while (y.m < 0) {
    y.h--;
    y.m += 60;
  }
  while (y.s < 0) {
    y.m--;
    y.s += 60;
  }

  // hour checks
  while (y.h < 0) {
    y.h += 24;
  }
  while (y.h > 24) {
    y.h -= 24;
  }

  return y;
}

bool dateValid(int h, int m, int s) {
  if (h < 0 || h > 24 || m < 0 || m > 59 || s < 0 || s > 59)
    return 0;
  return 1;
}
