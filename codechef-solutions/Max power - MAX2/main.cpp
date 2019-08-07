/*
* Problem Link: https://www.codechef.com/problems/MAX2
*/

#include <bits/stdc++.h> 
using namespace std;

int n;
string str;

int solve() {
	int ans = 0;
	for(int i = n - 1; i >= 0 && str[i] == '0'; ans++, i--);
	return ans;
}

int main() {
	cin >> n >> str;
	cout << solve() << endl;
	return 0;
}