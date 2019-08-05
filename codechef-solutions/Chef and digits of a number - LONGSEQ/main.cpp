/*
* Problem Link: https://www.codechef.com/problems/LONGSEQ
*/

#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e5 + 5;
char S[MX];

int main() {
  int t, n;
  scanf("%d", &t);

  for(int i = 0; i < t; i++){
  	scanf("%s", S);
  	n = strlen(S);
  	int one = 0, zero = 0;
  	for(int j = 0; j < n; (S[j] == '0') ? zero++: one++, j++);
  	(((one + 1) == n) || ((zero + 1) == n)) ? printf("Yes\n") : printf("No\n");
  }
  return 0;
}