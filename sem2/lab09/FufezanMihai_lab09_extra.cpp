/*
 * Fufezan Mihai, 2012, lab09, ex extra
 *
 * Create a Car class with attributes name (char*), km (int) and seats (int).
 * Overload operator- to take an int number of km to subtract from the class
 * attribute km. Overload operator+ as a friend function which takes an int
 * number of seats to add to the class attribute seats. Create setters & getters
 * for each attribute.
 *
 * Car - name  (*char)
 *     - km    (int)
 *     - seats (int)
 * Overload + (seats),
 */

#include <cstring>
#include <iostream>

using namespace std;

class Car {
  char *name = nullptr;
  int km, seats;

public:
  Car(int km = 0, int seats = 2, char *name = (char *)"Default") {
    this->km = km;
    this->seats = seats;
    this->name = new char[30];
    strcpy(this->name, name);
  }
  Car(Car &x) {
    km = x.getKm();
    seats = x.getSeats();
    name = new char[30];
    strcpy(name, x.getName());
  }
  ~Car() {
    // if (name != nullptr)
    delete[] name;
  }

  void setKm(int x) { km = x; }
  void setSeats(int x) { seats = x; }
  void setName(char *x);
  int getKm() { return km; }
  int getSeats() { return seats; }
  char *getName() { return name; }

  friend Car operator+(Car x, int y);
  Car operator-(int y);
};

int main() {
  char name[20];
  int k, s;
  cout << "Enter a car name, its km and number of seats: ";
  cin >> name >> k >> s;
  Car a(k, s, name);

  cout << "\nHow many seats do you want to add? ";
  cin >> s;
  a = a + s;
  cout << "\nThe car now has " << a.getSeats() << " seats.\n";

  cout << "\nHow many km do you want to remove? ";
  cin >> k;
  a = a - k;
  cout << "\nThe car now has " << a.getKm() << " km.\n";
}

// add seats
Car operator+(Car x, int y) {
  int s = y + x.getSeats();

  Car res;
  res.setKm(x.getKm());
  res.setSeats(s);
  res.setName(x.getName());

  return res;
}

// subtract km
Car Car::operator-(int y) {
  int k = km - y;

  Car res;
  res.setKm(k);
  res.setSeats(getSeats());
  res.setName(getName());

  return res;
}

void Car::setName(char *x) {
  // realloc when needed
  // if (strlen(x) > strlen(name)) {
  //   delete[] name;
  name = new char[strlen(x) + 1];
  // }
  strcpy(name, x);
}
