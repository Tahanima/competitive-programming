/*
* Problem link: https://open.kattis.com/problems/encodedmessage
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 5;
char S[MX];

int main() {
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%s", S);
		int n = strlen(S); n = sqrt(n);
		char Original[n][n];
		
		int id = 0;
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; Original[j][k] = S[id++], k++);
		
		for(int j = n - 1; j >= 0; j--)
			for(int k = 0; k < n ; printf("%c", Original[k][j]), k++);
		
		printf("\n");
	}
	return 0;
}
