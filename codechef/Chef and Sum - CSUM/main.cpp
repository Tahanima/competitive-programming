/*
* Problem Link: https://www.codechef.com/problems/CSUM
*/

#include <bits/stdc++.h> 
using namespace std;

typedef signed long long ll;
typedef vector<int> vi;
#define pb push_back 
#define all(a) a.begin(), a.end()
const int MX = 1e5 + 5;
map<int, vi> mp;
int A[MX];

int main() {
	int t, n, k;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		scanf("%d %d", &n, &k);
		mp.clear();
		bool ok = false;
		for(int j = 0; j < n; scanf("%d", &A[j]), mp[A[j]].pb(j), j++);
		for(int j = 0; j < n; j++){
			if(mp.count(k - A[j])){
				int ans = 0;
				int lo = lower_bound(all(mp[k - A[j]]), -1) - mp[k - A[j]].begin();
				int hi = upper_bound(all(mp[k - A[j]]), -1) - mp[k - A[j]].begin();
                ans += hi - lo + 1;
                if(2 * A[j] == k) ans--;
                if(ans > 0) {
                	ok = true;
                	break;
                }
			}
		}
		ok ? printf("Yes\n") : printf("No\n");
	}
	return 0;
}