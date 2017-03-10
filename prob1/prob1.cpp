//#include "stdafx.h"
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


int main() {
	string Input;
	double pi = 3.14;
	double size;
	double rad;
	double areaCirc;
	double areaSq;
	double var;
	double thaddeus;
	double savage;
	double ans;
	while (true) {
		cout << "Input side length: ";
		getline(cin, Input);
		size = atof(Input.c_str());
		rad = size / 4;
		areaCirc = ((pow(rad, 2)) * pi)/4;
		var = areaCirc * 12;
		thaddeus = pow((size / 4), 2) * 4;
		savage = thaddeus + var;
		areaSq = pow(size, 2);
		ans = areaSq - savage;
		cout << "Answer: " << ans << endl << endl;
	}
}
