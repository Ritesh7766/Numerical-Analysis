/*
* Author - Ritesh Saha
* Bisection method.
*/

#include <cmath>

static double bisection(double x0, double x1, double (*f)(double), double epsilon) {
	double prevroot = 0.0, root = 0.0;
	do {
		prevroot = root;
		root = x0 + (x1 - x0) / 2.0;
		if (f(root) < 0.0) x0 = root;
		else x1 = root;
	}
	while (fabs(root - prevroot) > epsilon);
	return root;
}
