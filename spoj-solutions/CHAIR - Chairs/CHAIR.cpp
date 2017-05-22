/*
 * Problem Link: http://www.spoj.com/problems/CHAIR/en/
*/

#include <bits/stdc++.h>
using namespace std;

typedef signed long long ll;
const int MX = 1e3 + 1;
const ll mod = 1e9 + 3;
ll dp[MX][MX];

ll solve(int pos, int tot){
	if(tot < 0) return 0;
	if(pos <= 0){
		return tot == 0;
	}
	
	if(dp[pos][tot] != -1) return dp[pos][tot];
	
	ll Ans = 0;
	Ans = (Ans % mod + solve(pos - 1, tot) % mod) % mod; 
	Ans = (Ans % mod + solve(pos - 2, tot - 1) % mod) % mod;
	
	return dp[pos][tot] = Ans % mod;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	if(k > n/2){
		printf("0\n");
		return 0;
	}
	memset(dp, -1, sizeof(dp));
	ll Ans = (solve(n - 1, k) % mod + solve(n - 3, k - 1) % mod) % mod;
	printf("%lld\n", Ans);
	return 0;
}
