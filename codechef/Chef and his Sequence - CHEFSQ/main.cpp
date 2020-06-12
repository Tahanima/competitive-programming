/*
* Problem Link: https://www.codechef.com/problems/CHEFSQ
*/

#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e5+ 5;
int A[MX], B[MX];

int main() {
  int t, n, m;
  scanf("%d", &t);

  for(int i = 0; i < t; i++){
  	scanf("%d", &n);
  	for(int j = 0; j < n; scanf("%d", &A[j]), j++);
  	scanf("%d", &m);
    for(int j = 0; j < m; scanf("%d", &B[j]), j++);
    
    int j, k;
    for(j = 0, k = 0; j < n && k < m; j++){
    	if(A[j] == B[k]) k++;
    }

    (k == m) ? printf("Yes\n") : printf("No\n");
  }
  return 0;
}