/*
* Problem Link: https://www.codechef.com/problems/COPS
*/

#include <bits/stdc++.h> 
using namespace std;

const int MX = 105;
int A[MX];

int main() {
	int t, m, x, y, n;
	
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		scanf("%d %d %d", &m, &x, &y);
		memset(A, 0, sizeof(A));
		for(int j = 0; j < m; j++){
			scanf("%d", &n);
			int lo = max(1, n - x * y), hi = min(100, n + x * y);
			A[lo]++; A[hi + 1]--; 
		}

		int ans = 0;
		for(int j = 1; j <= 100; j++){
			A[j] += A[j - 1];
			if(!A[j]) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}