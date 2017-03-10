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


string vowels[5] = { "A", "E", "I", "O", "U" };
bool IsVowel(string str) {
	for (int v = 0; v < 5; v++) {
		if (str == vowels[v]) {
			return true;
		}
	}
	return false;
}

vector<string> cons;
vector<string> inputs;

int main() {
	string FinalInput = "";
	string Input;
	string Building = "";
	int start = 0;
	bool Ended = true;
	while (true) {
		while (true) {
			getline(cin, Input);
			if (Input == "DONE") {
				break;
			}
			else {
				inputs.push_back(Input);
			}
		}
		for (vector<int>::size_type r = 0; r < inputs.size(); r++) {
			for (int i = 0; i < inputs[r].length(); i++) {
				string g = inputs[r].substr(i, 1);
				if (IsVowel(g)) {
					Ended = true;
					if (Building.length() > 0) {
						cons.push_back(Building);
						Building = "";
					}
				}
				else {
					if (!Ended) {
						start = i;
					}
					Ended = false;
					Building = Building + g;
				}
				if (i == inputs[r].length() && Building.length() == i) {
					Ended = true;
					if (Building.length() > 0) {
						cons.push_back(Building);
						Building = "";
					}
				}
			}
		}
		if (!Ended) {
			Ended = true;
			if (Building.length() > 0) {
				cons.push_back(Building);
				Building = "";
			}
		}
		int biggestL = 0; //Length
		for (vector<int>::size_type i = 0; i < cons.size(); i++) {
			if (cons[i].length() > biggestL) {
				biggestL = cons[i].length();
			}
		}
		cout << "The length is " << biggestL << endl;
	}

}