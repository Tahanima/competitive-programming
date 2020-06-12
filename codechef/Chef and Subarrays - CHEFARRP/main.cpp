/*
* Problem Link: https://www.codechef.com/problems/CHEFARRP
*/

#include <bits/stdc++.h> 
using namespace std;

const int MX = 55;
int A[MX], S[MX], P[MX];

int main() {
  int t, n;
  scanf("%d", &t);

  for(int i = 0; i < t; i++){
  	scanf("%d", &n);
  	for(int j = 0; j < n; j++){
  		scanf("%d", &A[j]);
  		S[j] = P[j] = A[j];
  		if(j){
  			S[j] += S[j - 1];
  			P[j] *= P[j - 1];
  		}
  	}

  	int ans = 0;
  	for(int j = 0; j < n; j++){
  		for(int k = j; k < n; k++){
  			int a = S[k], b = P[k];
  			if(j){
  				a -= S[j - 1];
  				b /= P[j - 1];
  			}
  			if(a == b) ans++;
  		}
  	}
  	printf("%d\n", ans);
  }
  return 0;
}