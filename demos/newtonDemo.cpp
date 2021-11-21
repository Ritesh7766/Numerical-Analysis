#include <iostream>
#include "../roots/newtonRhapson.h"

using namespace std;

double f(double x) {
	return x*x*x - 4.0;
}

double df(double x) {
	return 3.0*x*x;
}

int main(void) {
	double root = newtonRhapson(1.0, f, df, 0.00001);
	cout << root << endl;
	return 0;
}
