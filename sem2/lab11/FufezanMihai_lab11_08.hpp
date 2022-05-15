/*
 * Fufezan Mihai, 2012, lab11, ex 08
 *
 * Consider the Fraction class that has two protected attributes a and b for the
 * nominator and denominator and two corresponding setter and getter methods.
 * Declare a virtual method named simplify() that simplifies a fraction using
 * the greatest common divider determined using the % operator. Define an
 * explicit constructor without parameters that initializes a with 0 and b with
 * 1 and another explicit constructor with two integer parameters. For this
 * constructor is verified if b!=0 before to be called. Overload the addition,
 * subtraction, multiplication and division operators (+, -, *, /) using friend
 * functions and simplify (if necessary) the obtained results. Define a class
 * named Fraction_ext that inherits in a public mode the Fraction class and has
 * a parameterized constructor that calls the constructor from the base class.
 * The derived class redefines the implementation of simplify( ) by determining
 * the greatest common divider using the differences based algorithm. Display an
 * appropriate message in this method. Overload the composed addition,
 * subtraction, multiplication and division operators (+=, -=, *=, /=) using
 * member methods. Use member methods for overloading the post-increment and
 * post-decrement operators that will add 1 to the value of a Fraction_ext
 * instance. Instantiate 2 Fraction objects without parameters. Set the
 * attributes using values read from the keyboard. Perform the operations
 * implemented with friend functions from the base class and initialize another
 * 4 objects with the obtained results. Simplify the results. Instantiate two
 * objects of Fraction_ext type with data from the KB. Perform the implemented
 * operations with the member functions and methods. Assign the operation
 * results to other 4 existing Fraction_ext objects. Use for operations copies
 * of the initial objects. Simplify and display the obtained results. Verify the
 * possibility of using both simplify( ) methods (base and derived class) using
 * instances of the base and derived classes and a pointer of Fraction type.
 */

class Fraction {
protected:
  int a, b;
  static int icount;

public:
  Fraction() {
    a = 0;
    b = 1;
    icount++;
  }
  Fraction(int x, int y) {
    if (y != 0) {
      a = x;
      b = y;
    } else
      cerr << "\nDenominator can't be 0!\n";
    icount++;
  }
  ~Fraction() {
    icount--;
    cout << "\nNumber of objects present: " << icount << ".\n";
  }

  void setA(int x) { a = x; }
  void setB(int x) { b = x; }
  int getA() { return a; }
  int getB() { return b; }
  int getIcount() { return icount; }

  int gcd();
  Fraction simplify();
  template <class T> Fraction op_fraction(Fraction x, Fraction y, T op);
  friend Fraction operator+(Fraction x, Fraction y);
  friend Fraction operator-(Fraction x, Fraction y);
  friend Fraction operator*(Fraction x, Fraction y);
  friend Fraction operator/(Fraction x, Fraction y);
};

class Fraction_ext : public Fraction {
public:
  Fraction_ext() { Fraction(); }
  Fraction_ext(int x, int y) { Fraction(x, y); }
  Fraction_ext(Fraction &x) { *this = x; }

  void operator=(Fraction x) {
    a = x.getA();
    b = x.getB();
  };

  int gcd();
  Fraction simplify();

  Fraction operator+=(Fraction x);
  Fraction operator-=(Fraction x);
  Fraction operator*=(Fraction x);
  Fraction operator/=(Fraction x);

  Fraction operator++(int) {
    a++;
    return *this;
  };
  Fraction operator--(int) {
    a--;
    return *this;
  };
  Fraction operator++() {
    Fraction tmp = *this;
    a++;
    return tmp;
  };
  Fraction operator--() {
    Fraction tmp = *this;
    a--;
    return tmp;
  };
};
