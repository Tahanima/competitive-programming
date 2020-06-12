/*
 * Problem Link: https://www.codechef.com/problems/SPIT04
*/

#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 10;
int mark[MX], Arr[MX], Ans[MX];

int main() {
	int n, m, id;
	for(; scanf("%d %d", &n, &m) == 2 ;){
		for(int i = 0; i < n; scanf("%d", &Arr[i]), i++);
		memset(mark, 0, sizeof(mark));
		memset(Ans, 0, sizeof(Ans));
		for(int i = n - 1; i >= 0; i--){
			Ans[i] += (!mark[Arr[i]]);
			Ans[i] += Ans[i + 1];
			mark[Arr[i]]++;
		}
		
		for(int i = 0; i < m; i++){
			scanf("%d", &id); id--;
			printf("%d\n", Ans[id]);
		}
	}
	return 0;
}
