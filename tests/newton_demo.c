#include <stdio.h>
#include "newton_rhapson.h"

double f(double x) {
	return x*x*x - 4.0;
}

double df(double x) {
	return 3.0*x*x;
}

int main(void) {
	double x = 1.0;
	double root = newton_rhapson(x, f, df, 0.00001);
	printf("%f\n", root);
	return 0;
}
