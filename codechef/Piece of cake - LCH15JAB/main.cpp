/*
* Problem Link: https://www.codechef.com/problems/LCH15JAB
*/

#include <bits/stdc++.h> 
using namespace std;

const int MX = 30;
char S[100];
int A[MX];

int main() {
	int t, n;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		scanf("%s", S);
		n = strlen(S);
		memset(A, 0, sizeof(A));
		for(int j = 0; j < n; A[S[j] - 'a']++, j++);
		bool ok = false;
	    for(int j = 0; j < 26 && !ok; ok |= (A[j] == (n - A[j])), j++);
	    ok ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}