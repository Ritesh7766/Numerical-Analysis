/*
* Author - Ritesh Saha
* Secant method (Optimized regula falsi method)
*/

#include <cmath>

double secant(double x0, double x1, double (*f)(double), double epsilon) {
	double prevroot = 0.0, root = 0.0;
	do {
		prevroot = root;
		root = (x0 * f(x1) - x1 * f(x0)) / (f(x1) - f(x0));
		x1 = root;
	}
	while (fabs(prevroot - root) > epsilon);
	return root;
}