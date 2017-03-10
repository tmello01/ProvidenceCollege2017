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

string prep[14] = { "ABOVE", "AT", "BELOW", "BEFORE", "BEHIND", "BY", "FROM", "IN", "OF", "OFF", "OVER", "TO", "TOWARD", "UNDER" };

int main() {
	string Input;
	int amount = 0;
	while (true) {
		getline(cin, Input);
		if (Input == "XYXY") {
			cout << "There are " << amount << " prepositions." << endl;
			getline(cin, Input);
			break;
		} else {
			vector<string> thing = SplitString(Input);
			for (vector<int>::size_type i = 0; i != thing.size(); i++) {
				for (int j = 0; j < 14; j++) {
					if (thing[i] == prep[j]) {
						amount++;
					}
				}
			}
		}		
	}
}