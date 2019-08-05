/*
* Problem Link: https://www.codechef.com/problems/TRICOIN
*/

#include <bits/stdc++.h> 
using namespace std;

int main() {
	int t, n;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		scanf("%d", &n);
		int ans = -1 + (int)sqrt(1.0 + 8.0 * n);
		ans /= 2;
		printf("%d\n", ans);
	}
	return 0;
}