/*
 * Problem Link: https://www.codechef.com/problems/MRS
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 105;
const int INF = 1e9 + 100;

int main() {
	int n, m, num, mx = 0;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		int tmp = INF;
		for(int j = 0; j < m; j++){
			scanf("%d", &num);
			tmp = min(tmp, num);
		}
		mx = max(mx, tmp);
	}
	printf("%d\n", mx);
	return 0;
}
