/*
 * Problem Link: https://www.codechef.com/problems/DIVMAC
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6 + 10;
const int N = 1e5 + 10;
struct node{
	int sum, mx;
};

int _div[MX], Arr[N];
node tree[6 * N];

void sieve(){
	memset(_div, 0, sizeof(_div));
	_div[1] = 1;
	
	for(int i = 2; i<MX; i++){
		if(!_div[i]){
			for(int j = i; j<MX; j += i){
				if(!_div[j]) _div[j] = i;
			}
		}
	}
}

void build(int x, int st, int en){
	if(st == en){
		tree[x].sum = Arr[st];
		tree[x].mx = _div[Arr[st]];
		return;
	}
	
	int left = 2 * x, right = left + 1, mid = (st + en)/2;
	build(left, st, mid);
	build(right, mid + 1, en);
	tree[x].mx = max(tree[left].mx, tree[right].mx);
	tree[x].sum = tree[left].sum + tree[right].sum;
}

void update(int x, int st, int en, int l, int r){
	if(st > r || en < l) return;
	if((en - st + 1) == tree[x].sum) return;
	if(st == en){
		Arr[st] /= _div[Arr[st]];
		tree[x].sum = Arr[st];
		tree[x].mx = _div[Arr[st]];
		return;
	}
	int left = 2 * x, right = left + 1, mid = (st + en)/2;
	update(left, st, mid, l, r);
	update(right, mid + 1, en, l, r);
	tree[x].mx = max(tree[left].mx, tree[right].mx);
	tree[x].sum = tree[left].sum + tree[right].sum;
}

int query(int x, int st, int en, int l, int r){
	if(st > r || en < l) return 1;
	if(st >= l && en <= r) return tree[x].mx;
	int left = 2 * x, right = left + 1, mid = (st + en)/2;
    int p = query(left, st, mid, l, r);
    int q = query(right, mid + 1, en, l, r);
    return max(p, q);
}

int main() {
	int t, n, m, id, l, r;
	sieve();
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++){
		scanf("%d %d", &n, &m);
		for(int j = 0; j<n; scanf("%d", &Arr[j]), j++);
		build(1, 0, n-1);
		
		bool ok = false;
		for(int j = 1; j<=m; j++){
			scanf("%d %d %d", &id, &l, &r);
			if(id){
				if(ok) printf(" %d", query(1,0,n-1,l-1,r-1));
				else {
					printf("%d", query(1,0,n-1,l-1,r-1));
					ok = true;
				}
			}else{
				update(1,0,n-1,l-1,r-1);
			}
		}
		printf("\n");
	}
	return 0;
}
