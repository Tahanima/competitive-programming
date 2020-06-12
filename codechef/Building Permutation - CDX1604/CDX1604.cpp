/*
 * Problem Link: https://www.codechef.com/problems/CDX1604
*/

#include <bits/stdc++.h>
using namespace std;

typedef signed long long ll;
const int MX = 1e6 + 10;
ll Arr[MX];

int main() {
	int t, n;
	ll num, tot = 0;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%d", &n);
		for(int j = 0; j < n; scanf("%lld", &Arr[j]), j++);
		tot = 0;
		sort(Arr, Arr + n);
		for(int j = 0; j < n; j++){
			tot += abs(Arr[j] - (j + 1));
		}
		printf("%lld\n", tot);
	}
	return 0;
}
