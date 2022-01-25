#include <stdio.h>
#include "secant.h"

double f(double x) {
	return x*x - 7.0;
}

int main(void) {
	double x0 = 1.0, x1 = 3.0;
	double root = secant(x0, x1, f, 0.000001);
	printf("%f\n", root);
	return 0;
}
