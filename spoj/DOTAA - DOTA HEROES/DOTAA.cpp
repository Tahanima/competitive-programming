/*
 * Problem Link: http://www.spoj.com/problems/DOTAA/en/
*/

#include <bits/stdc++.h>
using namespace std;

int getNum(int n, int h){
	int cnt = 0;
	for( ; n - h > 0 ; cnt++, n -= h);
	return cnt;
}

int main() {
	int t, n, m, h, num, cnt = 0;
	scanf("%d", &t);
	for(int k = 1 ; k <= t ; k++){
		cnt = 0;
		scanf("%d %d %d", &n, &m, &h);
		for(int i = 0; i < n; scanf("%d", &num), cnt += getNum(num, h), i++);
		cnt >= m ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}
