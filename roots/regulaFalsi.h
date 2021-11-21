/*
* Author - Ritesh Saha
* The method of false position.
*/

#include <cmath>

double regulaFalsi(double x0, double x1, double (*f)(double), double epsilon) {
	double prevroot = 0.0, root = 0.0;
	do {
		prevroot = root;
		root = (x0 * f(x1) - x1 * f(x0)) / (f(x1) - f(x0));
		if ((*f)(root) < 0.0) x0 = root;
		else x1 = root;
	}
	while (fabs(prevroot - root) > epsilon);
	return root;
}
