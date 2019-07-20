/*
* Problem Link: https://www.codechef.com/problems/CHOPRT
*/

#include <bits/stdc++.h> 
using namespace std;

int main() {
  int t, n0, n1; 
  scanf("%d", &t);
  for(int i = 0; i < t; i++) {
  	scanf("%d %d", &n0, &n1);
  	if(n0 == n1) printf("=\n");
  	else (n0 < n1) ? printf("<\n") : printf(">\n");
  }
  
  return 0;
}