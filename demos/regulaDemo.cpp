#include <iostream>
#include "../roots/regulaFalsi.h"

using namespace std;

double f(double x) {
	return x*x - 5;
}

int main(void) {
	double root = regulaFalsi(1.0, 3.0, f, 0.000001);
	cout << root << endl;
	return 0;
}
