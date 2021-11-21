/*
* Author - Ritesh Saha
* Newton Rhapson method.
*/

#include <cmath>

double newtonRhapson(double x0, double (*f)(double), double (*df)(double), double epsilon) {
	double prevroot = 0.0;
	do {
		prevroot = x0;
		x0 = x0 - (f(x0) / df(x0));
	}
	while (fabs(prevroot - x0) > epsilon);
	return x0;
}
