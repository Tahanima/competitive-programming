/*
* Problem Link: https://www.codechef.com/problems/STRPALIN
*/

#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e3 + 10;
char A[MX], B[MX];

int main() {
	int t, n, m;
	scanf("%d", &t);

	for(int i = 1; i <= t; i++) {
		scanf("%s %s", A, B);
		n = strlen(A);
		m = strlen(B);
		int mask = 0;

		for(int j = 0; j < n; j++) {
			mask |= (1 << (A[j] - 'a'));
		}

		bool ok = false;
		for(int j = 0; j < m; j++) {
			int pos = 1 << (B[j] - 'a');
			if (pos & mask) {
				ok = true;
				break;
			}
		}

		ok ? printf("Yes\n") : printf("No\n");
	}
	return 0;
}