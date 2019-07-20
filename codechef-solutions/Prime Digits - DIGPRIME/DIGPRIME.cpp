#include <bits/stdc++.h>
using namespace std;

/*
 * Problem Link: https://www.codechef.com/problems/DIGPRIME
*/

typedef signed long long ll;
ll dp[20][2][2];
string str;
int sz;

ll solve(int pos, int top, int prime){
	if(pos == sz) return (prime > 0) ? 1LL : 0LL;
	if(dp[pos][top][prime] != -1) return dp[pos][top][prime];
	int limit = top ? str[pos] - '0' : 9;
	ll Ans = 0;
	for(int i = 0; i <= limit; i++){
		Ans += solve(pos + 1, top & (i == (str[pos] - '0')), prime | ((i == 2) || (i == 3) || (i == 5) || (i == 7)));
	}
	return dp[pos][top][prime] = Ans;
}


int main() { 
	int t;
	ll n;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%lld", &n);
		stringstream ss;
		ss << n;
		str = ss.str();
		sz = str.size();
		memset(dp, -1, sizeof(dp));
		printf("%lld\n", solve(0, 1, 0));
	}
	return 0;
}
