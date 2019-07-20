/*
* Problem Link: https://www.codechef.com/problems/RECIPE
*/

#include <bits/stdc++.h> 
using namespace std;

const int MX = 55;
int A[MX];

int main() {
  int t, n, g; 
  scanf("%d", &t);
  
  for(int i = 0; i < t; i++){
  	g = 0;
  	scanf("%d", &n);
  	for(int j = 0; j < n; scanf("%d", &A[j]), g = __gcd(g, A[j]), j++);
  	for(int j = 0; j < n; j++){
  		if(j) printf(" ");
  		printf("%d", A[j]/g);
  	}
  	printf("\n");
  }
  return 0;
}