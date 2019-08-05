/*
* Problem Link: https://www.codechef.com/problems/CEQUAL
*/

#include <bits/stdc++.h> 
using namespace std;

map<int, int> mp;

int main() {
	int t, n, num;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		scanf("%d", &n);
		mp.clear();
		bool ok = false;
		for(int j = 0; j < n; scanf("%d", &num), mp[num]++, ok |= (mp[num] >= 2), j++);
		
		ok ? printf("Yes\n") : printf("No\n");
	}
	return 0;
}