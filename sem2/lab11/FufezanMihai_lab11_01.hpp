#include <iostream>
using namespace std;
class Position {
protected:
  int x, y;

public:
  Position(int = 0, int = 0);
  Position(const Position &);
  ~Position();
  virtual void display();
  virtual void movement(int, int);
};

Position::Position(int abs, int ord) {
  x = abs;
  y = ord;
  cout << "Constructor CB \"Position\", ";
  display();
}

Position::Position(const Position &p) {
  x = p.x;
  y = p.y;
  cout << "Copy constructor CB \"Pozitie\", ";
  display();
}

Position::~Position() {
  cout << "Destructor CB \"Position\", ";
  display();
}

void Position::display() {
  cout << " CB display: coords: x = " << x << ", y = " << y << "\n";
}

void Position::movement(int dx, int dy) {
  cout << "CB: movement" << endl;
  x += dx;
  y += dy;
}

class Point : public Position {
  int visible;
  char color;

public:
  Point(int = 0, int = 0, char = 'A');
  Point(const Point &);
  ~Point();
  void show() { visible = 1; }
  void hide() { visible = 0; }
  void colorize(char c) { color = c; }
  void movement(int, int);
  void display();
};

Point::Point(int abs, int ord, char c) : Position(abs, ord) {
  visible = 0;
  color = c;
  cout << "Constructor CD \"Punct\", ";
  display();
}
Point::Point(const Point &p) : Position(p.x, p.y) {

  visible = p.visible;
  color = p.color;
  cout << "Copy constructor CD \"Point\", ";
  display();
}

Point::~Point() {
  cout << "Destructor CD \"Point\", ";
  display();
}

void Point::movement(int dx, int dy) {
  if (visible) {
    cout << " CD: Display movement CD\n";
    x += dx;
    y += dy;
    display();
  } else {
    x += dx;
    y += dy;
    cout << "Movement through CD displayed from CB\n";
    Position::display();
  }
}
// redefinire metoda de afisare in clasa derivata
void Point::display() {
  cout << "Position: x = " << x << ", y = " << y;
  cout << ", color: " << color;
  cout << ", " << (visible ? "" : "in") << "visible\n";
}

class Circle : public Position {
  int radius;
  int visible;
  int color;

public:
  Circle(int = 0, int = 0, char = 'A');
  Circle(const Circle &);
  ~Circle();
  void show() { visible = 1; }
  void hide() { visible = 0; }
  void colorize(char c) { color = c; }
  void movement(int, int);
  void display();
};

void Circle::display() {
  cout << "Position: x = " << x << ", y = " << y << ", color: " << color
       << ", radius: " << radius << ", " << (visible ? "" : "in")
       << "visible\n";
}

void Circle::movement(int dx, int dy) {
  if (visible) {
    cout << " Derived class: Display derived class movement\n";
    x += dx;
    y += dy;
    display();
  } else {
    x += dx;
    y += dy;
    cout << "Movement through derived class displayed from base class\n";
    Position::display();
  }
}
