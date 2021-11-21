#include <iostream>
#include "../roots/secant.h"

using namespace std;

double f(double x) {
	return x*x - 7.0;
}

int main(void) {
	double root = secant(1.0, 3.0, f, 0.000001);
	cout << root << endl;
	return 0;
}
