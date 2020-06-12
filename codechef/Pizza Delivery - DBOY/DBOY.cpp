/*
 * Problem Link: https://www.codechef.com/problems/DBOY
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 505;
const int INF = 1e9 + 5;
int n, num, dis[MX], fuel[MX], dp[MX * 2];

void solve(int mx){
	for(int i = 0; i <= 2 * mx; i++) dp[i] = INF;
	dp[0] = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = fuel[i]; j <= 2 * mx; j++){
			dp[j] = min(dp[j], 1 + dp[j - fuel[i]]);
		}
	}
	
	int Ans = 0;
	for(int i = 0; i < n; i++) Ans += dp[2 * dis[i]];
	printf("%d\n", Ans);
}

int main() {
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%d", &n);
		int mx = 0;
		for(int j = 0; j < n; scanf("%d", &dis[j]), mx = max(mx, dis[j]), j++);
		for(int j = 0; j < n; scanf("%d", &fuel[j]), j++);
		solve(mx);
	}
	return 0;
}
