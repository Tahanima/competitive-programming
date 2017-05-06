/*
 * Problem Link: https://www.codechef.com/problems/CHKDST
*/

#include <bits/stdc++.h>
using namespace std;

typedef signed long long ll;
const ll mod = 7630367;
const int MX = 1e5 + 10;
ll Arr[MX], sum[MX];

int main() {
	int n, q;
	ll val;
	scanf("%d %d", &n, &q);
	
	for(int i = 0; i < n; scanf("%lld", &Arr[i]), i++);
	sort(Arr, Arr + n);
	
	for(int i = 0; i < n; i++){
		sum[i] = Arr[i];
		if(i) sum[i] = ((sum[i] % mod) + (sum[i-1] % mod)) % mod;
	}
	
	for(int i = 0; i < q; i++){
		scanf("%lld", &val);
		int id = upper_bound(Arr, Arr + n, val) - Arr;
		ll Ans = ((((ll)id % mod) * (val % mod)) - sum[id - 1]) % mod;
		if(id != n){
			Ans = (Ans + (sum[n - 1] - sum[id - 1]) % mod - (((ll)(n - id) % mod) * (val % mod))) % mod;
		}
		if(Ans < 0) Ans += mod;
		printf("%lld\n", Ans);
	}
	return 0;
}
