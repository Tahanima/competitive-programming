/*
* Problem Link: https://www.codechef.com/problems/PERFCONT
*/

#include <bits/stdc++.h> 
using namespace std;

int main() {
	int t, n, p, num;
	scanf("%d", &t);

	for(int i = 1; i <= t; i++) {
		scanf("%d %d", &n, &p);
		int easy = 0, hard = 0;
		for(int j = 1; j <= n; j++) {
			scanf("%d", &num);
			if (num >= p/2) easy++;
			if (num <= p/10) hard++;
		}
		((easy == 1) && (hard == 2)) ? printf("yes\n") : printf("no\n");
	}
	return 0;
}