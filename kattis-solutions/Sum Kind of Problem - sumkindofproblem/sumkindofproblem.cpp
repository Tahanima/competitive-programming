/*
* Problem link: https://open.kattis.com/problems/sumkindofproblem
*/

#include <bits/stdc++.h>
using namespace std;

typedef signed long long ll;

int main() {
	int t;
	ll n;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%lld %lld", &n, &n);
		printf("%d %lld %lld %lld\n", i, (n * (n + 1))/2, n * (n + 1) - n, n * (n + 1));
	}
	return 0;
}