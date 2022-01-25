// Author - Ritesh Saha

#include "regula_falsi.h"
#include <math.h>

double regula_falsi(double x0, double x1, double (*f)(double), double epsilon) {
	double prevroot = 0.0, root = 0.0;
	do {
		prevroot = root;
		root = (x0 * f(x1) - x1 * f(x0)) / (f(x1) - f(x0));
		if ((f(root) * f(x0)) < 0.0) x1 = root;
		else x0 = root;
	}
	while (fabs(prevroot - root) > epsilon);
	return root;
}

bool csv_regula_falsi(double *x0, double *x1, double(*f)(double), double epsilon, double *new_approximation, double *prev_approximation) {
	*prev_approximation = *new_approximation;
	*new_approximation = (*x0 * f(*x1) - *x1 * f(*x0)) / (f(*x1) - f(*x0));
	if ((f(*new_approximation) * f(*x0)) < 0.0) *x1 = *new_approximation;
	else *x0 = *new_approximation;
	return fabs(*new_approximation - *prev_approximation) < epsilon;
}