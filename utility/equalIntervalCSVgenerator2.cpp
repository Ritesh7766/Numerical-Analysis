/*
* Author - Ritesh Saha
* Generating test cases to test various interpolation and extrapolation methods.
*/

#include <iostream>
#include <fstream>
#include <string>

const double INITIAL_VAL = 0.0;

using namespace std;

// Change the fuction defination for other functions
double f(double x) {
	return 3.0*x*x*x - 2.0*x*x + 4.0*x - 9.0; // Some random polynomial.
}

int main(int argc, char *argv[]) {
	// Checking proper usage.
	if (argc != 4) {
		cout << "Usage: .\\csvGenerator %length% %number of csv files% %interval%" << endl;
		return 1;
	}

	double h = atof(argv[3]);
	int n = atoi(argv[2]);
	int len = atoi(argv[1]);
	string file = "./intervals_testCases2/";
	string def = "testCase";
;

	try {
		for (int j = 0; j < n; j++) {
			ofstream csv;
			csv.open(file + def + to_string(j) + ".csv");

			csv << "x" << "," << "f(x)" << endl;

			for (int i = 0; i < len; i++) {
				double x = INITIAL_VAL + h * i;
				double y = f(x);
				csv << x << "," << y << endl;
			}

			csv.close();
		}
	}
	catch (ofstream::failure e) {
		cout << "Exception opening/reading/closing file\n" << endl;
	}

	return 0;
}