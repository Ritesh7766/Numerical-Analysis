#include <stdio.h>
#include "newton_forward.h"

int main(void) {
	double args[7] = {0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
	double h = 0.5;
	double x = 3.6;
	double res = newton_forward(args, 7, h, x);
	printf("%f\n",res);
}