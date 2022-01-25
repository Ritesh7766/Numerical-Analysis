/*
* Author - Ritesh Saha
* Newton's forward interpolation.
*/

#include "newton_forward.h"

double newton_forward(double args[], int len, double h, double x) {
	double p = (x - args[0]) / h;
	double temp = p;
	double res = args[1];
	int f = 1;
	for (int i = 2; i < len; i++) {
		res += ((temp/f) * args[i]);
		f = f * i; 
		temp = temp * (p - (i-1));
	}
	return res;
}