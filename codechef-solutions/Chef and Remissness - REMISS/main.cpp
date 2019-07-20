/*
* Problem Link: https://www.codechef.com/problems/REMISS
*/

#include <bits/stdc++.h> 
using namespace std;

int main() {
  int t, a, b;
  scanf("%d", &t);
  for(int i = 0; i < t; scanf("%d %d", &a, &b), printf("%d %d\n", max(a, b), a + b), i++);
  return 0;
}