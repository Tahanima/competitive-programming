/*
 * Problem Link: https://www.spoj.com/problems/PARTY/
*/

#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e2 + 5;
const int INF = 1e9;

int n, tot, fee[MX], fun[MX], dp[MX][505];

int solve(int pos, int sum){
	if(sum <= 0 || pos < 0) return 0;
	if(dp[pos][sum] != -1) return dp[pos][sum];
	int ans = solve(pos - 1, sum); 
    if(sum - fee[pos] >= 0) ans = max(ans, fun[pos] + solve(pos - 1, sum - fee[pos]));
	return dp[pos][sum] = ans;
}

int main() {
	for(; scanf("%d %d", &tot, &n) == 2 && (tot + n);){
		for(int i = 0; i < n; scanf("%d %d", &fee[i], &fun[i]), i++);
		memset(dp, -1, sizeof(dp));
		for(int i = 0; i <= tot; i++) solve(n - 1, i);
	    int ans = solve(n - 1, tot), ans0 = -1;
	    for(int i = 0; i <= tot; i++){
	    	if(dp[n - 1][i] == ans){
	    		ans0 = i;
	    		break;
	    	}
	    }
	    printf("%d %d\n", ans0, ans);
	}
}