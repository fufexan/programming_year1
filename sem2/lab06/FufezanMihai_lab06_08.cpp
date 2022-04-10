/*
 * Fufezan Mihai, 2012, lab06, ex 08
 *
 * Develop the application from example 6, variant b) with new facilities that
 * allow:
 * - using the returned values of the method setValidPNC() to supplementary
 * validate the PNC (month and day) in main() based on a leap or not year and
 * the month number.
 * - introducing PNC codes that start with numbers different than 1 or 2 and
 * analyze the significance of the new numbers (5 – male, 6 - female).
 */

#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Person {
  string name, surname, PNC;
  // PNC structure: S YY MM DD LLL RR C; total 13 digits

public:
  void setName(string n);
  void setSurname(string p);
  int setValidPNC(string c);
  string getName() { return name; }
  string getSurname() { return surname; }
  string getPNC() { return PNC; }
  char getGender();
  int getBirthYear();
  int getBirthMonth();
  int getBirthDay();
  int getAge();
};

void Person::setName(string n) { name = n; }
void Person::setSurname(string p) { surname = p; }
int Person::setValidPNC(string c) {
  if (c.size() == 13) {
    string buf;
    int n;
    // validare PNC: numai pentru cifra gen, cifrele pentru AN, LU, ZI

    // PNC length
    if (c.size() != 13)
      return 1;

    // gender code
    if (c[0] != '1' && c[0] != '2' && c[0] != '5' && c[0] != '6')
      return 2;

    // year
    // buf = c.substr(1, 2);
    // n = stoi(buf);
    // if ((n <= 99 && c[0] == '5') || (n <= 99 && c[0] == '6'))
    //   return 3;
    // else if ((n > 99 && c[0] == '1') || (n > 99 && c[0] == '2'))
    //   return 3;

    // month
    buf = c.substr(3, 2);
    n = stoi(buf);
    if (n <= 0 || n > 12)
      return 4;

    // day
    buf = c.substr(5, 2);
    n = stoi(buf);
    if (n == 0 || n > 31)
      return 5;

    // copy valid string into PNC
    PNC = c;
    return 0;
  }

  // invalid PNC
  return -1;
}

char Person::getGender() {
  if (PNC[0] == '1' || PNC[0] == '5')
    return 'M';
  if (PNC[0] == '2' || PNC[0] == '6')
    return 'F';
  return 'X';
}

int Person::getBirthYear() {
  int year = 2000 + stoi(PNC.substr(1, 2));
  if (PNC[0] == '1' || PNC[0] == '2')
    year -= 100;
  return year;
}

int Person::getBirthMonth(void) { return stoi(PNC.substr(3, 2)); }

int Person::getBirthDay() { return (PNC[5] - '0') * 10 + (PNC[6] - '0'); }

int Person::getAge() {
  struct tm newTime;
  time_t szClock;

  time(&szClock);
  newTime = *localtime(&szClock);

  int year_c = 1900 + newTime.tm_year;
  int year_n = getBirthYear();
  int n = year_c - year_n;

  int month_c = newTime.tm_mon + 1;
  int month_n = getBirthMonth();
  if (month_c < month_n)
    n--;
  else {
    if (month_c == month_n) {
      int day_c = newTime.tm_mday;
      int day_n = getBirthDay();
      if (day_c < day_n)
        n--;
    }
  }

  return n;
}

bool testDate(int year, int month, int day);

int main() {
  Person p1;
  string aux_string;

  cout << "\nEnter Name: ";
  cin >> aux_string; // Popescu
  p1.setName(aux_string);

  cout << "\nEnter Surname: ";
  cin.ignore();
  getline(cin, aux_string); // may have multiple surnames
  p1.setSurname(aux_string);

  cout << "\nEnter PNC: ";
  cin >> aux_string; // 1890403120671

  int t_PNC = p1.setValidPNC(aux_string);

  switch (t_PNC) {
  case 0:
    if (testDate(p1.getBirthYear(), p1.getBirthMonth(), p1.getBirthDay())) {
      cout << "\nPNC valid\n";
      cout << "\nObject data: " << endl;
      cout << "Name: " << p1.getName() << "\nSurname: " << p1.getSurname()
           << "\nPNC: " << p1.getPNC() << endl;
      cout << "Gender: " << p1.getGender() << endl;
      cout << "Birth date: " << p1.getBirthYear() << "-" << setfill('0')
           << setw(2) << p1.getBirthMonth() << "-" << setfill('0') << setw(2)
           << p1.getBirthDay() << endl;
      cout << "Age: " << p1.getAge() << endl;
    } else
      cout << "Date is invalid!";
    break;
  case 1:
    cout << "\nPNC length invalid";
    break;
  case 2:
    cout << "\nInvalid gender";
    break;
  case 3:
    cout << "\nInvalid year";
    break;
  case 4:
    cout << "\nInvalid month";
    break;
  case 5:
    cout << "\nInvalid day";
    break;
  default:
    cout << "\nPNC has issues";
    break;
  }
}

bool testDate(int year, int month, int day) {
  // general validation
  if (year > 9999 || month > 12 || day > 31)
    return 0;

  // validate feb with bisect years
  if (month == 2 && day > 28) {
    if (year % 4 == 0 && day == 29)
      return 1;
    return 0;
  }

  // validate the 4 30-day months
  if (month == 4 || month == 6 || month == 9 || month == 11)
    if (day > 30)
      return 0;

  // date is valid
  return 1;
}