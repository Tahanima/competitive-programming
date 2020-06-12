/*
* Problem Link: https://www.codechef.com/problems/NOTINCOM
*/

#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e6 + 5;
int A[MX], mark[MX];

int main() {
	int t, n, m, num;
	scanf("%d", &t);

	for(int i = 1; i <= t; i++) {
		memset(mark, 0, sizeof(mark));
		scanf("%d %d", &n, &m);
		for(int j = 0; j < n; scanf("%d", &A[j]), j++);
		for(int j = 0; j < m; scanf("%d", &num), mark[num] = 1, j++);
		int ans = 0;
	    for(int j = 0; j < n; ans += mark[A[j]], j++);
	    printf("%d\n", ans);
	}
	return 0;
}