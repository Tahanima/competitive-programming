/*
 * Problem link: https://www.hackerrank.com/contests/world-codesprint-5/challenges/camelcase 
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 5;
char S[MX];

int solve(){
	int n = strlen(S), cnt = 1;
	for(int i = 0; i < n; cnt += (S[i] >= 'A' && S[i] <= 'Z'), i++);
    return cnt;
}

int main() {
	scanf("%s", S);
	printf("%d\n", solve());
	return 0;
}
