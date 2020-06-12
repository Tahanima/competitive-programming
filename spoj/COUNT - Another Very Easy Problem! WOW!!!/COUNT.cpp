/*
 * Problem Link: http://www.spoj.com/problems/COUNT/en/
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 5005;
const int mod = 1988;
int dp[MX][MX];

int solve(int n, int k){
	if(n < 0) return 0;
	if(k == 0) return n == 0;
	if(dp[n][k] != -1) return dp[n][k];
	int Ans = 0;
	for(int i = n/k; i >= 0; i--){
		Ans += solve(n - i*k, k - 1);
		if(Ans >= mod) Ans %= mod;
	}
	return dp[n][k] = Ans;
}


int main() {
	memset(dp, -1, sizeof(dp));
	int n, k;
	
	for(; scanf("%d %d", &n, &k) == 2 && (n + k) != 0 ;){
		printf("%d\n", solve(n - k, k));
	}
	return 0;
}
