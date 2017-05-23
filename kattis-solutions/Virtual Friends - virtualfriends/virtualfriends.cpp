/*
* Problem link: https://open.kattis.com/problems/virtualfriends
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6 + 5;
int par[MX], set_sz[MX], r[MX];

void init(){
	for(int i = 0; i < MX; i++){
		par[i] = i;
		set_sz[i] = 1;
		r[i] = 0;
	}
}

int find_par(int p){
	return par[p] == p ? p : find_par(par[p]);
}

void make_set(int a, int b){
	int par_a = find_par(a), par_b = find_par(b);
	if(par_a != par_b){
		if(r[par_a] > r[par_b]){
			par[par_b] = par_a;
			set_sz[par_a] += set_sz[par_b];
		}else{
			par[par_a] = par_b;
			set_sz[par_b] += set_sz[par_a];
            if(r[par_a] == r[par_b]) r[par_b]++;
		}
	}
}

int main() {
	int t, n, id, a, b;
	string name_a, name_b;

	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%d", &n);
		id = 0;
		map<string, int> mp;
		init();

		for(int j = 1; j <= n; j++){
			cin >> name_a >> name_b;
			if(!mp.count(name_a)) mp[name_a] = id++;
			if(!mp.count(name_b)) mp[name_b] = id++;
            a = mp[name_a];
            b = mp[name_b];
            make_set(a, b);
            int sz = set_sz[find_par(a)];
            printf("%d\n", sz);
		}

	}
	return 0;
}
