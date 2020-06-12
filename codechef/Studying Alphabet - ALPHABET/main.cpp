/*
* Problem Link: https://www.codechef.com/problems/ALPHABET
*/

#include <bits/stdc++.h> 
using namespace std;

int main() {
	int n, s = 0, ss;
	char S[50], SS[50];
	scanf("%s %d", S, &n);

	int sz = strlen(S);
	for(int i = 0; i < sz; s |= (1 << (S[i] - 'a')), i++);


	for(int i = 0; i < n; i++) {
		scanf("%s", SS);
		sz = strlen(SS); ss = 0;
		for(int j = 0; j < sz; ss |= (1 << (SS[j] - 'a')), j++);
		((ss | s) == s) ? printf("Yes\n") : printf("No\n");
	}
	return 0;
}