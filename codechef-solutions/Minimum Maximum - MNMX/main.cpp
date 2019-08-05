/*
* Problem Link: https://www.codechef.com/problems/MNMX
*/

#include <bits/stdc++.h> 
using namespace std;

typedef signed long long ll;
const ll INF = 1e9 + 7;

int main() {
	int t, n;
	ll num, mn;
	
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		scanf("%d", &n);
		mn = INF;
		for(int j = 0; j < n; scanf("%lld", &num), mn = min(mn, num), j++);
		printf("%lld\n", mn * (n - 1));
	}
	return 0;
}