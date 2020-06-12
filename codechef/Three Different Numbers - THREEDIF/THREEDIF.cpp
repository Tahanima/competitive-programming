/*
 * Problem Link: https://www.codechef.com/problems/THREEDIF
 * solution: basic concept of counting
*/


#include <bits/stdc++.h>
using namespace std;

typedef signed long long ll;
ll mod = 1e9 + 7;

ll solve(){
	ll Arr[3];
	scanf("%lld %lld %lld", &Arr[0], &Arr[1], &Arr[2]);
	sort(Arr, Arr + 3);
	Arr[0] %= mod;
	Arr[1] = (Arr[1] - 1) % mod;
	Arr[2] = (Arr[2] - 2) % mod;
	
	ll Ans = Arr[0] * Arr[1]; Ans %= mod;
	Ans = Ans * Arr[2]; Ans %= mod;
	printf("%lld\n", Ans);
}

int main() {
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; solve(), i++);
	return 0;
}
