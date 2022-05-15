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
 * quadrilateral type. The irregular convex quadrilateral wil be determined
 * considering the following formula that express the area in terms of the sides
 * a, b, c, d, the semiperimeter s, and the diagonals p, q: A=sqrt
 * {(s-a)(s-b)(s-c)(s-d)-1/4(ac+bd+pq)(ac+bd-pq)}. At the irregularr concave
 * quadrilateral will be determined only the perimeter.
 */

#include <cmath>

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
    float ab = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
    float ad = sqrt(pow(d.getX() - a.getX(), 2) + pow(d.getY() - a.getY(), 2));
    float bc = sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2));
    float cd = sqrt(pow(d.getX() - c.getX(), 2) + pow(d.getY() - c.getY(), 2));

    return ab + bc + cd + ad;
  }

  virtual float area() override {
    int shape = determine_shape();

    float ab = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
    float ad = sqrt(pow(d.getX() - a.getX(), 2) + pow(d.getY() - a.getY(), 2));
    float bc = sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2));
    float cd = sqrt(pow(d.getX() - c.getX(), 2) + pow(d.getY() - c.getY(), 2));
    float p = sqrt(pow(c.getX() - a.getX(), 2) + pow(c.getY() - a.getY(), 2));
    float q = sqrt(pow(d.getX() - b.getX(), 2) + pow(d.getY() - b.getY(), 2));

    switch (shape) {
    case 1:
      return pow(
          sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2)), 2);
      break;
    case 2:
      return sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2)) *
             sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2));
      break;
    default:
      float s = perim() / 2;
      return sqrt((s - ab) * (s - bc) * (s - cd) * (s - ad) -
                  1 / 4.0 * (ab * cd + bc * ad + p * q) *
                      (ab * cd + bc * ad - p * q));
      break;
    }

    return 0;
  }

  int determine_shape() {
    float ab = sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
    float ad = sqrt(pow(d.getX() - a.getX(), 2) + pow(d.getY() - a.getY(), 2));
    float bc = sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2));
    float cd = sqrt(pow(d.getX() - c.getX(), 2) + pow(d.getY() - c.getY(), 2));

    // 0 - unknown
    // 1 - square
    // 2 - rectangle
    if (ab == cd) {
      if (bc == ad && bc == ab)
        return 1;
      else
        return 2;
    } else
      return 0;
  }

  void setPoints(Point a, Point b, Point c, Point d) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
  }
};
