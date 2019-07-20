/*
* Problem Link: https://www.codechef.com/problems/FLOW018
*/

#include <bits/stdc++.h> 
using namespace std;

typedef signed long long ll;
const int MX = 22;
ll f[MX];

void solve() {
	f[0] = f[1] = 1;
	for(int i = 2; i < MX; f[i] = f[i - 1] * (ll)i , i++);
}

int main() {
  int t, n; solve();
  scanf("%d", &t);
  for(int i = 0; i < t; scanf("%d", &n), printf("%lld\n", f[n]), i++);
  
  return 0;
}