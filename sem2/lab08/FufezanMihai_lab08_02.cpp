/*
 * Fufezan Mihai, 2012, lab08, ex 02
 *
 * Write a C++ application in which the class Calculator has a private attribute
 * called RAM_memory (int) and a friend function named service_technician( )
 * that can modify the attribute’s value. The friend function will be member in
 * the class Motherboard, that encapsulates the processor_type variable (string
 * of characters). Write the code that allows the modifying of the
 * processor_type’s value and the RAM_memory from the friend function.
 */

#include <iostream>

using namespace std;

class Computer;
class Motherboard;

class Motherboard {
  string cpu_type;

public:
  string getCpuType() { return cpu_type; }
  void setCpuType(string cpu) { cpu_type = cpu; }
  friend Computer service_technician(Computer x, Motherboard mb, int ram,
                                     string cpu_type);
};

class Computer {
  int ram;
  Motherboard mb;

public:
  int getRam() { return ram; }
  string getCpuType() { return mb.getCpuType(); }
  void setCpuType(string cpu) { mb.setCpuType(cpu); }
  friend Computer service_technician(Computer x, Motherboard mb, int ram,
                                     string cpu_type);
};

int main() {
  Computer x;
  Motherboard y;
  int ram;
  string cpu_type;

  cout << "Enter amount of RAM: ";
  cin >> ram;
  cout << "\nEnter new CPU name: ";
  cin >> cpu_type;

  x = service_technician(x, y, ram, cpu_type);

  cout << "\nThe new values are:\n";
  cout << "RAM: " << x.getRam() << '\n';
  cout << "CPU Type: " << x.getCpuType() << '\n';
}

Computer service_technician(Computer x, Motherboard mb, int ram,
                            string cpu_type) {
  x.ram = ram;
  x.setCpuType(cpu_type);

  return x;
}
