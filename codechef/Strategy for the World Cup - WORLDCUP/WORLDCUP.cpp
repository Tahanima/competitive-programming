/*
 * Problem Link: https://www.codechef.com/problems/WORLDCUP
*/

#include <bits/stdc++.h>
using namespace std;

typedef signed long long ll;
ll mod = 1e9 + 7;
int R, B, L;
ll dp[301][10][1801];

ll solve(int balls, int wicket, int tot){
	if(wicket < 0 || tot < 0) return 0;
	if(balls == 0) return tot == 0;
	if(dp[balls][wicket][tot] != -1) return dp[balls][wicket][tot];
	
	ll Ans = 0;
	ll curr_wicket = solve(balls - 1, wicket, tot - 6) % mod; 
	curr_wicket = (curr_wicket + solve(balls - 1, wicket, tot - 4) % mod) % mod;
	curr_wicket = (curr_wicket + solve(balls - 1, wicket, tot) % mod) % mod;
	ll next_wicket = solve(balls - 1, wicket - 1, tot) % mod; 
    Ans = (curr_wicket + next_wicket) % mod;
    
    return dp[balls][wicket][tot] = Ans;
}

int main() {
	int t;
	scanf("%d", &t);
	memset(dp,-1, sizeof(dp));
	
	for(int i = 1; i <= t; i++){
		scanf("%d %d %d", &R, &B, &L);
		if(B * 6 < R || (R & 1)) printf("0\n");
		else printf("%lld\n", solve(B, L, R));
	}
	return 0;
}
