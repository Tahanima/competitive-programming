/*
 * Problem link: https://www.hackerrank.com/challenges/maximum-element 
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int MX = 1e5 + 5;
int n, tree[4 * MX];

void update(int node, int st, int en, int l, int r, int val){
	if(st > r || en < l) return;
	if(st >= l && en <= r){
		tree[node] = val;
		return;
	}
	int left = 2 * node, right = left + 1, mid = (st + en)/2;
	update(left, st, mid, l, r, val);
	update(right, mid + 1, en, l, r, val);
	tree[node] = max(tree[left], tree[right]);
}

int query(int node, int st, int en, int l, int r){
	if(st > r || en < l) return 0;
	if(st >= l && en <= r) return tree[node];
	int left = 2 * node, right = left + 1, mid = (st + en)/2;
	return max(query(left, st, mid, l, r),query(right, mid + 1, en, l, r));
}

void solve(){
	int id = 0, type, num;
	memset(tree, 0, sizeof(tree));
	stack<pii> S;
	for(int i = 0; i < n; i++){
		scanf("%d", &type);
		if(type == 1){
			scanf("%d", &num);
			update(1, 0, MX - 1, id, id, num);
			pii p = pii(num, id++);
			S.push(p);
		}else if(type == 2){
			pii p = S.top(); S.pop();
			update(1, 0, MX - 1, p.second, p.second, 0);
		}else{
			int Ans = query(1, 0, MX - 1, 0, MX - 1);
			printf("%d\n", Ans);
		}
	}
}

int main() {
	scanf("%d", &n);
	solve();
	return 0;
}
