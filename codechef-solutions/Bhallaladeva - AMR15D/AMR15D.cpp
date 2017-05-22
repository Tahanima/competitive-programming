/*
 * Problem Link: https://www.codechef.com/problems/AMR15D
*/

#include <bits/stdc++.h>
using namespace std;

typedef signed long long ll;
const int MX = 1e5 + 5;
ll Arr[MX];

int main() {
	int n, q, k;
	scanf("%d", &n);
	
	for(int i = 0; i<n; scanf("%lld", &Arr[i]), i++);
	sort(Arr, Arr + n);
	for(int i = 1; i<n; Arr[i] += Arr[i-1], i++);
	scanf("%d", &q);
	
	for(int i = 1; i<=q; i++){
		scanf("%d", &k);
		int id = ceil((double) n /((double) k + 1.0)) - 1;
		printf("%lld\n", Arr[id]);
	}
	
	return 0;
}
