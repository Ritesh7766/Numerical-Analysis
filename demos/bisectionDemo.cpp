#include <iostream>
#include "../roots/bisection.h"

using namespace std;

double f(double x) {
	return x*x - 2929292929292929.495249572957289;
}

int main(void) {

	double root = bisection(1.0, 99999999999999999.0, f, 0.000001);

	cout << root << endl;

	return 0;
}
