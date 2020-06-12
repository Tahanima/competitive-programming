/*
* Problem Link: https://www.codechef.com/problems/TWOSTR
*/

#include <bits/stdc++.h> 
using namespace std;

int main() {
	int t;
	char A[15], B[15];
	
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		scanf("%s %s", A, B);
		int n = strlen(A);
		bool ok = true;
		for(int j = 0; j < n && ok; ok &= !((isalpha(A[j]) && isalpha(B[j])) && (A[j] != B[j])), j++);
		ok ? printf("Yes\n") : printf("No\n");
	}
	return 0;
}