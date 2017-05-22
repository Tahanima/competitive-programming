/*
 * Problem Link: http://www.spoj.com/problems/CUBEFR/en/
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 1e7 + 1;
typedef vector<int> vi;
int d[MX];
vi _d;

void sieve(){
	memset(d, 0, sizeof(d));
	for(int i = 2; i * i * i < MX; i++){
		for(int j = i * i * i; j < MX; j += i * i * i){
			d[j] = 1;
		}
	}
	
	for(int i = 1; i < MX; i++){
		if(!d[i]) _d.push_back(i);
	}
}

int main() {
	sieve();
	int t, n;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%d", &n); 
		bool ok = binary_search(_d.begin(), _d.end(), n);
		ok ? printf("Case %d: %d\n", i, upper_bound(_d.begin(), _d.end(), n) - _d.begin()) : printf("Case %d: Not Cube Free\n", i);
	}
	return 0;
}
