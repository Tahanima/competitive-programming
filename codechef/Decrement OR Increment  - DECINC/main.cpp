/*
* Problem Link: https://www.codechef.com/problems/DECINC
*/

#include <bits/stdc++.h> 
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	n += (n & 3) ? -1: 1;
	printf("%d\n", n);
	return 0;
}