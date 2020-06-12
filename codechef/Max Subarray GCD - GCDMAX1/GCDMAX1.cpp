/*
 * Problem Link: https://www.codechef.com/problems/GCDMAX1
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5 + 5;
const int N = 20;
int n, k, Arr[MX], Table[N][MX];

void preprocess(){
	for(int i = 1; i < N ; i++){
		for(int j = 0; j <= n - (1 << i); j++){
			Table[i][j] = __gcd(Table[i - 1][j], Table[i - 1][(1 << (i - 1)) + j]);
		}
	}
}

void input(){
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; scanf("%d", &Arr[i]), Table[0][i] = Arr[i], i++);
	preprocess();
}

void solve(){
	input();
	int Ans = 0;
	for(int i = 0; i < n ; i++){
		int L = i, tmp = 0, val = 0;
		for(int j = N - 1; j >= 0; j--){
			if(L + (1 << j) - 1 < n){
				if(__gcd(val, Table[j][L]) >= k){
					val = __gcd(val, Table[j][L]);
					L += (1 << j);
			   	    tmp += (1 << j);
				}
			}
		}
		Ans = max(Ans, tmp);
	}
	printf("%d\n", Ans);
}

int main() {
	solve();
	return 0;
}
