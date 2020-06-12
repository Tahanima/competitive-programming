/*
* Problem Link: https://www.codechef.com/problems/SEGM01
*/

#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e5 + 10;
char A[MX];

int main() {
	int t, n, m;
	scanf("%d", &t);

	for(int i = 1; i <= t; i++) {
		scanf("%s", A);
		n = strlen(A);
		int sz = 0;
		
		for(int j = 0; j < n; ){
			if(A[j] == '1') {
				sz++;
				for( ; j < n && A[j] == '1' ; j++);
			}else{
				j++;
			}
		}

		(sz == 1) ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}