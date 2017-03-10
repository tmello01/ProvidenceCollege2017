#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

vector<string> SplitString(string input, string filter = " ") {
	vector<string> arr;
	size_t pos = 0, found;
	while ((found = input.find_first_of(filter, pos)) != string::npos) {
		arr.push_back(input.substr(pos, found - pos));
		pos = found + 1;
	}
	arr.push_back(input.substr(pos));
	return arr;
}

vector<string> vec;

int main() {

	string Input;
	while (true) {
		cout << "Input n1, n2, n3, n4, n5 and x all on the same line." << endl;
		getline(cin, Input);
		vector<string> numbers = SplitString(Input);
		int squares = atof(numbers[0].c_str());
		int circles = atof(numbers[1].c_str());
		int triangles = atof(numbers[2].c_str());
		int hexagons = atof(numbers[3].c_str());
		int octagons = atof(numbers[4].c_str());
		int x = atof(numbers[5].c_str());


	}

}