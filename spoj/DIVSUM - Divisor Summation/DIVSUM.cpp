/*
 * Problem Link: http://www.spoj.com/problems/DIVSUM/en/
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5 + 5;
int d[MX];

void sieve(){
	memset(d, 0, sizeof(d));
	for(int i = 1; i < MX; i++){
		for(int j = i + i; j < MX; j += i){
			d[j] += i;
		}
	}
}

int main() {
	sieve();
	int t, n;
	scanf("%d", &t);
	for(int i = 0; i < t; scanf("%d", &n), printf("%d\n", d[n]), i++);
	return 0;
}
