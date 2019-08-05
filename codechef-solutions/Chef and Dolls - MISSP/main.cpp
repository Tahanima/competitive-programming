/*
* Problem Link: https://www.codechef.com/problems/MISSP
*/

#include <bits/stdc++.h> 
using namespace std;

int main() {
	int t, n, num, ans;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		ans = 0;
		scanf("%d", &n);
		for(int j = 0; j < n; scanf("%d", &num), ans ^= num, j++); 
		printf("%d\n", ans);
	}
	
	return 0;
}