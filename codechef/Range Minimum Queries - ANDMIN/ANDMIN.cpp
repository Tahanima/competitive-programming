/*
 * Problem Link: https://www.codechef.com/problems/ANDMIN
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 10;
struct node{
	int mn;
	bool bit[32];
};

int Arr[MX];
node tree[6 * MX];

void build(int x, int st, int en){
	if(st == en){
		tree[x].mn = Arr[st];
		for(int i = 0; i<32; i++){
			tree[x].bit[i] = ((1 << i) & Arr[st]);
		}
		return;
	}
	
	int left = 2 * x, right = left + 1, mid = (st + en)/2;
	build(left, st, mid);
	build(right, mid + 1, en);
	tree[x].mn = min(tree[left].mn, tree[right].mn);
	for(int i = 0; i<32; i++){
		tree[x].bit[i] = tree[left].bit[i] | tree[right].bit[i];
	}
}

void update(int x, int st, int en, int l, int r, int val){
	if(st > r || en < l) return;
	bool check = false;
	
	for(int i = 0; i<32; i++){
		if(tree[x].bit[i] && !((1<<i) & val)){
			check = true; break;
		}
	}
	
	if(!check) return;
	
	if(st == en){
		Arr[st] = Arr[st] & val;
		tree[x].mn = Arr[st];
		for(int i = 0; i<32; i++){
			tree[x].bit[i] = ((1 << i) & Arr[st]);
		}
		return;
	}
	
	int left = 2 * x, right = left + 1, mid = (st + en)/2;
	update(left, st, mid, l, r, val);
	update(right, mid + 1, en, l, r, val);
	tree[x].mn = min(tree[left].mn, tree[right].mn);
	for(int i = 0; i<32; i++){
		tree[x].bit[i] = tree[left].bit[i] | tree[right].bit[i];
	}
}

int query(int x, int st, int en, int l, int r){
	if(st > r || en < l) return 1<<30;
	if(st >= l && en <= r) return tree[x].mn;
	int left = 2 * x, right = left + 1, mid = (st + en)/2;
	int p = query(left, st, mid, l, r);
	int q = query(right, mid + 1, en, l, r);
	return min(p,q);
}

int main() {
	int n, q, id, l, r ,x;
	scanf("%d %d", &n, &q);
	
	for(int i = 0; i<n; scanf("%d", &Arr[i]), i++);
	build(1, 0, n-1);
	for(int i = 1; i <= q; i++){
		scanf("%d", &id);
		if(id){
			scanf("%d %d %d", &l, &r, &x);
			update(1, 0, n-1, l-1, r-1, x);
		}else{
			scanf("%d %d", &l, &r);
			printf("%d\n", query(1, 0, n-1, l-1, r-1));
		}
	}
	return 0;
}
