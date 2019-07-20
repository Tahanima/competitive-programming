/*
* Problem Link: https://www.codechef.com/problems/FLOW005
*/

#include <bits/stdc++.h> 
using namespace std;

int notes[6] = {1, 2, 5, 10, 50, 100};

int solve(int n) {
	int ans = 0;
	for(int i = 5; i >= 0; i--){
		if(n >= notes[i]) {
			ans += (n / notes[i]);
			n -= (n / notes[i]) * notes[i];
		}
	}
	return ans;
}

int main() {
  int t, n; 
  scanf("%d", &t);
  
  for(int i = 0; i < t; scanf("%d", &n), printf("%d\n", solve(n)), i++);
  return 0;
}