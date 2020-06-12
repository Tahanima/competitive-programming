/*
* Problem Link: https://www.codechef.com/problems/CHNGOR
*/

#include <bits/stdc++.h> 
using namespace std;

int main() {
	int t, n, num;
	scanf("%d", &t);

	for(int i = 1; i <= t; i++) {
		scanf("%d", &n);
		int ans = 0;
		for (int i = 0; i < n; scanf("%d", &num), ans |= num, i++);
		printf("%d\n", ans);
	}
	return 0;
}