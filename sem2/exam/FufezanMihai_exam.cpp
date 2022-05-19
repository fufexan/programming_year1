// Fufezan Mihai, 2012, sem2 exam

#include <fstream>
#include <iomanip>
#include <iostream>

std::ostream &manip(std::ostream &stream);

class Vehicle {
protected:
  std::string name, producer;
  int wheels;

public:
  Vehicle(std::string n = "unknown", std::string p = "unknown",
          int w = 0) noexcept
      : name{n}, producer{p}, wheels{w} {}

  Vehicle(Vehicle const &v) { *this = v; }

  void operator=(const Vehicle &v) noexcept {
    name = v.name;
    producer = v.producer;
    wheels = v.wheels;
  }

  void setName(std::string n) { name = n; }
  void setProducer(std::string p) { producer = p; }
  void setWheels(int w) { wheels = w; }

  std::string getName() { return name; }
  std::string getProducer() { return producer; }
  int getWheels() { return wheels; }

  virtual void display() noexcept {
    std::cout << "Title: " << manip << name;
    std::cout << "\nProducer: " << manip << producer;
    std::cout << "\nWheels: " << manip << wheels;
  }

  friend std::ostream &operator<<(std::ostream &stream, Vehicle v) noexcept;
};

class Car : public Vehicle {
  int power, capacity;

public:
  Car(std::string n = "unknown", std::string p = "unknown", int w = 0,
      int pw = 0, int cap = 0)
      : Vehicle(n, p, w), power{pw}, capacity{cap} {}
  Car(const Car &c) { *this = c; }

  void operator=(const Car &c) {
    name = c.name;
    producer = c.producer;
    wheels = c.wheels;
    power = c.power;
    capacity = c.capacity;
  }

  void setPower(int p) { power = p; }
  void setCapacity(int c) { capacity = c; }
  int getPower() { return power; }
  int getCapacity() { return capacity; }

  virtual void display() noexcept override {
    std::cout << "Title: " << manip << name;
    std::cout << "\nProducer: " << manip << producer;
    std::cout << "\nWheels: " << manip << wheels;
    std::cout << "\nPower: " << manip << power;
    std::cout << "\nCapacity: " << manip << capacity;
  }

  friend std::ostream &operator<<(std::ostream &stream, Car c) noexcept;
};

int main() {
  // base class
  Vehicle v1("Monocycle", "Oxelo", 1), v2;
  v2 = v1;
  Vehicle v3(v1);

  // derived class
  Car c1("Supra", "Toyota", 4, 1000, 2), c2;
  c2 = c1;
  Car c3(c1);

  // write in file
  std::ofstream fout("Vehicle.txt");
  fout << "Vehicle:\n" << v1 << std::endl << "Car:\n" << c1 << std::endl;

  v1.display();
  std::cout << std::endl << std::endl;
  v2.display();
  std::cout << std::endl << std::endl;
  v3.display();
  std::cout << std::endl << std::endl;

  c1.display();
  std::cout << std::endl << std::endl;
  c2.display();
  std::cout << std::endl << std::endl;
  c3.display();
  std::cout << std::endl << std::endl;

  // base object
  Vehicle *vp = &v1;
  vp->setName("Mountain Bike");
  vp->setProducer("DHL");
  vp->setWheels(2);
  vp->display();
  std::cout << std::endl << std::endl;
  fout << "Vehicle 2:\n" << *vp << std::endl;

  // derived object
  vp = &c1;
  vp->setName("Civic Type R");
  vp->setProducer("Honda");
  vp->display();
  fout << "Car 2:\n" << *vp << std::endl;
}

std::ostream &manip(std::ostream &stream) { return stream << std::setw(30); }
std::ostream &operator<<(std::ostream &stream, Vehicle v) noexcept {
  stream << "Title: " << manip << v.getName();
  stream << "\nProducer: " << manip << v.getProducer();
  stream << "\nWheels: " << manip << v.getWheels();
  return stream;
}

std::ostream &operator<<(std::ostream &stream, Car c) noexcept {
  stream << "Title: " << manip << c.getName();
  stream << "\nProducer: " << manip << c.getProducer();
  stream << "\nWheels: " << manip << c.getWheels();
  stream << "\nPower: " << manip << c.getPower();
  stream << "\nCapacity: " << manip << c.getCapacity();
  return stream;
}
