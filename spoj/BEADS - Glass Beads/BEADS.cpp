/*
 * Problem Link: http://www.spoj.com/problems/BEADS/en/
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 1e4 + 5;
char T[MX];

struct info{
	int ind, tup[2];
	
	bool operator<(const info &a) const{
		if(tup[0] != a.tup[0]){
			return tup[0] < a.tup[0];
		}else{
			if(tup[1] == a.tup[1]) return ind < a.ind;
			else return tup[1] < a.tup[1];
		}
	}
	
}Arr[MX];

int n, Rank[18][MX];

void gen_SA(){
	for(int i = 0; i < n; i++){
		Rank[0][i] = T[i];
		Arr[i].tup[0] = Arr[i].tup[1] = 0;
	}
	
	for(int step = 1, jump = 1; jump <= n; step++, jump <<= 1){
		for(int i = 0; i < n; i++){
			Arr[i].ind = i;
			Arr[i].tup[0] = Rank[step - 1][i];
			Arr[i].tup[1] = Rank[step - 1][(i + jump) % n];
		}
		
		sort(Arr, Arr + n);
		Rank[step][Arr[0].ind] = 0;
		for(int i = 1; i < n; i++){
			Rank[step][Arr[i].ind] = (Arr[i].tup[0] == Arr[i - 1].tup[0]) && (Arr[i].tup[1] == Arr[i - 1].tup[1]) ?
			Rank[step][Arr[i - 1].ind] : i;
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++){
		scanf("%s", T);
		n = strlen(T);
		gen_SA();
		printf("%d\n", Arr[0].ind + 1);
	}
	return 0;
}
