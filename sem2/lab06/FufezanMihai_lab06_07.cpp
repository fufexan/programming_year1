/*
 * Fufezan Mihai, 2012, lab06, ex 07
 *
 * Write a class named Safe that has as private attributes the cipher (pin, 4
 * int digits) and the amount of money of double type. Implement the private
 * methods getMoney() and setMoney(). The public methods putInSafe() and
 * getFromSafe() will call the previous private methods only if the cipher sent
 * as parameter matches the value stored inside the class. Display a message if
 * the cipher is not correct.
 */

#include <iostream>

using namespace std;

class Safe {
  int cipher[4]{3, 4, 5, 2};
  double money;

  double getMoney();
  void setMoney(double amount);

public:
  void putInSafe(int *cipher, double amount);
  double getFromSafe(int *cipher);
};

int main() {
  Safe safe;

  int cipher[4], amount;

  cout << "Enter a cipher(4 digits, space separated): ";
  for (int i{}; i < 4; i++)
    cin >> cipher[i];

  cout << "Enter an amount of money you want to add to the safe: ";
  cin >> amount;

  safe.putInSafe(cipher, amount);

  amount = safe.getFromSafe(cipher);
  if (amount != -1)
    cout << "\nThe total amount of money in the safe is " << amount;
}

double Safe::getMoney() { return money; }
void Safe::setMoney(double amount) { money = amount; }

void Safe::putInSafe(int *cipher, double amount) {
  bool ok = true;

  for (int i{}; i < 4 && ok; i++)
    if (cipher[i] != this->cipher[i])
      ok = false;

  if (ok) {
    setMoney(amount);
    cout << "\nMoney set successfully.\n";
  } else
    cout << "\nCipher incorrect. Money not set.\n";
}

double Safe::getFromSafe(int *cipher) {
  bool ok = true;

  for (int i{}; i < 4 && ok; i++)
    if (cipher[i] != this->cipher[i])
      ok = false;

  if (ok)
    return getMoney();

  cout << "\nCipher incorrect. Money not read.\n";
  return -1;
}
