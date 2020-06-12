/*
 * Problem Link: http://www.spoj.com/problems/ACPC10D/en/
*/

#include <bits/stdc++.h>
using namespace std;

typedef signed long long ll;
const int MX = 1e5 + 5;
const ll INF = 1e18 + 5;
int r;
ll G[MX][4], dp[MX][4];

ll solve(int row, int col){
	if(row == r - 1){
		if(col == 2) return INF;
		else if(col == 1) return G[row][1];
		else return G[row][0] + G[row][1];
	}
	
	if(dp[row][col] != -1) return dp[row][col];
	
	ll Ans = INF;
	if(col == 0){
		Ans = min(Ans, solve(row, 1) + G[row][col]);
		Ans = min(Ans, solve(row + 1, 0) + G[row][col]);
		Ans = min(Ans, solve(row + 1, 1) + G[row][col]);
	}else if(col == 1){
		Ans = min(Ans, solve(row, 2) + G[row][col]);
		Ans = min(Ans, solve(row + 1, 0) + G[row][col]);
		Ans = min(Ans, solve(row + 1, 1) + G[row][col]);
		Ans = min(Ans, solve(row + 1, 2) + G[row][col]);
	}else{
		Ans = min(Ans, solve(row + 1, 1) + G[row][col]);
		Ans = min(Ans, solve(row + 1, 2) + G[row][col]);
	}
	
	return dp[row][col] = Ans;
}

int main() {
	for(int cs = 1; scanf("%d", &r) == 1 && r != 0 ; cs++){
		for(int i = 0; i < r; i++){
			for(int j = 0; j < 3; j++){
				scanf("%lld", &G[i][j]);
			}
		}
		memset(dp, -1, sizeof(dp));
		printf("%d. %lld\n", cs, solve(0, 1));
	}
	return 0;
}
