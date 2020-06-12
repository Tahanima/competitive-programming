/*
 * Problem Link: https://www.codechef.com/problems/PRCS16D
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int MX = 1e5 + 5;
# define f first
#define s second
typedef unsigned long long ll;
int n, q, SZ;
ll Ans[MX],  treeA[MX], treeB[MX], A[MX], B[MX], K[MX]; 
pair<pii, int> queries[MX];

bool cmp(const pair<pii, int> &x, const pair<pii, int> &y){
	int _x = x.f.f/SZ;
	int _y = y.f.f/SZ;
	
	if(_x != _y) return _x < _y;
	return x.f.s < y.f.s;
}

void update(int x, ll val, ll tree[]){
	for(; x < MX ; tree[x] += val, x += x & -x) ;
}

ll query(int x, ll tree[]){
	ll sum = 0;
	for(; x > 0 ; sum += tree[x], x -= x & -x) ;
	return sum;
}

void add(int x){
	if(A[x] < MX) update(A[x], 1, treeA);
	if(B[x] < MX) update(B[x], 1, treeB);
}

void remove(int x){
	if(A[x] < MX) update(A[x], -1, treeA);
	if(B[x] < MX) update(B[x], -1, treeB);
}

int main() {
	scanf("%d %d", &n, &q);
	SZ = static_cast<int> (sqrt(n));
	for(int i = 0; i<n; scanf("%lld", &A[i]), i++);
	for(int i = 0; i<n; scanf("%lld", &B[i]), i++);
	memset(treeA, 0, sizeof(treeA));
	memset(treeB, 0, sizeof(treeB));
	
	for(int i = 0; i<q; i++){
		scanf("%d %d %lld", &queries[i].f.f , &queries[i].f.s ,&K[i]);
		queries[i].f.f--;
		queries[i].f.s--;
		queries[i].s = i;
	}
	
	sort(queries, queries + q, cmp);
	int left = 0, right = -1;
	for(int i = 0; i<q; i++){
		int l = queries[i].f.f;
		int r = queries[i].f.s;
		int id = queries[i].s;
		
		while(right < r){
			right++;
		    add(right);
		}
		
		while(right > r){
			remove(right);
			right--;
		}
		
		while(left < l){
			remove(left);
			left++;
		}
		
		while(left > l){
			left--;
			add(left);
		}
		
		ll k = K[id];
		ll res = query(sqrt(k), treeA) * query(sqrt(k), treeB); 
		res *= -1;
		
		for(int j = 1; j<=sqrt(k); j++){
			ll val = j;
			ll _val = k/val;
			res += (query(val, treeA) - query(val - 1, treeA)) * query(_val, treeB);
			res += (query(val, treeB) - query(val - 1, treeB)) * query(_val, treeA);
		}
		
		Ans[id] = res;
	}
	
	for(int i = 0; i<q; i++) printf("%lld\n", Ans[i]);
	
	return 0;
}
