/*
* Problem Link: https://www.codechef.com/problems/NITIKA
*/

#include <bits/stdc++.h> 
using namespace std;

string capitalize(string str) {
	int sz = str.size();
	str[0] = toupper(str[0]);
	for(int i = 1; i < sz; str[i] = tolower(str[i]), i++);
	return str;
}

int main() {
	int t;
	string name, str;
	cin >> t;
	getline(cin, name);

	for(int i = 1; i <= t; i++) {
		getline(cin, name);
		stringstream ss;
		ss << name;
		vector<string> names;
		for(; ss >> str; names.push_back(str));
		int sz = names.size();

	    for(int j = 0; j < sz; j++){
	    	if(sz - 1 == j){
	    		cout << capitalize(names[j]) << endl;
	    	}else{
	    		cout << (char) toupper(names[j][0]) << ". ";
	    	}
	    }
	}
	return 0;
}