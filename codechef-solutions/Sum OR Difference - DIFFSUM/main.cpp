/*
* Problem Link: https://www.codechef.com/problems/DIFFSUM
*/

#include <bits/stdc++.h> 
using namespace std;

int main() {
	int n0, n1;
	scanf("%d %d", &n0, &n1);
	(n0 > n1) ? printf("%d\n", n0 - n1) : printf("%d\n", n0 + n1);
	return 0;
}