/*
 * Problem Link: https://www.codechef.com/problems/FIRESC
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 5;
typedef signed long long ll;
const ll mod = 1e9 + 7;
int no_of_sets, set_size[MX], p[MX], r[MX];

void init(int n){
	no_of_sets = n;
	for(int i = 0; i <= n; i++){
		set_size[i] = 1;
		p[i] = i;
		r[i] = 0;
	}
}

int find_set(int i){
	return (p[i] == i) ? i : p[i] = find_set(p[i]);
}

void union_set(int i, int j){
	int x = find_set(i), y = find_set(j);
	if(x != y){
		no_of_sets--;
		if(r[x] > r[y]){
			p[y] = x;
			set_size[x] += set_size[y];
		}else{
			p[x] = y;
			set_size[y] += set_size[x];
			if(r[x] == r[y]) r[y]++;
		}
	}
}

int main() {
	int t, n, m, u, v;
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++){
		scanf("%d %d", &n, &m);
		init(n);
		
		for(int j = 1; j <= m; j++){
			scanf("%d %d", &u, &v);
			union_set(u, v);
		}
		
		map<int, int> mp;
		for(int j = 1; j <= n; j++){
			int par = find_set(j);
			int num = set_size[par];
			mp[par] = num;
		}
		
		ll Ans = 1LL;
		map<int, int>:: iterator it;
		for(it = mp.begin(); it != mp.end(); it++){
			ll num = (ll)(it->second);
			Ans = (Ans * num % mod) % mod;
		}
		
		printf("%d %lld\n", no_of_sets, Ans % mod);
	}
	return 0;
}
