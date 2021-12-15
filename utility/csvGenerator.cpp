/*
* Author - Ritesh Saha
* Generating test cases to test various interpolation and extrapolation methods.
*/
#include <random>
#include <iostream>
#include <fstream>
#include <string>

const double UPPER_BOUND = 10000.0;
const double LOWER_BOUND = 0.0;

using namespace std;

int main(int argc, char *argv[]) {
	// Checking proper usage.
	if (argc != 3) {
		cout << "Usage: .\\csvGenerator %length% %number of csv files%" << endl;
		return 1;
	}

	int n = atoi(argv[2]);
	int len = atoi(argv[1]);
	string file = "./testCases/";
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
				double y = unif(re);
				csv << x << "," << y << endl;
			}
			double x = unif(re);
			double y = unif(re);
			csv << x << "," << y;

			csv.close();
		}
	}
	catch (ofstream::failure e) {
		cout << "Exception opening/reading/closing file\n" << endl;
	}

	return 0;
}