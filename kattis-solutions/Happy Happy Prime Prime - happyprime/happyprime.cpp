/*
* Problem link: https://open.kattis.com/problems/happyprime
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 5;
int happy[MX], prime[MX], visit[MX];

void gen(){
	memset(happy, 0, sizeof(happy));
	memset(prime, 0, sizeof(prime));
	for(int i = 1; i < MX; i++){
		int num = i, Ans = 0, r;
		for(; num > 0 ; r = num % 10, Ans += r * r, num /= 10);
		happy[i] = Ans;
	}
	
	prime[0] = prime[1] = 1;
	for(int i = 2; i < MX; i++){
		if(!prime[i]){
			for(int j = i + i; j < MX; prime[j] = 1, j += i);
		}
	}
}

bool solve(int n){
	int val = 0;
	memset(visit, 0, sizeof(visit));
	for(; !visit[n] ; visit[n] = 1, val = happy[n], n = val);
	return val == 1;
}

int main() {
	int t, n;
	gen();
	
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%d %d", &n, &n);
		if(prime[n]){
			printf("%d %d NO\n", i, n);
		}else{
			solve(n) ? printf("%d %d YES\n", i, n) : printf("%d %d NO\n", i, n);
		}
	}
	return 0;
}
