/*
 * Fufezan Mihai, 2012, lab01, ex 09
 *
 * Implement a C/C++ application that applies (using a macro function with XOR)
 * a binary mask to each element located in an array of characters. Define the
 * decoding function, too. Example: considering the character a and the mask
 * code 11001010:
 * a. the coding result will be obtained as it follows:
 * 'a' -> 97
 * (0x61) ASCII ->01100001 XOR Binary code (mask) 11001010
 * ------------
 * 10101011
 *
 * b. the decoding process:
 * the coded result -> 10101011 XOR
 * binary code mask 11001010
 * ------------
 * 01100001 - the ASCII code of a
 */

#include <cstring>
#include <iostream>

using namespace std;

#define ENC(x)                                                                 \
  { x ^= 0xCA; }
#define DEC(x)                                                                 \
  { x ^= 0xCA; }

int main() {
  const int n = 50;
  char arr[n]{};

  cout << "Enter a string: ";
  cin.getline(arr, n);
  int l = strlen(arr);

  cout << "\nThe encoded string's elements' complements of 0xCA is: ";
  for (int i = 0; i < l; i++) {
    ENC(arr[i]);
    cout << (int)arr[i] << ' ';
  }
  cout << endl;

  for (int i = 0; i < l; i++)
    DEC(arr[i]);

  cout << "\nThe decoded string is: " << arr << endl;
}
