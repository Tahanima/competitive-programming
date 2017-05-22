/*
 * Problem Link: https://www.codechef.com/problems/DRAWAR
*/

#include <bits/stdc++.h>
using namespace std;

typedef signed long long ll;
int phi[1000001];

ll solve(int n){
	ll Ans = 0;
	memset(phi, 0, sizeof(phi));
	phi[0] = 0; phi[1] = 1;
	
	for(int i = 2; i <= n; i++){
		if(!phi[i]){
			for(int j = i; j <= n; j += i){
				if(!phi[j]) phi[j] = j;
				phi[j] -= phi[j]/i;
			}
		}
	}
	
	for(int i = 1; i <= n; Ans += phi[i], i++);
	return Ans;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%lld\n", solve(n));
	return 0;
}
