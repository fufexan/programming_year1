/*
 * Fufezan Mihai, 2012, lab11, ex 07
 *
 * Write a C++ application that defines the abstract base class
 * AbstractQuadrilateral having as protected attributes four instances of the
 * Point class (a pair of x and y coordinates, getter and setter methods) that
 * represent the quadrilateral’s corners. Declare two pure virtual methods for
 * determining the area and the perimeter of the shape. Implement the derived
 * class ActualQuadrilateral that implements the inherited abstract methods and
 * has another method for determining whether the quadrilateral is a square,
 * rectangle, or irregular quadrilateral. Instantiate the derived class and call
 * the defined methods. The area will be determined depending on the
 * quadrilateral type. The irregularr convex quadrilateral are wil be determined
 * considering the following formula that express the area in terms of the sides
 * a, b, c, d, the semiperimeter s, and the diagonals p, q: A=sqrt
 * {(s-a)(s-b)(s-c)(s-d)-1/4(ac+bd+pq)(ac+bd-pq)}. At the irregularr concave
 * quadrilateral will be determined only the perimeter.
 */

class Point {
  int x, y;

public:
  void setX(int a) { x = a; }
  void setY(int a) { y = a; }
  int getX() { return x; }
  int getY() { return y; }
};

class AbstractQuadrilateral {
protected:
  Point a, b, c, d;

public:
  virtual float perim() = 0;
  virtual float area() = 0;
};

class ActualQuadrilateral : public AbstractQuadrilateral {
public:
  virtual float perim() override {
    float p;

    return p;
  }

  virtual float area() override {
    float a;

    return a;
  }
};
