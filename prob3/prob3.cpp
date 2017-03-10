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

string letters[26] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
string GetPlace(int n, int m, string ch) {
	int newval = n + m;
	if (newval > 26 ){
		newval = newval - 26;
	}
	cout << newval << endl;
	return letters[newval];
}

int main() {
//	string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string Input;
	vector<string> vect;
	string Message;
	string workingwith;
	while (true) {
		cout << "Please input the n-variable, m-variable, and the message all followed by a space" << endl;
		string Build = "";
		getline(cin, Input);
		vector<string> vect = SplitString(Input);
		int N = atof(vect[0].c_str());
		int M = atof(vect[1].c_str());
		int nn = 0;
		int nnn = N;
		Message = vect[2];
		for (int i = 0; i < Message.length(); i++){
			for (int v = 0; v < 26; v++) {
				if (Message.substr(i, 1) == letters[v]) {
					nn = (nnn + v + 1);
					cout << nn << endl;
					break;
				}
			}
			if (nn > 26) {
				nn = nn - 26;
			}
			cout << nn << endl;
			Build = Build + letters[nn];
			nnn = nnn + M;

		}
		cout << Build << endl;
	}

}