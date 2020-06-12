#include <bits/stdc++.h> 
using namespace std;

const int MX = 2e5 + 5;
int p[MX], l[MX], r[MX], c[MX], col[MX];

void init() {
	for(int i = 0; i < MX; p[i] = i, i++);
}

int find_par(int x) {
	return (p[x] == x) ? x : p[x] = find_par(p[x]);
}

void print_col(int n) {
	for(int i = 1; i <= n; printf("%d\n", col[i]), i++);
} 

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q;
	scanf("%d %d", &n, &q);
	init();

	for(int i = 0; i < q; scanf("%d %d %d", &l[i], &r[i], &c[i]), i++);
	for(int i = q - 1; i >= 0; i--){
		for(int j = find_par(l[i]); j <= r[i]; j = find_par(j)) {
			col[j] = c[i];
			p[j] = j + 1;
		}
	}
	print_col(n);
    return 0;
}
