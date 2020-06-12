/*
 * Problem Link: http://www.spoj.com/problems/ADACLEAN/en/
*/

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
const int MX = 1e5 + 5;
const ll mod = 1LL << 32;
const ll p = 31;
int n, k;
ll H[MX], p_pow[MX];
char S[MX];

void process(){
	for(int i = 0; i < n; i++){
		H[i] = p_pow[i] * (S[i] - 'a' + 1);
		if(i) H[i] += H[i - 1];
	}
}

void solve(){
	process();
	map<ll,int> cnt;
	for(int i = 0, j = k - 1; j < n; i++, j++){
		ll h = H[j];
		if(i) h -= H[i - 1];
		h *= p_pow[(n - k) - i];
		cnt[h]++;
	}
    printf("%d\n", cnt.size());
}

int main() {
	int t;
    p_pow[0] = 1;
    for(int i = 1; i < MX; p_pow[i] = p_pow[i - 1] * p, i++);
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
    	memset(H, 0, sizeof(H));
    	memset(S, 0, sizeof(S));
    	scanf("%d %d %s", &n, &k, S);
    	solve();
    }
	return 0;
}
