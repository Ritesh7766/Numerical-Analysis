/*
* Author - Ritesh Saha
* Generates forward difference table for the given data.
*/

// Unicode for greek letter delta - \u0394.

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// De-allocate all the memory.
static void destroy(vector<vector<double>* > vectors) {
	for (int i = 0, n = vectors.size(); i < n; i++)
		delete vectors[i];
	return;
}

// Parse the row.
static pair<double, double> get_coordinates(string line) {
	string y = "", x = "";
	bool flag = false;
	for (char ch : line) {
		if (flag) 
			y += ch;
		else if (ch == ',')
			flag = true;
		else if (!flag)
			x += ch;
	}
	return make_pair(stof(x), stof(y) );
}

static vector<double>* forwardDifference(vector<double> *data) {
	vector<double> *temp = new vector<double>;
	for (int i = 0, n = data->size() - 1; i < n; i++) 
		temp->push_back((*data)[i + 1] - (*data)[i]);
	return temp;
}

int main(int argc, char *argv[]) {
	// Checking proper usage.
	if (argc != 3)
		return 0;

	vector<double> *y_coordinates = new vector<double>;
	vector<double> *x_coordinates = new vector<double>;

	// Open the csv(It is assumed that the x coordinates are in arithmetic progression).
	ifstream infile(argv[1]);
	ofstream outfile;
	outfile.open(argv[2]);
	string buffer;

	// Compute the interval
	getline(infile, buffer); // Skip headers.
	getline(infile, buffer); // Read the second line.
	pair<double, double> temp1 = get_coordinates(buffer);
	getline(infile, buffer); // Read the third line.
	pair<double, double> temp2 = get_coordinates(buffer);
	double h = temp2.first - temp1.first;

	// Write the interval value in outfile.
	outfile << h << endl;

	// Store all the y coordinates in the vector.
	y_coordinates->push_back(temp1.second);
	y_coordinates->push_back(temp2.second);

	x_coordinates->push_back(temp1.first);
	x_coordinates->push_back(temp2.first);

	while (!infile.eof() ) {
		getline(infile, buffer);
		pair<double, double> temp = get_coordinates(buffer);
		y_coordinates->push_back(temp.second);
		x_coordinates->push_back(temp.first);
	}

	infile.close();

	// Write the headers.
	string header = "x,y,";
	for (int i = 1, n = y_coordinates->size(); i < n; i++) {
		header += (string("\u0394^") + to_string(i) + "y" + ",");
	}

	outfile << header << endl;

	// Create the table.
	vector<vector<double>* > vectors;

	vectors.push_back(y_coordinates);

	for (int i = 0, n = y_coordinates->size() - 1; i < n; i++) 
		vectors.push_back(forwardDifference(vectors[i]) );
	
	
	for (int i = 0, n = vectors.size(); i < n; i++) { 
		outfile << (*x_coordinates)[i] << ",";
		for (int j = 0, len = vectors[i]->size(); j < len; j++) {
			outfile << (*vectors[j])[i] << ",";
		}
		if (i == (n - 1))
			break;
		outfile << endl;
	}
	
	// De-allocate
	outfile.close();
	delete x_coordinates;
	delete y_coordinates;
	destroy(vectors);
	
	return 0;
}