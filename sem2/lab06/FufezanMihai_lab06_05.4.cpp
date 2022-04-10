/*
 * Fufezan Mihai, 2012, lab06, ex 04
 *
 * Write a C++ class that has as private attribute a date field. The date is
 * defined as a structure declared outside the class and it contains the fields
 * day(int), month(int), year(int).

 * The class contains public accessor/getter and mutator/setter methods that can
 * use the private information as date structure, for all fields from the
 * structure. The class also contains two public methods that:
 * - test the validity of the stored date.
 * - write into a file all the dates from the current year that precede
 * chronologically the class stored date based only on the year attribute as a
 * modified attribute.

 * In the main() function, after instantiating the class and after reading from
 * the keyboard all the components of a date, call the member methods and then
 * verify the obtained results.
 */

#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

ofstream fout("dates.txt");

struct Date {
  int day, month, year;
};

class A {
  Date date;

public:
  Date getDate() { return date; }
  void setDate(Date x) { date = x; }

  bool testDate();
  void writeDatesYear();
};

int main() {
  A *obj = new A;
  Date date;

  string str;
  int x[3];
  cout << "Enter a date (ISO-8601): ";
  cin >> x[0] >> x[1] >> x[2];

  date.year = abs(x[0]);
  date.month = abs(x[1]);
  date.day = abs(x[2]);

  obj->setDate(date);

  obj->writeDatesYear();
}

bool A::testDate() {
  // general validation
  if (date.year > 9999 || date.month > 12 || date.day > 31)
    return 0;

  // validate feb with bisect years
  if (date.month == 2 && date.day > 28) {
    if (date.year % 4 == 0 && date.day == 29)
      return 1;
    return 0;
  }

  // validate the 4 30-day months
  if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
    if (date.day > 30)
      return 0;

  // date is valid
  return 1;
}

void A::writeDatesYear() {
  bool stop = false;

  // copy date to object so that we can test it with testDate
  Date date = this->date;

  // cycle through dates and verify them
  for (int mo{1}; mo <= date.month; mo++) {
    for (int day{1}; day <= 31 && !stop; day++) {
      this->date.day = day;
      this->date.month = mo;

      if (testDate()) {
        // don't go past current date
        if (this->date.month == date.month && this->date.day == date.day)
          stop = true;

        // write date (padded, YYYY-MM-DD)
        fout << this->date.year << '-' << setfill('0') << setw(2)
             << this->date.month << '-' << setfill('0') << setw(2)
             << this->date.day << '\n';
      }
    }
  }

  // set date back to original date
  this->date = date;
}