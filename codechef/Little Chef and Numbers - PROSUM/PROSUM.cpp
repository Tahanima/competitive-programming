/*
 * Problem Link: https://www.codechef.com/problems/PROSUM
*/

#include <bits/stdc++.h>
using namespace std;

typedef signed long long ll;
const int MX = 1e6 + 5;
const int N = 1e5 + 5;
int Arr[N], tree[MX];

void update(int x){
	for(; x < MX ; tree[x]++, x += x & -x);
}

int query(int x){
	int sum = 0;
	for(; x > 0 ; sum += tree[x], x -= x & -x);
	return sum;
}

int main() {
	int t, n;
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++){
		scanf("%d", &n);
		memset(tree, 0, sizeof(tree));
		for(int j = 0; j < n; scanf("%d", &Arr[j]), j++);
		
		ll Ans = 0;
		for(int j = n - 1; j >= 0; j--){
			int num = Arr[j]; 
			if(num <= 1) continue;
			else if (num == 2){
				Ans += (ll)(query(MX - 1) - query(2));
				update(num);
			}else{
				Ans += (ll) query(MX - 1);
				update(num);
			}
		}
		
		printf("%lld\n", Ans);
	}
	return 0;
}
