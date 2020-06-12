/*
* Problem Link: https://www.codechef.com/problems/SMPAIR
*/

#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e6 + 5;
int A[MX];

int main() {
  int t, n;
  scanf("%d", &t);

  for(int i = 0; i < t; i++){
  	scanf("%d", &n);
  	for(int j = 0; j < n; scanf("%d", &A[j]), j++);
  	sort(A, A + n);
    printf("%d\n", A[0] + A[1]);
  }

  return 0;
}