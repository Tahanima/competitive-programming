/*
* Problem Link: https://www.codechef.com/problems/FLOW006
*/

#include <bits/stdc++.h> 
using namespace std;

int main() {;
  int t, n, sum;
  scanf("%d", &t);
  for(int i = 0; i < t; i++){
  	scanf("%d", &n);
  	sum = 0;
  	for(; n > 0; sum += (n%10), n /= 10);
  	printf("%d\n", sum);
  }
  return 0;
}