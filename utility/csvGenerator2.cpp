/*
* Author - Ritesh Saha
* Generating test cases to test various interpolation and extrapolation methods.
* The function is supplied by the user.
*/
#include <random>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const double UPPER_BOUND = 100.0;
const double LOWER_BOUND = 0.0;

// Change the fuction defination for other functions
double f(double x) {
	return 3.0*x*x*x - 2.0*x*x + 4.0*x - 9.0; // Some random polynomial.
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		cout << "Usage: ./utility/csvGenerator2 %length% %number of csv files%" << endl;
		return 0;
	}

	int n = atoi(argv[2]);
	int len = atoi(argv[1]);
	string file = "./testCases2/";
	string def = "testCase";

	std::uniform_real_distribution<double> unif(LOWER_BOUND, UPPER_BOUND);
   	std::default_random_engine re;

   	try {
   		for (int j = 0; j < n; j++) {
			ofstream csv;
			csv.open(file + def + to_string(j) + ".csv");

			csv << "x" << "," << "f(x)" << endl;

			for (int i = 1; i < len; i++) {
				double x = unif(re);
				double y = f(x);
				csv << x << "," << y << endl;
			}
			double x = unif(re);
			double y = f(x);
			csv << x << "," << y;

			csv.close();
		}
   	}
   	catch (ofstream::failure e) {
		cout << "Exception opening/reading/closing file\n" << endl;
	}

	return 0;
}