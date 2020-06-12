/*
 * Problem link: https://open.kattis.com/problems/evenup
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, num;
	scanf("%d", &n);
	stack<int> S;
	
	for(int i = 0; i < n; i++){
		scanf("%d", &num);
		if(S.empty()) S.push(num);
		else{
			int mod_a = num & 1, mod_b = S.top() & 1;
			if(mod_a ^ mod_b) S.push(num);
			else S.pop();
		}
	}
	
	printf("%d\n", S.size());
}

int main() {
	solve();
	return 0;
}
