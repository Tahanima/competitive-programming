/*
 * Problem Link: https://www.codechef.com/problems/SHISTR 
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 5e3 + 5;
int n, q;
string S;
int sum[MX];

void input(){
	scanf("%d %d", &n, &q);
	cin >> S;
}

void query(){
	int l, r, val;
	memset(sum, 0, sizeof(sum));
	for(int i = 0; i < q; i++){
		scanf("%d %d %d", &l, &r, &val); l--, r--;
		sum[l] += val;
		sum[r + 1] -= val;
	}
	
	for(int i = 1; i < n; i++){
		sum[i] += sum[i - 1];
	}
	
	for(int i = 0; i < n; i++){
		val = (S[i] - 'a') + sum[i];
		val %= 26;
		if(val < 0) val += 26;
		
		printf("%c", (char) (val + 'a'));
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		input();
		query();
	}
	return 0;
}
