/*
 * Problem Link: http://www.spoj.com/problems/COINS/en/
*/

#include <bits/stdc++.h>
using namespace std;

typedef signed long long ll;
map<ll,ll> dp;

ll solve(ll n){
	if(n == 0) return 0;
	if(dp.count(n)) return dp[n];
	ll Ans = 0;
	Ans = max(n, solve(n/2) + solve(n/3) + solve(n/4));
	dp[n] = Ans;
	return Ans;
}

int main() {
	ll n;
	for(; scanf("%lld", &n) == 1 ;){
		dp.clear();
		printf("%lld\n", solve(n));
	}
	return 0;
}s
