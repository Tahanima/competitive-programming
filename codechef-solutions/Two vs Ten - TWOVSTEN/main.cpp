/*
* Problem Link: https://www.codechef.com/problems/TWOVSTEN
*/

#include <bits/stdc++.h> 
using namespace std;

map<int, int> mp;

int main() {
	int t, n;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		scanf("%d", &n);
		if(n % 10 == 0) printf("0\n");
		else if(n % 5 == 0) printf("1\n");
	    else printf("-1\n");
	}
	return 0;
}