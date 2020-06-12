/*
 * Problem Link: http://www.spoj.com/problems/AMR11E/en/
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6 + 5;
typedef vector<int> vi;
int d[MX];
vi p;

void sieve(){
	memset(d, 0, sizeof(d));
	for(int i = 2; i < MX; i++){
		if(!d[i]){
			for(int j = i; j < MX; j += i){
				d[j]++;
			}
		}
	}
	
	for(int i = 2; i < MX; i++){
		if(d[i] >= 3) p.push_back(i);
	}
}

int main() {
	sieve();
    int t, n;
    scanf("%d", &t);
    for(int i = 0; i < t; scanf("%d", &n), printf("%d\n", p[n - 1]), i++);
	return 0;
}
