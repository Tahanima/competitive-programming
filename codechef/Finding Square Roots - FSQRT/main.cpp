/*
* Problem Link: https://www.codechef.com/problems/FSQRT
*/

#include <bits/stdc++.h> 
using namespace std;

int main() {
  int t, n;
  scanf("%d", &t);
  for(int i = 0; i < t; scanf("%d", &n), printf("%d\n", (int)sqrt(n * 1.0)), i++);
  return 0;
}