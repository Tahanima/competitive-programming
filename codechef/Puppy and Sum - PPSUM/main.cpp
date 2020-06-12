/*
* Problem Link: https://www.codechef.com/problems/PPSUM
*/

#include <bits/stdc++.h> 
using namespace std;

int main() {
	int t, n, m;
	
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		scanf("%d %d", &n, &m);
		for(int j = 0; j < n; m = (m * (m + 1))/2, j++);
		printf("%d\n", m);
	}
	return 0;
}