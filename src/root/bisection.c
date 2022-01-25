// Author - Ritesh Saha

#include "bisection.h"
#include <math.h>

double bisection(double x0, double x1, double (f)(double), double epsilon) {
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

bool csv_bisection(double *x0, double *x1, double (f)(double), double epsilon, double *new_approximation, double *prev_approximation) {
	*prev_approximation = *new_approximation;
	*new_approximation = *x0 + (*x1 - *x0) / 2.0;
	if (f(*new_approximation) < 0.0) *x0 = *new_approximation;
	else *x1 = *new_approximation;
	return fabs(*new_approximation - *prev_approximation) < epsilon;
}