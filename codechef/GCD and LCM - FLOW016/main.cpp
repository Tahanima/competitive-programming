/*
* Problem Link: https://www.codechef.com/problems/FLOW016
*/

#include <bits/stdc++.h> 
using namespace std;

typedef signed long long ll;

int main() {
  int t;
  ll a, b;
  scanf("%d", &t);

  for(int i = 0; i < t; i++){
  	scanf("%lld %lld", &a, &b);
    printf("%lld %lld\n", __gcd(a, b), a/__gcd(a, b) * b);
  }

  return 0;
}