// Author - Ritesh Saha

#include "secant.h"
#include <math.h>

double secant(double x0, double x1, double (*f)(double), double epsilon) {
	double prevroot = 0.0, root = 0.0;
	do {
		prevroot = root;
		root = (x0 * f(x1) - x1 * f(x0)) / (f(x1) - f(x0));
		x1 = root;
		x0 = prevroot;
	}
	while (fabs(prevroot - root) > epsilon);
	return root;
}

bool csv_secant(double *x0, double *x1, double (*f)(double), double epsilon, double *prev_approximation, double *new_approximation) {
	*prev_approximation = *new_approximation;
	*new_approximation = (*x0 * f(*x1) - *x1 * f(*x0)) / (f(*x1) - f(*x0));
	*x1 = *new_approximation;
	*x0 = *prev_approximation;
	return fabs(*prev_approximation - *new_approximation) < epsilon;
}