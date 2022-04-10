/*
 * Fufezan Mihai, 2012, lab03, ex 08
 *
 * Calculate ∫ab 1/(1+x2)dx, using the trapezoid method. The height of each
 * considered trapezoid must be smaller than ε=0.0001. The area of a trapezoid
 * is defined by the points (a,0), (b,0), (a,f(a)) and (b,f(b)) is
 * (b-a)*(f(a)+f(b))/2, where f(x)=1/(1+x2). The float values of a and b are
 * read from the keyboard (a must be smaller or equal to b). Use the „divide et
 * impera” method.
 */

#include <cassert>
#include <iostream>

using namespace std;

double f(int x);

int main() {
  int n;
  double a, b;

  cout << "Enter the values of a and b for integral calculation (a <= b): ";
  cin >> a >> b;
  assert(a <= b);

  cout << "Enter the number of subintervals: ";
  cin >> n;

  double step = abs(b - a) / n;

  double ifx = f(a) + f(b);

  for (double i = a + step; i < n; i += step)
    ifx += 2 * f(i);

  ifx = ifx * step / 2;

  cout << "\nThe equation's answer solved using the trapezoidal rule is "
       << ifx;
}

double f(int x) { return 1.0f / 1 + x * x; }
