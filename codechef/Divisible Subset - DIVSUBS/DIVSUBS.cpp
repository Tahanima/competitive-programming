/*
 * Problem Link: https://www.codechef.com/problems/DIVSUBS
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 5;
int n, Arr[MX], Sum[MX], mark[MX]; 

void input(){
	memset(mark, 0, sizeof(mark));
	scanf("%d", &n);
	Sum[0] = 0;
	mark[0]++;
	for(int i = 1; i <= n; scanf("%d", &Arr[i]), Sum[i] = (Sum[i - 1] + Arr[i]) % n, mark[Sum[i]]++, i++);
}

void solve(){
	int lo = -1, hi, mod = -1;
	for(int i = 0; i < n; i++){
		if(mark[i] >= 2){
			mod = i; break;
		}
	}
	
	if(mod == 0) lo = 1;
	for(int i = 1; i <= n; i++){
		if(Sum[i] == mod){
			if(lo == -1) lo = i + 1;
			else{
				hi = i; break;
			}
		}
	}
	
	printf("%d\n", hi - lo + 1);
	for(int i = lo; i <= hi; i++){
		(i == lo) ? printf("%d", i) : printf(" %d", i);
	}
	printf("\n");
}


int main() {
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		input();
		solve();
	}
	return 0;
}
