/*
 * Problem Link: https://www.codechef.com/problems/SPIT2 
*/

#include <bits/stdc++.h>
using namespace std;

typedef signed long long ll;
int n, m;
ll dp[55][15];

ll solve(int i, int tot){
	if(i == n) return 1;
	if(dp[i][tot] != -1) return dp[i][tot];
	ll Ans = 0;
	if(tot){
		Ans += solve(i + 1, m - 1) + solve(i + 1, tot - 1);
	}else{
		Ans += solve(i + 1, m - 1);
	}
	return dp[i][tot] = Ans;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
    	scanf("%d %d", &m, &n);
    	ll Ans = 0;
    	memset(dp, -1, sizeof(dp));
    	Ans = solve(0, m - 1);
    	printf("%lld\n", Ans);
    }
	return 0;
}
