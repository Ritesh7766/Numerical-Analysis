#include <stdio.h>
#include "bisection.h"

double f(double x) {
	return x*x - 2929292929292929.495249572957289;
}

int main(void) {
	double x0 = 1.0, x1 = 99999999999999999.0;
	double root = bisection(x0, x1, f, 0.000001);

	printf("%f\n", root);

	return 0;
}
