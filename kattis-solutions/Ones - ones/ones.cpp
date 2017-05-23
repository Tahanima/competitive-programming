/*
* Problem link: https://open.kattis.com/problems/ones
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int n){
	int cnt = 1, Ans = 1;
	for(; Ans % n ; cnt++, Ans *= 10, Ans ++, Ans %= n);
	return cnt;
}


int main() {
	int n;
	for( ; scanf("%d", &n) == 1; printf("%d\n", solve(n)));
	return 0;
}
