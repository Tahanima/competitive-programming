/*
* Problem Link: https://www.codechef.com/problems/FLOW004
*/

#include <bits/stdc++.h> 
using namespace std;

int rev(int n) {
	int m = 0;
	for(; n > 0; m *= 10, m += (n % 10), n /= 10);
    return m;
}

int main() {
  int t, n;
  scanf("%d", &t);
  for(int i = 0; i < t; scanf("%d", &n), printf("%d\n", (n % 10) + (rev(n) % 10)), i++);
  return 0;
}