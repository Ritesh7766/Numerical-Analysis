// Author - Ritesh Saha

#include "newton_rhapson.h"
#include <math.h>

double newton_rhapson(double x0, double (*f)(double), double (*df)(double), double epsilon) {
	double prevroot = 0.0;
	do {
		prevroot = x0;
		x0 = x0 - (f(x0) / df(x0));
	}
	while (fabs(prevroot - x0) > epsilon);
	return x0;
}

bool csv_newton_rhapson(double *x0, double(*f)(double), double (*df)(double), double epsilon, double *approximation) {
	*approximation = *x0;
	*x0 = *x0 - (f(*x0) / df(*x0));
	return fabs(*approximation - *x0) < epsilon;
}