/*
 * Problem Link: http://www.spoj.com/problems/DISUBSTR/en/
*/

#include <bits/stdc++.h>
using namespace std;

typedef signed long long ll;
const int MX = 1e4 + 5;
struct info{
	int ind, tup[2];
	bool operator<(const info &a) const{
		return tup[0] != a.tup[0] ? tup[0] < a.tup[0] : tup[1] < a.tup[1]; 
	}
}Arr[MX];

int n, step, jump, Rank[18][MX];
char text[MX];

void gen_SA(){
	for(int i = 0; i < n; i++){
		Rank[0][i] = text[i];
		Arr[i].tup[0] = Arr[i].tup[1] = 0;
	}
	
	for(step = 1, jump = 1; jump <= n; step++, jump <<= 1){
		for(int i = 0; i < n; i++){
			Arr[i].ind = i;
			Arr[i].tup[0] = Rank[step - 1][i];
			Arr[i].tup[1] = i + jump < n ? Rank[step - 1][i + jump] : -1;
		}
		
	    sort(Arr, Arr + n);
	    Rank[step][Arr[0].ind] = 0;
	    for(int i = 1; i < n; i++){
		    Rank[step][Arr[i].ind] = (Arr[i].tup[0] == Arr[i - 1].tup[0]) && (Arr[i].tup[1] == Arr[i - 1].tup[1]) ?
		    Rank[step][Arr[i - 1].ind] : i;
	    }
	}
}

void gen_LCP(){
	int id1, id2, len;
	ll common = 0, tot = (ll) n;
	
	for(int i = 1; i < n; i++){
		id1 = Arr[i - 1].ind;
		id2 = Arr[i].ind;
		len = 0;
		
		for(int j = step - 1; j >= 0 ; j--){
			if(Rank[j][id1] == Rank[j][id2] && Rank[j][id2]){
				len += (1 << j);
				id1 += (1 << j);
				id2 += (1 << j);
			}
		}
		common += (ll)len;
	}
	
	printf("%lld\n", (tot * (tot - 1))/2 - common);
}

int main() {
	int t;
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++){
		scanf("%s", text);
		n = strlen(text) + 1;
		text[n - 1] = '$';
		gen_SA();
		gen_LCP();
	}
	return 0;
}
