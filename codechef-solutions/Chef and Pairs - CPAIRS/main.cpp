/*
* Problem Link: https://www.codechef.com/problems/CPAIRS
*/

#include <bits/stdc++.h> 
using namespace std;

typedef signed long long ll;
const int MX = 1e5 + 5;
int A[MX], odd[MX];

int main() {
	int t, n;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		scanf("%d", &n);
		memset(odd, 0, sizeof(odd));
		for(int j = 1; j <= n; scanf("%d", &A[j]), odd[j] = (A[j] & 1),  odd[j] += odd[j - 1], j++);
		ll ans = 0;
	    for(int j = 1; j <= n; j++){
	    	if(!(A[j] & 1)){
	    		ans += odd[n] - odd[j];
	    	}
	    }
	    printf("%lld\n", ans);
	}
	return 0;
}