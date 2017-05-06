/*
 * Problem Link: https://www.codechef.com/problems/LEVENSUB
*/

#include <bits/stdc++.h>
using namespace std;

typedef signed long long ll;
const int MX = 1e6 + 5;
int n, Arr[MX], odd[MX];


int solve(){
	if(odd[n - 1] % 2 == 0) return n;

	int mx = 0;
	for(int i = n - 1; i >= 0; i--){
		if(odd[i] % 2 == 0){
			mx = i + 1; break;
		}
	}
	
	for(int i = 0; i < n; i++){
		if(i){
			if((odd[n - 1] - odd[i - 1]) % 2 == 0){
				mx = max(mx, n - i);
				break;
			}
		}
	}
	
	return mx;
}

int main() {
	int t;
	memset(odd, 0, sizeof(odd));
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%d", &n);
		for(int j = 0; j < n; j++){
			scanf("%d", &Arr[j]);
			odd[j] = (Arr[j] % 2) == 1;
			if(j) odd[j] += odd[j - 1];
		}
		printf("%d\n", solve());
	}
	return 0;
}
