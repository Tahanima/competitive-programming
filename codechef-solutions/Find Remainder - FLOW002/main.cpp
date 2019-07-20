/*
* Problem Link: https://www.codechef.com/problems/FLOW002
*/

#include <bits/stdc++.h> 
using namespace std;


int main() {
  int t, a, b;
  scanf("%d", &t);
  for(int i = 0; i < t; scanf("%d %d", &a, &b), printf("%d\n", a % b), i++);
  return 0;
}