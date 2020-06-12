/*
 * Problem Link: https://www.codechef.com/problems/POTATOES
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6 + 5;
int p[MX];
vector<int> prime;

void sieve(){
	memset(p, 0, sizeof(p));
	for(int i = 3; i * i <= MX; i += 2){
		if(!p[i]){
			for(int j = i * i; j < MX; j += i + i){
				p[j] = 1;
			}
		}
	}
	
	prime.push_back(2);
	for(int i = 3; i < MX; i += 2){
		if(!p[i]) prime.push_back(i);
	}
}



int main() {
	sieve();
	int t, a, b, tmp;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%d %d", &a, &b);
		tmp = upper_bound(prime.begin(), prime.end(), a + b) - prime.begin();
		printf("%d\n", prime[tmp] - a - b);
	}
	return 0;
}
