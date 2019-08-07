/*
* Problem Link: https://www.codechef.com/problems/PPATTERN
*/

#include <bits/stdc++.h> 
using namespace std;

const int MX = 105;
int A[MX][MX];

int main() {
	int t, n;
	scanf("%d", &t);

	for(int i = 1; i <= t; i++) {
		scanf("%d", &n);
		int val = 1;
		for(int j = 0; j < n; j++){
			for(int row = 0, col = j; row <= j; row++, col--){
				A[row][col] = val++;
			}
		}

		for(int j = 1; j < n; j++){
			for(int row = j, col = n - 1; row < n; row++, col--){
				A[row][col] = val++;
			}
		}

		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++){
				if(k) printf(" ");
				printf("%d", A[j][k]);
			}
			printf("\n");
		}
	}
	return 0;
}