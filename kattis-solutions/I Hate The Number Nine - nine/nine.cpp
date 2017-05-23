/*
* Problem link: https://open.kattis.com/problems/nine
*/

#include <bits/stdc++.h>
using namespace std;

typedef signed long long ll;
const ll mod = 1e9 + 7;

ll big_mod(ll a, ll b){
	ll x = 1LL, y = a;
	while(b > 0LL){
		if(b & 1LL){
			x = (x * y) % mod;
		}
		y = (y * y) % mod;
		b >>= 1LL;
	}
	return x % mod;
}


int main() {
	int t;
	ll n;

	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%lld", &n);
		ll Ans = (8 * big_mod(9, n - 1)) % mod;
		printf("%lld\n", Ans);
	}
	return 0;
}
