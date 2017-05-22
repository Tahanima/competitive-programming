/*
 * Problem Link: https://www.codechef.com/problems/CDX1605
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6 + 10;
int Arr[MX];

int main() {
	int t, n, m, num;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%d %d", &n, &m);
		memset(Arr, 0, sizeof(Arr));
		for(int j = 0; j < n; j++){
			scanf("%d", &num);
			if(num < MX) Arr[num] = 1;
		}
		
		int cnt = 0, tmp = m;
		for(int j = 1; j < MX; j++){
			if(Arr[j]) continue;
			if(tmp < j) break;
			cnt++;
			tmp -= j;
		}
		
		bool ok = false;
		printf("%d\n", cnt);
		for(int j = 1; j < MX; j++){
			if(Arr[j]) continue;
			if(m < j) break;
			(ok) ? printf(" %d", j) : printf("%d", j);
			ok = true;
			m -= j;
		}
		printf("\n");
	}
	return 0;
}
