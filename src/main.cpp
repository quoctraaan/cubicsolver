#include "rootsolver.h"

#include <iostream>

// Solves for all the roots of f(x) = a*x^3 + b*x^2 + c*x + d
//   populates out[] with the solution
//   returns # roots found
int solve_cubic(double d, double c, double b, double a, double out[]) {

  // YOUR CODE HERE

  // HINT: rootsolver.h contains 3 methods
  //          int solve_linear(...) which solves ax+b = 0
  //          int solve_quadratic(...) which solves ax^2+bx+c = 0
  //          int solve_in_range(...) which solves for a root of a 
  //               generic polynomial in the range [left, right] using 
  //               the bisection method
  //
  //       - if the sign of "a" is positive, you should be able to find x 
  //         - sufficiently small (e.g. towards -infinity) such that f(x) < 0
  //         - sufficiently large (e.g. towards +infinity) such that f(x) > 0
  //       - if the sign of "a" is negative, you should be able to find x
  //         - sufficiently small (e.g. towards -infinity) such that f(x) > 0
  //         - sufficiently large (e.g. towards +infinity) such that f(x) < 0
  //       - if "a" is zero, you have a quadratic equation, which you should be able to solve
  //
  //
  //  At this point, you are guaranteed to find at least one root using the bisection method
  //     You can either proceed to find it and use polynomial long division to get a quadratic
  //     equation, or you can use a property of stationary points (remember those?) to find 
  //     bounds for all three roots individually:
  //
  //       - there can only be one root between stationary points since the function is either 
  //           strictly increasing or strictly decreasing between them
  //
  //  e.g. x^3 - 6*x^2 + 11*x - 6
  //       has stationary points at x1=1.4226 and x2=2.5774
  //         f(x1) > 0, f(x2) < 0
  //       We can find x0 < x1 so that f(x0) < 0 (e.g. take x0 = 0)
  //       We can find x3 > x2 so that f(x3) > 0 (e.g. take x3 = 4)
  //       
  //       There is at most one root in the range [x0, x1],
  //          and since f(x0) and f(x1) have opposite signs, we can find it (root0 = 1)
  //       There is at most one root in the range [x1, x2],
  //          and since f(x1) and f(x2) have opposite signs, we can find it (root1 = 2)
  //       There is at most one root in the range [x2, x3],
  //          and since f(x2) and f(x3) have opposite signs, we can find it (root2 = 3)
  //
  //  e.g. x^3 - 3*x^2 + 3*x + 1
  //       has an inflection point at x1=x2=1 (repeated root of 3x^2 - 6x + 3)
  //         f(x1) = f(x2) = 2 > 0
  //       We can find x0 < x1 such that f(x0) < 0 (e.g. take x0 = -1)
  //       We can find x3 > x2 so that f(x3) > 0   (e.g. take x3 = 2)
  //
  //       There is at most one root in the range [x0, x1],
  //          and since f(x0) and f(x1) have opposite signs, we can find it (root0 = -0.25992)
  //       There is NO root in the range [x1, x2], since f(x1) == f(x2) > 0
  //       There is NO root in the range [x2, x3], since both f(x2) and f(x3) have the same sign
}

int main() {

  std::cout << "Cubic root solver" << std::endl;
  double a, b, c, d;
  std::cout << "  Enter the coefficient of x^3: ";
  std::cin >> a;
  std::cout << "  Enter the coefficient of x^2: ";
  std::cin >> b;
  std::cout << "  Enter the coefficient of x^1: ";
  std::cin >> c;
  std::cout << "  Enter the coefficient of x^0: ";
  std::cin >> d;
  std::cout << std::endl;

  double roots[3];  // storage for roots

  int nroots = solve_cubic(d, c, b, a, roots);
  std::cout << std::endl << a << "x^3 + " << b << "x^2 + " 
    << c << "x + " << d << " has " << nroots << " roots:"  ;
  for (int i=0; i<nroots; ++i) {
    std::cout << "  " << roots[i] << std::endl;
  }

  return 0;
}
