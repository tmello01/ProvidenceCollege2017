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
#define SSTR( x ) static_cast< std::ostringstream  & >(( std::ostringstream() << std::dec << x ) ).str()

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

vector<string> eq;
vector<int> ans;
vector<string> ansS;

bool AlreadyDone(string equation) {
	for (vector<int>::size_type e = 0; e != eq.size(); e++) {
		if (equation == eq[e]) {
			return true;
		}
	}
	return false;
}

int main() {
	string Input;
	while (true) {
		cout << "Please input a value for n: ";
		getline(cin, Input);
		int n = atof(Input.c_str());
		cout << "Please input all your numbers, separated by a space: ";
		getline(cin, Input);
		cout << endl;
		vector<string> numbers = SplitString(Input);
		
		//Additions
		for (int i = 0; i < numbers.size(); i++) {
			for (int j = i + 1; j < numbers.size(); j++) {
				if (!AlreadyDone(numbers[i] + "+" + numbers[j])) {
					//ans.push_back(atof(numbers[i].c_str()) + atof(numbers[j].c_str()));
					int ans = atof(numbers[i].c_str()) + atof(numbers[j].c_str());
					ansS.push_back(SSTR(ans) + ": " + numbers[i] + "+" + numbers[j]);
					//cout << ans.back() << ": " << numbers[i] << " + " << numbers[j] << endl;
					eq.push_back(numbers[i] + "+" + numbers[j]);
					eq.push_back(numbers[j] + "+" + numbers[i]);
				}
			}
		}
		for (int i = 0; i < numbers.size(); i++) {
			for (int j = i + 1; j < numbers.size(); j++) {
				if (!AlreadyDone(numbers[i] + "*" + numbers[j])) {
					int ans = atof(numbers[i].c_str()) * atof(numbers[j].c_str());
					ansS.push_back(SSTR(ans) + ": " + numbers[i] + "*" + numbers[j]);
					eq.push_back(numbers[i] + "*" + numbers[j]);
					eq.push_back(numbers[j] + "*" + numbers[i]);
				}
			}
		}
		for (int i = 0; i < numbers.size(); i++) {
			for (int j = i + 1; j < numbers.size(); j++) {
				if (!AlreadyDone(numbers[i] + "-" + numbers[j])) {
					int ans = atof(numbers[i].c_str()) - atof(numbers[j].c_str());
					ansS.push_back(SSTR(ans) + ": " + numbers[i] + "-" + numbers[j]);
					eq.push_back(numbers[i] + "-" + numbers[j]);
				}
				if (!AlreadyDone(numbers[j] + "-" + numbers[i])) {
					int ans = atof(numbers[j].c_str()) - atof(numbers[i].c_str());
					ansS.push_back(SSTR(ans) + ": " + numbers[j] + "-" + numbers[i]);
					eq.push_back(numbers[j] + "-" + numbers[i]);
				}
			}
		}
		struct {
			bool operator()(string a, string b) {
				string subbeda = a.substr(0,a.find_first_of(":"));
				string subbedb = b.substr(0, b.find_first_of(":"));
				int ae = atof(subbeda.c_str());
				int be = atof(subbedb.c_str());
				return ae < be;
			}
		} newSort;

		sort(ansS.begin(), ansS.end(), newSort);
		for (vector<int>::size_type i = 0; i != ansS.size(); i++) {
			cout << ansS[i] << endl;
		}


		eq.clear();
		ansS.clear();
		cout << endl;
	}
}