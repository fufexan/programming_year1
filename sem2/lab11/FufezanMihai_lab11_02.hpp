class Vehicle {
  int wheels;
  float weight;

public:
  virtual void message() { cout << "Message from class Vehicle\n"; }
  virtual void setWeight(float w) { weight = w; }
  virtual float getWeight() { return weight; }
};
class Automobile : public Vehicle {
  int passengers;

public:
  void message() override { cout << "Message from class Automobile\n"; }
};

class Truck : public Vehicle {
  int passengers;
  float cargo;

public:
  int getPassengers() { return passengers; }
};

class Boat : public Vehicle {
  int passengers;

public:
  int getPassengers() { return passengers; }
  void message() override { cout << "Message from class Boat\n"; }
};
